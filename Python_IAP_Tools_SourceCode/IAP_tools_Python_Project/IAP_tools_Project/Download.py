import sys
import time
import os
import serial
import serial.tools.list_ports
import tkinter as tk
from tkinter import filedialog, messagebox, END, NORMAL, DISABLED
from PIL import Image, ImageTk
from pywinusb import hid as py_hid, hid  # 使用Windows原生HID库
import IAP_tools
import threading
from intelhex import IntelHex
from datetime import datetime
import traceback
import crcmod #添加CRC32


class IAPControl:
    #版本信息常量
    SOFTWARE_VERSION = "Version:0.2.0"
    BUILD_TIME = datetime.now().strftime("%Y-%m-%d %H:%M:%S")  # 动态生成构建时间
    BUILD_NUMBER = "2025122501"
    NAME = "Skydiver"

    # 宏定义HID设备参数
    USB_VID = 0x2F81
    USB_PID = 0x7209
    HID_REPORT_ID = 0x00
    PACKET_SIZE = 64  # 协议规定的包大小

    # 协议命令定义
    GET_VERSION = 0x20
    ERASE_APP = 0x21
    SYSTEM_RESET = 0x22
    WRITE_APP = 0x23
    VERIFY_APP = 0x24
    CLEAR_FLAG = 0x25
    WRITE_FLAG = 0x26
    SEG_STARTADDR = 0x27  # 支持hex文件多段下载
    MCU_INFO = 0x28  # 获取MCU分给APP空间大小和起始位置

    # 通讯超时时间定义
    DEFAULT_TIMEOUT_VALUE = 500
    ERASEAPP_TIMEOUT_VALUE = 800  # 擦除应用超时时间

    # 响应命令掩码
    RESPONSE_MASK = 0xC0

    def __init__(self, app):
        self.download_thread = None
        self.app = app
        self.ser = None  # COM串口对象
        self.firmware_path = ""  # 固件路径
        self.hid_device = None  # HID设备对象
        self.hid_handle = None  # HID通信句柄
        self.bin_data = None  # 解析后的Bin数据
        self.segments = []  # 存储分段数据
        self.download_abort = False  # 下载中断标记

        # HID设备状态跟踪
        self.hid_connected = False
        self.hid_monitor_thread = None
        self.hid_monitor_running = False

        # 保存MCU返回的应用空间信息
        self.mcu_app_start_addr = 0  # MCU应用区起始地址
        self.mcu_app_total_size = 0  # MCU应用区总大小

        self.last_response = None  # 保留原缓存变量
        self.response_lock = threading.Lock()  # 新增：线程锁，解决同步问题
        self.current_cmd = None  # 新增：记录当前正在等待的命令

        # 配置日志文本标签样式
        self.app.Message.tag_config("error", foreground="red")  # 错误日志红色
        self.app.Message.tag_config("info", foreground="black")    # 普通信息日志黑色
        self.app.Message.tag_config("attention", foreground="orange")  # 标注信息橙色
        self.app.Message.tag_config("data", foreground="blue")       # 数据信息蓝色
        self.app.Message.tag_config("command", foreground="green")  # 指令日志绿色

        # 初始化4个段的信息，每个段包含长度、地址和校验和
        self.mcu_app_info = [
            {"length": 0, "address": 0, "checksum": 0},  # 段1
            {"length": 0, "address": 0, "checksum": 0},  # 段2
            {"length": 0, "address": 0, "checksum": 0},  # 段3
            {"length": 0, "address": 0, "checksum": 0}   # 段4
        ]

        # 初始化图标
        self.connect_icon = self._load_icon("Connect.ico", (96, 96))
        self.disconnect_icon = self._load_icon("Disconnect.ico", (96, 96))
        self._reinit_connect_state_label()

        # 绑定事件与初始化界面
        self._bind_events()
        self._init_ui_elements()
        # 初始化时输出版本信息到日志
        self.log(
            f"IAP工具初始化完成 | 版本: {self.SOFTWARE_VERSION} | 构建时间: {self.BUILD_TIME} "
            f"| 构建号: {self.BUILD_NUMBER}",
            "INFO")
        self.log(f"This software is developed by: {self.NAME}",
            "INFO")
        # 更新窗口标题，包含版本号
        #self.app.top.title(f"IAP Tools - {self.SOFTWARE_VERSION}")

    def get_icon_path(self, icon_name):
        if getattr(sys, 'frozen', False):
            base_path = sys._MEIPASS
        else:
            base_path = os.path.dirname(os.path.abspath(__file__))

        icon_path = os.path.join(base_path, icon_name)

        if not os.path.exists(icon_path):
            raise FileNotFoundError(f"图标文件 {icon_name} 未找到: {icon_path}")

        return icon_path

    # 图标加载与初始化
    def _load_icon(self, icon_name, target_size=(96, 96)):
        try:
            icon_path = self.get_icon_path(icon_name)
            if not os.path.exists(icon_path):
                self.log(f"警告：图标 {icon_path} 不存在", "WARNING")
                return None
            image = Image.open(icon_path).resize(target_size, Image.Resampling.LANCZOS)
            return ImageTk.PhotoImage(image)
        except Exception as e:
            self.log(f"加载图标失败：{str(e)}", "ERROR")
            return None

    def _reinit_connect_state_label(self):
        # 销毁旧的连接状态标签（如果存在）
        if hasattr(self, 'Connect_State'):
            self.Connect_State.destroy()

        # 使用 tk.Label，父容器为 self.app.Connect_State_Labe
        self.Connect_State_Icon = tk.Label(
            self.app.Connect_State_Labe,  # 直接指定父容器
            background="#d9d9d9",
            image=self.disconnect_icon
        )
        self.Connect_State_Icon.place(relx=0.17, rely=0.17, height=96, width=96, bordermode='ignore')

    # 事件绑定与界面初始化
    def _bind_events(self):
        self.app.Clear_Message.config(command=self.clear_message)
        self.app.Open_Port.config(command=self.open_ser_port)
        self.app.Open_file.config(command=self.open_file)
        self.app.Download.config(command=self.start_download_thread)
        self.app.Port_Select.bind("<<ComboboxSelected>>", self.on_port_select_change)

    def _init_ui_elements(self):
        self.app.Port_Select['values'] = ["HID", "VCOM"]
        self.app.Port_Select.current(0)
        self.baud_rates = ["9600", "19200", "38400", "57600", "115200", "230400", "460800", "921600"]
        self.app.BaudRate_Select['values'] = self.baud_rates
        self.app.BaudRate_Select.current(4)
        self.update_connection_state(False)
        self.set_mode_ui("HID")
        # 顶部中间版本信息标签
        self.version_label = tk.Label(
            self.app.top,  # 父容器
            text=f"软件版本: {self.SOFTWARE_VERSION} | 构建时间: {self.BUILD_TIME}",
            font=("微软雅黑", 9),
            fg="#333333",
            background="#f0f0f0"
        )
        # 顶部中间布局参数：relx=0.5（水平居中），rely=0.01（顶部位置），anchor=tk.CENTER（锚定中心）
        self.version_label.place(relx=0.5, rely=0.01, relwidth=0.6, height=20, anchor=tk.CENTER)

    # 模式切换处理
    def set_mode_ui(self, mode):
        if mode == "HID":
            self.app.COM_Select.config(state=DISABLED)
            self.app.BaudRate_Select.config(state=DISABLED)
            self.app.Open_Port.config(state=DISABLED)
            self.connect_hid_device()
        else:
            self.app.COM_Select.config(state=NORMAL)
            self.app.BaudRate_Select.config(state=NORMAL)
            self.app.Open_Port.config(state=NORMAL)
            self.refresh_com_ports()
            self.update_connection_state(False)
            self.ser = None
            if self.hid_handle:
                self.hid_handle.close()
                self.hid_handle = None

    # HID设备连接与通信
    def connect_hid_device(self):
        self.log(f"查找HID设备 (VID:0x{self.USB_VID:04X}, PID:0x{self.USB_PID:04X})...")
        hid_devices = hid.HidDeviceFilter(vendor_id=self.USB_VID, product_id=self.USB_PID).get_devices()

        if not hid_devices:
            self.log("HID设备未找到，请插入设备", "ERROR")
            self.hid_device = None
            self.hid_handle = None
            self.update_connection_state(False)
            return

        try:
            self.hid_handle = hid_devices[0]
            self.hid_handle.open()
            self.hid_handle.set_raw_data_handler(self._hid_data_receive_callback)
            self.hid_device = True
            self.log("HID设备连接成功，已准备通信", "INFO")
            self.update_connection_state(True)
        except Exception as e:
            self.log(f"HID设备打开失败：{str(e)}", "ERROR")
            self.hid_device = None
            self.hid_handle = None
            self.update_connection_state(False)


    def on_port_select_change(self, event=None):
        """端口选择变化时触发"""
        selected_mode = self.app.Port_Select.get()
        self.log(f"模式切换为：{selected_mode}")

        if self.ser and self.ser.is_open:
            self.ser.close()
        if self.hid_handle:
            self.hid_handle.close()
            self.hid_handle = None
        self.hid_device = None
        self.set_mode_ui(selected_mode)

    def detect_hid_device(self):
        """检测符合VID和PID的HID设备"""
        try:
            # 查找所有HID设备
            all_hid_devices = hid.find_all_hid_devices()
            target_device = None

            # 筛选符合VID和PID的设备
            for device in all_hid_devices:
                if device.vendor_id == self.USB_VID and device.product_id == self.USB_PID:
                    target_device = device
                    break

            if target_device:
                self.hid_device = target_device
                self.hid_connected = True
                self.log(f"发现HID设备: VID=0x{self.USB_VID:04X}, PID=0x{self.USB_PID:04X}", "INFO")
                self.update_connection_state(True)
                return True
            else:
                self.hid_device = None
                self.hid_connected = False
                self.log(f"未找到HID设备: VID=0x{self.USB_VID:04X}, PID=0x{self.USB_PID:04X}", "WARNING")
                self.update_connection_state(False)
                return False

        except Exception as e:
            self.log(f"HID设备检测失败: {str(e)}", "ERROR")
            self.hid_connected = False
            self.update_connection_state(False)
            return False

    def refresh_com_ports(self):
        """刷新COM端口列表，严格按「设备描述 (端口名)」格式显示"""
        # 假设self.app和self.log是已定义的对象，这里保留原有逻辑仅修改输出部分
        ports = serial.tools.list_ports.comports()
        port_list = []

        for port in ports:
            # 处理空描述（部分设备可能无描述，用“未知串行设备”兜底）
            device_desc = port.description.strip() if port.description else "未知串行设备"
            # 严格格式：设备描述 (端口名)（如“USB Serial Port (COM6)”）
            display_text = f"{device_desc} ({port.device})"
            port_list.append(display_text)

        if port_list:
            self.app.COM_Select['values'] = port_list
            self.app.COM_Select.current(0)
            self.log("列出所有扫描到的串口：")
            # 遍历列表，逐个输出每个串口，实现一行一个的效果
            for port_item in port_list:
                self.log(f"  {port_item}")
        else:
            self.app.COM_Select['values'] = ["无可用端口"]
            self.log("未发现可用COM口", "WARNING")

    def open_ser_port(self):
        if self.ser and self.ser.is_open:
            self.ser.close()
            self.ser = None
            self.log("串口已关闭", "INFO")
            self.update_connection_state(False)
        else:
            self._open_port()
            pass

    def _open_port(self):
        # 1. 获取下拉列表选中的完整文本（如“USB 串行设备 (COM6)”）
        selected_text = self.app.COM_Select.get()

        # 2. 检查是否为“无可用端口”
        if "无可用端口" in selected_text:
            messagebox.showerror("错误", "未选择有效COM口")
            return

        # 3. 从完整文本中提取纯端口名（核心修复：提取“(”和“)”之间的内容）
        try:
            # 找到“(”和“)”的位置（格式严格为「描述 (端口名)」）
            start_idx = selected_text.find("(")
            end_idx = selected_text.find(")")

            # 验证格式是否正确
            if start_idx == -1 or end_idx == -1 or end_idx <= start_idx:
                raise ValueError("端口格式错误，无法提取有效端口名")

            # 提取并清理端口名（如从“(COM6)”中提取“COM6”）
            com_port = selected_text[start_idx + 1: end_idx].strip()

            # 额外验证端口名格式（Windows：COMx，Linux：/dev/ttyUSBx）
            if not (com_port.startswith("COM") or com_port.startswith("/dev/")):
                raise ValueError(f"无效端口名：{com_port}（应为COMx或/dev/ttyUSBx格式）")

        except ValueError as e:
            messagebox.showerror("错误", f"提取端口名失败：{str(e)}")
            self.log(f"端口名提取错误：{str(e)}", "ERROR")
            return

        # 4. 后续逻辑不变（获取波特率、打开端口）
        baud_rate = self.app.BaudRate_Select.get()
        try:
            self.ser = serial.Serial(
                port=com_port,  # 这里用的是提取后的纯端口名（如“COM6”）
                baudrate=int(baud_rate),
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                bytesize=serial.EIGHTBITS,
                timeout=2
            )
            if self.ser.is_open:
                self.log(f"COM口 {com_port} 打开（波特率：{baud_rate}）")
                self.update_connection_state(True)
        except Exception as e:
            self.log(f"COM口打开失败：{str(e)}", "ERROR")
            messagebox.showerror("错误", f"COM口打开失败：{str(e)}")
            self.ser = None
            self.update_connection_state(False)

    def _close_port(self):
        if self.ser and self.ser.is_open:
            com_port = self.ser.port
            try:
                self.ser.close()
                self.log(f"COM口 {com_port} 关闭")
            except Exception as e:
                self.log(f"COM口关闭失败：{str(e)}", "ERROR")
            finally:
                self.ser = None
                self.update_connection_state(False)


    def _hid_data_receive_callback(self, data):
        """HID数据接收回调（可能在独立线程执行）"""
        if len(data) > 1:
            # 跳过报告ID，取有效数据
            recv_data = data[1:self.PACKET_SIZE + 1]
            with self.response_lock:  # 加锁确保数据一致性
                self.last_response = recv_data
    # 协议相关函数
    def _calculate_checksum(self, data):
        """
        计算32位校验和（按uint16_t累加）
        逻辑：将数据按uint16_t（2字节）分组累加，结果为uint32_t
        处理奇数长度：最后一个字节视为高8位为0的uint16_t
        """
        checksum = 0  # 32位无符号整数，等效于C++的uint32_t
        length = len(data)
        addr = 0  # 数据索引

        while addr < length:
            # 取当前字节和下一字节组成uint16_t（低地址为低8位，高地址为高8位）
            if addr + 1 < length:
                # 正常2字节组合：data[addr]为低8位，data[addr+1]为高8位
                uint16_val = (data[addr + 1] << 8) | data[addr]
                addr += 2  # 移动2个字节
            else:
                # 奇数长度处理：最后一个字节视为0xFFXX
                uint16_val = 0xFF00 | data[addr]
                addr += 1  # 移动1个字节

            checksum += uint16_val  # 累加至32位校验和

        # 确保结果为32位无符号整数
        return checksum & 0xFFFFFFFF

    def calc_crc_mpeg2(self,data):
        crc32_mpeg2 = crcmod.mkCrcFun(0x104C11DB7, initCrc=0xFFFFFFFF, rev=False, xorOut=0x00000000)
        return crc32_mpeg2(data)

    def _calculate_crc32(self, data):
        crc_value = self.calc_crc_mpeg2(data)
        return crc_value

    def _build_packet(self, cmd, data=None):
        """构建协议数据包"""
        if data is None:
            data = b''

        # 计算包长度（包括命令和校验和）
        packet_length = 1 + 1 + len(data) + 2  # cmd(1) + length(1) + data(n) + checksum(2)
        if packet_length > self.PACKET_SIZE:
            raise ValueError(f"数据包过长，最大{self.PACKET_SIZE}字节")

        # 构建包
        packet = bytearray()
        packet.append(cmd)  # 命令
        packet.append(packet_length)  # 包长度

        if data:
            packet.extend(data)  # 数据

        # 计算校验和（使用16位校验和用于数据包验证）
        checksum = 0
        for b in packet:
            checksum += b
            checksum &= 0xFFFF

        packet.append((checksum >> 8) & 0xFF)  # 校验和高8位
        packet.append(checksum & 0xFF)  # 校验和低8位

        # 填充到64字节
        if len(packet) < self.PACKET_SIZE:
            packet += b'\x00' * (self.PACKET_SIZE - len(packet))

        return packet

    def _send_packet(self, cmd, data=None, timeout=DEFAULT_TIMEOUT_VALUE):
        """发送数据包，返回响应（支持自定义超时）"""
        global current_mode, original_com_timeout
        try:
            # 1. 构建协议数据包
            packet = self._build_packet(cmd, data)
            self.log(f"发送命令: 0x{cmd:02X}, 数据长度: {len(data) if data else 0}", "COMMAND")

            current_mode = self.app.Port_Select.get()
            response = None
            original_com_timeout = None  # 保存COM口原始超时时间

            # 2. HID模式发送与超时等待
            if current_mode == "HID" and self.hid_handle and self.hid_handle.is_opened:
                # 1. 发送前清空旧缓存，并记录当前命令
                with self.response_lock:
                    self.last_response = None  # 关键：发送新命令前清空缓存
                    self.current_cmd = cmd  # 记录当前等待的命令

                # 2. 发送HID数据包
                hid_packet = bytes([self.HID_REPORT_ID]) + packet
                self.hid_handle.send_output_report(hid_packet)

                # 3. 超时等待（只接收与当前命令匹配的响应）
                max_retries = timeout * 10
                retry_count = 0
                while retry_count < max_retries:
                    if self.download_abort:
                        return False, "下载被中断"

                    # 加锁读取缓存，避免回调函数同时修改
                    with self.response_lock:
                        if self.last_response is not None:
                            # 验证响应是否匹配当前命令（响应命令 = 原命令 | 0xC0）
                            response_cmd = self.last_response[0]
                            expected_cmd = cmd | self.RESPONSE_MASK
                            if response_cmd == expected_cmd:
                                response = self.last_response
                                self.last_response = None  # 清空缓存
                                self.current_cmd = None
                                break
                            else:
                                # 收到不匹配的响应（可能是上一条命令的延迟响应），忽略并继续等待
                                self.log(f"收到不匹配的响应：预期0x{expected_cmd:02X}，实际0x{response_cmd:02X}，忽略",
                                         "ERROR")
                                self.last_response = None  # 清空错误响应

                    time.sleep(0.001)
                    retry_count += 1

                # 4. 超时判断
                if retry_count >= max_retries:
                    with self.response_lock:
                        self.last_response = None  # 超时后清空可能的残留数据
                        self.current_cmd = None
                    return False, f"HID模式超时（{timeout}秒内未收到响应）"

            # 3. COM模式发送与超时控制
            elif current_mode == "VCOM" and self.ser and self.ser.is_open:
                # 保存原始超时时间，临时修改为当前指令超时
                original_com_timeout = self.ser.timeout
                self.ser.timeout = timeout  # 设为当前指令的超时时间

                # 发送数据并读取响应
                self.ser.write(packet)
                self.ser.flush()
                response = self.ser.read(self.PACKET_SIZE)  # 按超时时间等待响应

                # 恢复COM口原始超时时间
                self.ser.timeout = original_com_timeout

            # 4. 响应有效性检查
            if not response:
                return False, f"未收到响应（超时{timeout}秒）"

            # 验证响应命令（Command | 0xC0）
            expected_response_cmd = cmd | self.RESPONSE_MASK
            if response[0] != expected_response_cmd:
                return False, f"响应命令不匹配：预期0x{expected_response_cmd:02X}，实际0x{response[0]:02X}"

            self._process_response(response)

            # 验证校验和
            packet_length = response[1]  # 响应包的有效长度
            if packet_length < 4:  # 最小有效长度：cmd(1)+len(1)+checksum(2)
                return False, "响应数据包长度非法"
            valid_data = response[:packet_length]  # 截取有效数据（含校验和）

            # 计算校验和（使用16位校验和验证数据包）
            checksum = 0
            for b in valid_data[:-2]:
                checksum += b
                checksum &= 0xFFFF

            received_crc = (valid_data[-2] << 8) | valid_data[-1]  # 接收的校验和
            if checksum != received_crc:
                return False, f"校验和不匹配：计算0x{checksum:04X}，接收0x{received_crc:04X}"

            return True, response

        except Exception as e:
            # 异常恢复：确保COM口超时时间还原
            if current_mode == "VCOM" and original_com_timeout is not None:
                self.ser.timeout = original_com_timeout
            return False, f"发送异常：{str(e)}"

    def _process_response(self, response):
        """处理接收到的响应数据"""
        if len(response) < 4:
            self.log("无效的响应数据", "ERROR")
            return

        cmd = response[0]
        packet_length = response[1]

        # 存储最后一次响应，供同步读取
        self.last_response = response

        # 解析特定命令的响应
        # 处理“获取版本”响应命令的逻辑
        if cmd == self.GET_VERSION | self.RESPONSE_MASK:
            # 1. 检查response的长度是否至少有3个字节（避免索引越界）
            if len(response) < 3:
                raise Exception("响应数据长度不足，无法获取第三个字节")

            # 2. 获取第三个字节（索引2），并转换为字符
            third_byte = response[2]
            third_char = chr(third_byte)  # 字节转字符（如65→'A'，66→'B'）

            # 3. 判断是否为'A'或'B'，否则抛出异常
            if third_char not in ('A', 'B'):
                raise Exception(f"第三个字节数据错误，期望为'A'或'B'，实际为'{third_char}'（字节值：0x{third_byte:02X}）")

            # 4. 根据字符判断并打印对应内容
            if third_char == 'A':
                module_state = "Application"
                self.current_location = 1
            else:  # third_char == 'B'
                module_state = "Bootloader"
                self.current_location = 0

            # 同时写入日志，便于后续查看
            self.log(f"MCU当前处在: {module_state}", "INFO")

            version_str = ''.join([chr(b) for b in response[2:packet_length - 2] if b != 0])
            self.log(f"当前MCU固件版本号: {version_str}", "INFO")

        elif cmd == self.MCU_INFO | self.RESPONSE_MASK:
            # 解析MCU信息：起始地址(4字节)和大小(4字节)
            if packet_length >= 10:  # 1+1+8+2=12，至少需要10字节有效数据
                start_addr = (response[2] << 24) | (response[3] << 16) | (response[4] << 8) | response[5]
                size = (response[6] << 24) | (response[7] << 16) | (response[8] << 8) | response[9]

                # 保存MCU应用区信息到实例变量
                self.mcu_app_start_addr = start_addr
                self.mcu_app_total_size = size

                self.log(f"MCU返回应用信息 - 编程起始地址:0x{start_addr:08X}, 可编程大小:0x{size:08X}", "ATTENTION")

    # 固件解析相关函数
    def _parse_intel_hex(self, hex_path, print_bin=True):
        """使用IntelHex库解析Intel Hex文件（修复解包异常）"""
        try:
            from intelhex import IntelHex
        except ImportError:
            self.log("未找到IntelHex库，请先安装：pip install intelhex", "ERROR")
            return bytearray(), None

        self.segments = []
        ih = IntelHex()

        try:
            ih.loadhex(hex_path)
        except Exception as e:
            self.log(f"Hex文件加载失败：{str(e)}", "ERROR")
            return bytearray(), None

        # 获取所有非空段
        segments = ih.segments()

        # 处理段信息
        processed_segments = []
        for seg in segments:
            # 兼容 (start, end) 和 (start, end, data) 两种格式
            if len(seg) == 2:
                start, end = seg  # 新版本可能只返回地址范围
            elif len(seg) == 3:
                start, end, _ = seg  # 旧版本可能返回包含数据的三元组
            else:
                self.log(f"忽略无效段格式：{seg}", "WARNING")
                continue

            # 统一通过地址范围提取数据（兼容所有版本）
            length = end - start
            if length <= 0:
                self.log(f"忽略无效段（长度<=0）：0x{start:08X}~0x{end:08X}", "WARNING")
                continue

            # 提取段数据（使用地址范围确保准确性）
            try:
                # 注意：tobinarray()返回的是array.array类型，需转换为bytes
                data_array = ih.tobinarray(start=start, end=end - 1)
                data = data_array.tobytes()  # 关键：将array转换为bytes
                processed_segments.append((start, end, data))
            except Exception as e:
                self.log(f"提取段数据失败（0x{start:08X}~0x{end:08X}）：{e}", "ERROR")
                continue

        # 限制最多4个段
        if len(processed_segments) > 4:
            self.log(f"警告：Hex文件包含{len(processed_segments)}个段，仅保留前4个", "WARNING")
            processed_segments = processed_segments[:4]
        else:
            self.log(f"当前选择的.hex文件包含：{len(processed_segments)}个段")

        for start, end, data in processed_segments:
            original_length = end - start
            # 计算新长度，确保为偶数
            new_length = original_length if original_length % 2 == 0 else original_length + 1
            # 调整数据长度，不足则补0xFF
            if new_length > original_length:
                data = data + b'\xFF'  # 填充一个字节使长度为偶数
            # 更新结束地址
            new_end_addr = start + new_length
            self.segments.append({
                "address": start,
                "data": data,
                "length": new_length,
                "end_addr": new_end_addr
            })

        # 后续逻辑保持不变（构建bin数据、计算校验和等）
        bin_data = bytearray()
        start_addr = None

        for i, segment in enumerate(self.segments):
            segment["checksum"] = self._calculate_crc32(segment["data"]) #段内校验修改成CRC32
            self.mcu_app_info[i] = {
                "length": segment["length"],
                "address": segment["address"],
                "checksum": segment["checksum"]
            }

            if start_addr is None:
                start_addr = segment["address"]

            offset = segment["address"] - start_addr
            if offset < 0:
                self.log(f"警告：段{i + 1}地址重叠", "WARNING")
                continue

            if offset + segment["length"] > len(bin_data):
                bin_data.extend(b'\xFF' * (offset + segment["length"] - len(bin_data)))

            bin_data[offset:offset + segment["length"]] = segment["data"]

        for i in range(len(self.segments), 4):
            self.mcu_app_info[i] = {"length": 0, "address": 0, "checksum": 0}

        # Debug 打印输出信息
        if print_bin and bin_data:
            self.log("Hex解析生成Bin数据（每行16字节）：", "INFO")
            print("\n===== Hex解析Bin数据 =====")
            for i in range(0, len(bin_data), 16):
                chunk = bin_data[i:i + 16]
                hex_str = ' '.join([f"{b:02X}" for b in chunk])
                print(f"0x{i:08X}: {hex_str}")
            print("=========================\n")

            print("\n===== 非空段数据详情 =====")
            for seg_idx, segment in enumerate(self.segments):
                if segment["length"] > 0:
                    start = segment["address"]
                    end = segment["end_addr"] - 1
                    print(f"\n段 {seg_idx + 1}:")
                    print(f"地址范围: 0x{start:08X} ~ 0x{end:08X}")
                    print(f"长度: 0x{segment['length']:08X} ({segment['length']}字节)")
                    print("数据:")
                    for i in range(0, segment["length"], 16):
                        chunk = segment["data"][i:i + 16]
                        hex_str = ' '.join([f"{b:02X}" for b in chunk])
                        chunk_addr = segment["address"] + i
                        print(f"0x{chunk_addr:08X}: {hex_str}")
            print("=========================\n")

        return bin_data, start_addr

    def _find_version(self, data):
        version_tag = b"Version:"
        tag_pos = data.find(version_tag)
        if tag_pos == -1:
            return None
        version_start = tag_pos + len(version_tag)
        version_chars = []
        for i in range(version_start, len(data)):
            byte = data[i]
            if (0x30 <= byte <= 0x39) or (byte == 0x2E):
                version_chars.append(chr(byte))
            else:
                break
        version_str = ''.join(version_chars).rstrip('.')
        return version_str if any(c.isdigit() for c in version_str) else None

    def open_file(self):
        file_path = filedialog.askopenfilename(
            title="选择固件文件",
            filetypes=[("固件文件", "*.hex"), ("所有文件", "*.*")]   #去掉.bin文件烧录支持，只支持hex文件加载
        )
        if file_path:
            self.firmware_path = file_path
            self.app.Text1.delete(1.0, END)
            self.app.Text1.insert(END, file_path)
            self.log(f"选择固件：{file_path}")
            self._parse_firmware_info()

    def _parse_firmware_info(self):
        default_len = "0x00000000"
        default_crc = "0x00000000"
        default_addr = "0x00000000"
        default_ver = "----"

        if not self.firmware_path or not os.path.exists(self.firmware_path):
            self.log("固件不存在", "ERROR")
            self.app.Length.config(text=default_len)
            self.app.Checksum.config(text=default_crc)
            self.app.Address.config(text=default_addr)
            self.app.AppVersion.config(text=default_ver)
            self.bin_data = None
            return

        start_addr = 0x08001800  # .bin default start address
        version_str = default_ver

        try:
            file_ext = os.path.splitext(self.firmware_path)[1].lower()

            # 重置段信息
            self.mcu_app_info = [
                {"length": 0, "address": 0, "checksum": 0},
                {"length": 0, "address": 0, "checksum": 0},
                {"length": 0, "address": 0, "checksum": 0},
                {"length": 0, "address": 0, "checksum": 0}
            ]

            if file_ext == ".hex":
                self.log("处理Hex文件...", "INFO")
                bin_data, parsed_addr = self._parse_intel_hex(self.firmware_path)
                if bin_data is None:
                    self.app.Length.config(text=default_len)
                    self.app.Checksum.config(text=default_crc)
                    self.app.Address.config(text=default_addr)
                    self.app.AppVersion.config(text=default_ver)
                    self.bin_data = None
                    return
                start_addr = parsed_addr
                self.bin_data = bin_data
                found_ver = self._find_version(bin_data)
                if found_ver:
                    version_str = found_ver

                # 显示段信息
                for i, seg in enumerate(self.mcu_app_info):
                    self.log(
                        f"段{i + 1} - 起始地址:0x{seg['address']:08X}, 数据长度:0x{seg['length']:08X}, 本段CRC32校验和:0x{seg['checksum']:08X}",
                        "DATA")

            else:
                self.log(f"不支持格式：{file_ext}", "ERROR")
                self.app.Length.config(text=default_len)
                self.app.Checksum.config(text=default_crc)
                self.app.Address.config(text=default_addr)
                self.app.AppVersion.config(text=default_ver)
                self.bin_data = None
                return

            self.bin_length = len(self.bin_data)
            length_display = f"0x{self.bin_length:08X}"
            # 使用CRC32计算整个文件的校验值
            self.crc32_val = self._calculate_crc32(self.bin_data)
            crc_display = f"0x{self.crc32_val:08X}"
            addr_display = f"0x{start_addr:08X}"

            # 更新UI显示
            self.app.Length.config(text=length_display) #在UI上显示整个固件.bin数据长度
            self.app.Checksum.config(text=crc_display)  # 在UI上显示CRC32值
            self.app.Address.config(text=addr_display)
            self.app.AppVersion.config(text=version_str if version_str else default_ver)
            self.log(f"固件信息：起始地址:{addr_display} | 固件长度:{length_display} | 固件CRC32:{crc_display} | 固件版本{version_str}",
                     "ATTENTION")

        except Exception as e:
            self.log(f"解析异常：{str(e)}", "ERROR")
            self.app.Length.config(text=default_len)
            self.app.Checksum.config(text=default_crc)
            self.app.Address.config(text=default_addr)
            self.app.AppVersion.config(text=default_ver)
            self.bin_data = None

    # 启动下载线程的方法
    def start_download_thread(self):
        # 先检查线程对象是否存在且非None，再判断是否活跃
        if self.download_thread is not None and self.download_thread.is_alive():
            self.log("下载正在进行中，请等待完成", "WARNING")
            return

        # 启动新线程执行下载（覆盖旧的线程对象）
        self.download_thread = threading.Thread(target=self.download_firmware_process, daemon=True)
        self.download_thread.start()

    def download_firmware_process(self):
        current_mode = self.app.Port_Select.get()
        is_connected = False
        self.download_abort = False

        # 检查连接状态
        if current_mode == "HID":
            is_connected = self.hid_handle and self.hid_handle.is_opened
        else:
            is_connected = self.ser and self.ser.is_open

        self.log("检查连接状态...", "INFO")

        current_mode = self.app.Port_Select.get()
        if current_mode == "HID":
            if self.hid_handle:
                self.hid_handle.close()
                self.hid_handle = None
            self.hid_device = None
            self.set_mode_ui(current_mode)

        if not is_connected:
            # 使用after在主线程显示错误
            self.app.top.after(0, lambda: messagebox.showerror(
                "错误", f"{current_mode}未连接或通信句柄异常"
            ))
            self.log(f"下载失败：{current_mode}通信异常", "ERROR")
            return

        # 检查Bin数据
        if self.bin_data is None or len(self.bin_data) == 0:
            self.app.top.after(0, lambda: messagebox.showerror(
                "错误", "无有效bin数据（请先选择hex并解析固件）"
            ))
            self.log("下载失败：无bin数据", "ERROR")
            return
        # 筛选有效段（排除长度为0的段）
        valid_segments = [seg for seg in self.segments if seg["length"] > 0]
        if not valid_segments:
            self.app.top.after(0, lambda: messagebox.showerror(
                "错误", "无有效固件段数据（解析失败或固件为空）"
            ))
            self.log("下载失败：无有效固件段", "ERROR")
            return

        self.log("开始固件下载流程...", "INFO")
        # 使用after更新进度条
        self.app.top.after(0, lambda: self.app.DownloadTProgressbar.config(value=0, maximum=100))

        try:
            # 1. 获取设备版本
            self.log("获取设备版本...", "INFO")
            success, response = self._send_packet(self.GET_VERSION)
            if not success:
                raise Exception(f"获取版本失败: {response}")

            # 2. 清除复位标志，擦除1K information 区间数据
            self.log("清除Boot标志信息", "INFO")
            success, response = self._send_packet(self.CLEAR_FLAG)
            if not success:
                raise Exception(f"获取MCU信息失败: {response}")

            if self.current_location == 1:  #当前处在Application
                self.log("当前处在Application,复位芯片到Bootloader,请等待...", "INFO")
                success, response = self._send_packet(self.SYSTEM_RESET)
                if not success:
                    raise Exception(f"获取MCU信息失败: {response}")
                if current_mode == "HID":
                    time.sleep(3)
                    if self.hid_handle:
                        self.hid_handle.close()
                        self.hid_handle = None
                    self.hid_device = None
                    self.set_mode_ui(current_mode)
                else:
                    time.sleep(3)
            elif self.current_location == 0: #当前处在Bootloader
                self.log("Boot模式下直接下载", "INFO")
            else:
                raise Exception(f"返回芯片状态异常: {response}")

            # 3. 获取MCU信息
            self.log("获取MCU信息...", "INFO")
            success, response = self._send_packet(self.MCU_INFO)
            if not success:
                raise Exception(f"获取MCU信息失败: {response}")

            # 验证是否成功获取MCU空间信息
            if self.mcu_app_total_size == 0:
                raise Exception("未获取到有效的MCU应用空间大小信息")
            if self.mcu_app_start_addr == 0:
                raise Exception("未获取到有效的MCU应用区起始地址")

            # 检查固件第一段起始地址是否匹配
            firmware_first_segment_addr = self.mcu_app_info[0]["address"]
            if firmware_first_segment_addr != self.mcu_app_start_addr:
                raise Exception(
                    f"固件起始地址与MCU应用区地址不匹配！\n"
                    f"固件第一段地址: 0x{firmware_first_segment_addr:08X}\n"
                    f"MCU应用区起始地址: 0x{self.mcu_app_start_addr:08X}"
                )

            # 4. 检查固件大小
            total_firmware_size = len(self.bin_data)
            if total_firmware_size > self.mcu_app_total_size:
                raise Exception(
                    f"固件总大小超过MCU应用空间，固件:0x{total_firmware_size:08X}({total_firmware_size}字节), "
                    f"可用:0x{self.mcu_app_total_size:08X}({self.mcu_app_total_size}字节)"
                )

            # 5. 擦除应用空间
            self.log("擦除应用空间（预计耗时较长，超时30秒）...", "INFO")
            erase_page = ( total_firmware_size//1024 ) + 1
            if total_firmware_size % 1024 != 0:
                erase_page += 1
            erase_page_byte = erase_page.to_bytes(2, byteorder='big', signed=False)

            # 拼接两个字节序列，得到最终的send_data
            erase_send_data = bytearray()
            erase_send_data.extend(erase_page_byte)  # 再添加总大小的2个字节

            success, response = self._send_packet(self.ERASE_APP, erase_send_data, timeout=self.ERASEAPP_TIMEOUT_VALUE)
            if not success:
                raise Exception(f"擦除应用空间失败: {response}")
            # 更新进度条
            self.app.top.after(0, lambda: self.app.DownloadTProgressbar.config(value=10))

            # 6. 发送段起始地址和信息
            self.log("发送段信息...", "INFO")
            seg_data = bytearray()
            for seg in self.mcu_app_info:
                seg_data.extend([
                    (seg["length"] >> 24) & 0xFF,
                    (seg["length"] >> 16) & 0xFF,
                    (seg["length"] >> 8) & 0xFF,
                    seg["length"] & 0xFF
                ])
                seg_data.extend([
                    (seg["address"] >> 24) & 0xFF,
                    (seg["address"] >> 16) & 0xFF,
                    (seg["address"] >> 8) & 0xFF,
                    seg["address"] & 0xFF
                ])
                seg_data.extend([
                    (seg["checksum"] >> 24) & 0xFF,
                    (seg["checksum"] >> 16) & 0xFF,
                    (seg["checksum"] >> 8) & 0xFF,
                    seg["checksum"] & 0xFF
                ])

            success, response = self._send_packet(self.SEG_STARTADDR, seg_data)
            if not success:
                raise Exception(f"设置段信息失败: {response}")

            # 7. 按有效段分块写入应用程序
            self.log("开始写入应用程序...", "INFO")
            total_write_progress = 70  # 写入阶段总进度占比
            processed_bytes = 0  # 已处理的总有效字节数

            # 遍历每个有效段
            for seg_idx, seg in enumerate(valid_segments, 1):
                seg_addr = seg["address"]
                seg_data = seg["data"]
                seg_length = seg["length"]
                seg_total_packets = (seg_length + self.PACKET_SIZE - 5) // (self.PACKET_SIZE - 5)  # 本段总包数

                self.log(
                    f"开始处理段 {seg_idx}/{len(valid_segments)} - 地址:0x{seg_addr:08X}, 长度:0x{seg_length:08X}, "
                    f"总包数:{seg_total_packets}", "INFO"
                )

                total_valid_bytes = sum(seg["length"] for seg in valid_segments)
                # 计算本段在总写入进度中的占比
                seg_progress_weight = (seg_length / total_valid_bytes) * total_write_progress
                # 计算本段的起始进度
                seg_base_progress = 10 + (processed_bytes / total_valid_bytes) * total_write_progress

                # 分包发送本段数据
                for packet_idx in range(seg_total_packets):
                    if self.download_abort:
                        raise Exception("下载被用户中断")

                    # 计算当前包数据（仅取本段有效数据，无填充0xFF）
                    start_idx = packet_idx * (self.PACKET_SIZE - 5)
                    end_idx = min(start_idx + (self.PACKET_SIZE - 5), seg_length)
                    current_data = seg_data[start_idx:end_idx]  # 直接从段数据中截取，避免填充字节

                    # 发送写应用命令
                    success, response = self._send_packet(self.WRITE_APP, current_data)
                    if not success:
                        raise Exception(f"段{seg_idx}第{packet_idx + 1}包写入失败: {response}")

                    # 更新进度
                    processed_in_seg = end_idx  # 本段已处理字节数
                    processed_bytes += (end_idx - start_idx)  # 累计总处理字节数
                    # 计算当前进度：本段基础进度 + 本段内已完成比例 * 本段权重
                    current_progress = seg_base_progress + (processed_in_seg / seg_length) * seg_progress_weight
                    self.app.top.after(0, lambda p=current_progress: self.app.DownloadTProgressbar.config(value=p))

                    # 日志输出（每5包或最后一包）
                    if (packet_idx + 1) % 5 == 0 or (packet_idx + 1) == seg_total_packets:
                        self.log(
                            f"段{seg_idx}写入进度：{current_progress:.1f}% | 第{packet_idx + 1}/{seg_total_packets}包 | "
                            f"本段已发送: {processed_in_seg}/{seg_length}字节 | 总已发送: {processed_bytes}/{total_valid_bytes}字节",
                            "INFO"
                        )

                self.log(f"段{seg_idx}写入完成", "INFO")

            # 8. 验证应用程序
            self.log("验证应用程序...", "INFO")
            success, response = self._send_packet(self.VERIFY_APP)
            if not success:
                raise Exception(f"应用程序验证失败: {response}")
            self.app.top.after(0, lambda: self.app.DownloadTProgressbar.config(value=85))

            # 9. 写入标志（整个程序CRC32和程序长度）
            self.log("写入应用标志...", "INFO")

            # 按大端模式将32位整数转换为4字节的字节序列
            start_addr_bytes = self.bin_length.to_bytes(4, byteorder='big', signed=False)
            # 处理应用区总大小（32bit → 4字节，大端）
            total_size_bytes = self.crc32_val.to_bytes(4, byteorder='big', signed=False)

            # 拼接两个字节序列，得到最终的send_data
            send_data = bytearray()
            send_data.extend(start_addr_bytes)  # 先添加起始地址的4个字节
            send_data.extend(total_size_bytes)  # 再添加总大小的4个字节

            # 发送写应用命令
            success, response = self._send_packet(self.WRITE_FLAG, send_data)
            if not success:
                raise Exception(f"写入应用标志失败: {response}")

            # 10. 复位MCU（如果勾选）
            if self.app.che76.get() == 1:
                self.log("执行系统复位...", "INFO")
                success, response = self._send_packet(self.SYSTEM_RESET)
                if not success:
                    self.log(f"复位命令发送警告: {response}", "WARNING")
                self.app.top.after(0, lambda: self.app.DownloadTProgressbar.config(value=95))
                time.sleep(0.5)

            # 11. 下载完成
            self.app.top.after(0, lambda: self.app.DownloadTProgressbar.config(value=100))
            self.log("固件下载流程完成！", "INFO")
            self.app.top.after(0, lambda: messagebox.showinfo(
                "完成", f"{current_mode}模式固件下载成功！"
            ))
            pass

        except Exception as e:
            #将异常信息转换为字符串并保存到局部变量
            error_msg = str(e)
            self.log(f"下载异常：{str(e)}", "ERROR")
            # 使用保存的局部变量更新UI，避免直接引用e
            self.app.top.after(0, lambda: self.app.DownloadTProgressbar.config(value=0))
            self.app.top.after(0, lambda msg=error_msg: messagebox.showerror(
                "错误", f"下载失败：{msg}"  # 使用提前保存的msg变量
            ))

    # 日志和状态更新
    def log(self, message, level="INFO"):
        self.app.Message.config(state=NORMAL)
        timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
        log_entry = f"[{timestamp}] {message}\n"

        # 根据日志级别选择标签
        if level == "INFO":
            self.app.Message.insert(END, log_entry, "info")
        elif level == "ERROR":
            self.app.Message.insert(END, log_entry, "error")
        elif level == "ATTENTION":
            self.app.Message.insert(END, log_entry, "attention")
        elif level == "DATA":
            self.app.Message.insert(END, log_entry, "data")
        elif level == "COMMAND":
            self.app.Message.insert(END, log_entry, "command")
        else:
            self.app.Message.insert(END, log_entry, "info")

        self.app.Message.see(END)
        self.app.Message.config(state=DISABLED)

    def clear_message(self):
        self.app.Message.config(state=NORMAL)
        self.app.Message.delete(1.0, END)
        self.app.Message.config(state=DISABLED)
        self.log("日志已清空","INFO")

    def update_connection_state(self, connected):
        if connected:
            self.Connect_State_Icon.config(image=self.connect_icon)
            if self.app.Port_Select.get() == "VCOM":
                self.app.Open_Port.config(text="Close_Port")
        else:
            self.Connect_State_Icon.config(image=self.disconnect_icon)
            if self.app.Port_Select.get() == "VCOM":
                self.app.Open_Port.config(text="Open_Port")


def main():
    root = IAP_tools.tk.Tk()

    try:
        def get_logo_path():
            if getattr(sys, 'frozen', False):
                base_path = sys._MEIPASS
            else:
                base_path = os.path.dirname(os.path.abspath(__file__))
            return os.path.join(base_path, "Logo.ico")

        logo_path = get_logo_path()
        if os.path.exists(logo_path):
            root.iconbitmap(logo_path)  # 使用绝对路径
        else:
            messagebox.showwarning("警告", f"未找到Logo.ico文件: {logo_path}")
    except Exception as e:
        messagebox.showerror("错误", f"设置图标失败：{str(e)}")  # 弹窗显示错误

    app = IAP_tools.Toplevel1(root)

    # 窗口居中逻辑
    def center_window(window):
        # 确保窗口尺寸已计算
        window.update_idletasks()
        # 获取屏幕宽度和高度
        screen_width = window.winfo_screenwidth()
        screen_height = window.winfo_screenheight()
        # 获取窗口宽度和高度
        window_width = window.winfo_width()
        window_height = window.winfo_height()
        # 计算居中位置（左上角坐标）
        x = (screen_width - window_width) // 2
        y = (screen_height - window_height) // 2
        # 设置窗口位置
        window.geometry(f"+{x}+{y}")

    # 对主窗口进行居中
    center_window(root)

    IAPControl(app)
    root.mainloop()



if __name__ == "__main__":
    main()
