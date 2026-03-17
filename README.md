# MM32-IAP-Demo

#### 项目介绍
- MM32MCU IAP 上位机/协议/源码，不定期收集分享开源资料，来源于https://gitee.com/jitingai/mm32_-iap_-demo
- 基于原始开源仓库，更新迭代到V2.0版本

#### IAP升级软件流程图
![image](https://gitee.com/skydiver/mm32-iap-demo/raw/master/Flowchart/IAP_Flowchart.png)

### 项目文件介绍

```
mm32-iap-demo

├─Cortex-M0
│  ├─MM32F0010
│  ├─MM32F0020
│  ├─MM32F0040
│  ├─MM32F0050
│  ├─MM32F0120
│  ├─MM32F0130
│  ├─MM32F0140
│  ├─MM32F0160
│  ├─MM32F0270
│  ├─MM32G0001
│  ├─MM32G0020
│  ├─MM32SPIN0230
│  ├─MM32SPIN0280
│  ├─MM32SPIN05
│  ├─MM32SPIN06
│  └─MM32SPIN07
|
├─Cortex-M0+
│  ├─MM32G0005
│  ├─MM32L0020
│  ├─MM32L0130
│  └─MM32L0180
|
├─Cortex-M3
│  └─MM32F3270
|
├─STAR-MC1
│  ├─MM32F5270
│  ├─MM32F5330
│  └─MM32F5370
|
├─Flowchart (程序流程图)
|
├─Python_IAP_Tools_SourceCode
│  ├─IAP_tools_Python_Project (IAP_Tools上位机软件 Python源码) 
│  └─PAGE_GUI_Project (IAP_Tools GUI界面原始文件)
|
├─screenshots
|
├─Tools
│  ├─IAP_Tools.exe
│  ├─Merge_Tools.exe
│  └─网页版hex合并工具.html
|
├─.gitignore
├─IAP协议说明_20251225.xlsx
├─LICENSE
├─README.en.md
└─README.md


```

### V2.0更新说明

- 基于原始仓库优化原始协议，更新到IAP协议说明_20251225.xlsx
- Bootloader工程增加CRC32校验，分别校验Boot区间/APP区间和1K Information区间，同时判断栈顶地址是否合法，保证程序严谨
- Application工程增加app_protocol.c/app_protocol.h 文件，支持接收上位机指令擦除1K Information区间后跳转回Bootloader进行程序升级
- Merge_Tools.exe 和 网页版hex合并工具.html 是Boot 与 APP合并工具，合并后会在Bootloader程序后面1K区间添加标志/APP长度/APP CRC32校验/1K Information区间1020 byte区间CRC32校验,最后生成一个Bootloader_CRC.hex文件供烧录调试
- 工程书写统一规范进行代码格式化，Bootloader 统一使用 boot.c/boot.h/crc32_algorithm.c/crc32_algorithm.h
- 移除原始仓库里面的I2C主从机工程
- 由于原始仓库配套测试上位机没有源码无法修改，所以V2.0版本开始移除原始仓库配套的上位机


### 项目移植其他MCU平台说明

- 编译后会调用crc_gen_keil.bat批处理把Bootloader区间数据计算CRC32 最终写到Bootloader最末尾
- 编译后生成的Bootloader.hex通过批处理添加CRC32校验码之后生成Bootloader_CRC.hex，debug调试会通过加载crc_load.ini文件选择烧录Bootloader_CRC.hex
- Bootloader启动后会按顺序读取校验Bootloader CRC，1K Information CRC和APP区间CRC还有跳转标志，都校验通过才会跳转到App去执行 
- 如果要要移植到其他MCU平台，需要修改如下地方：
###### Bootloader:
> 1. Copy main.c/boot.c/boot.h/crc32_algorithm.c/crc32_algorithm.h 到目标工程，将MDK-ARM 目录下crc_gen_keil.bat/crc_load.ini/mcu_crc.exe 也复制到目标工程下
> 2. 修改Bootloader Keil工程 Target里面分配Flash空间大小，如果是STAR-MC1内核，请到Keil 工程里面Options for Target -> Linker 修改分散加载文件.sct，添加Options for Target -> User After Build/Rebuild 添加.\crc_gen_keil.bat 脚本执行，用于处理生成Bootloader_CRC.hex
> 3. 修改boot.h文件里面#define BOOT_SIZE 7 这个宏(配置Boot大小), #define FLASH_SIZE 128(这个宏定义Flash最大空间)，#define SRAM_LEGAL_ADDRESS_MASK 0x2FFFF000 配置SRAM合法地址范围，需要注意main.c if (((*(__IO uint32_t *)ApplicationAddress) & SRAM_LEGAL_ADDRESS_MASK) == 0x20000000) // 检查栈顶地址是否SRAM合法，这个地址需要和实际芯片匹配
> 4. Keil工程同目录下crc_gen_keil.bat 这个批处理里面的宏SET CRC_ADDRESS=0x1BFC（这个地址是设置Boot区间CRC32的存放位置，计算方法就是Boot大小-4，例如BOOT定义7K：（7 * 1024）- 0x04 = 0x1BFC）
> 5. 在main.c 文件里面修改IAP升级外设初始化函数，以UART升级为例：修改UART_Configure(115200);
> 6. 实现数据接收，以UART升级为例：中断接收void UART1_IRQHandler(void)里面 uint16_t UART_RX_STA 和 uint8_t UART_RxBuff[REPORT_PACKET_SIZE]进行数据接收 
> 7. 实现数据发送，以UART升级为例：void UART_SendGroup(uint8_t *pBuff, uint16_t length)
> 8. 实现Boot.c文件里面Flash读写函数：static void FLASH_Write(const uint8_t *buff, uint32_t addr, uint32_t writeNumber) 和 void FLASH_Read(uint8_t *buff, uint32_t addr, uint32_t readNumber)
> 9. 需要注意Boot.c文件里面void writeAppFlag(uint8_t *buff) 函数，写1K Information区间也有写Flash操作，需要和实际芯片匹配
##### Application:
> 1. Copy main.c/app_protocol.c/app_protocol.h 到目标工程
> 2. 修改Application Keil工程 Target里面分配Flash空间大小,方法同上
> 3. 修改app_protocol.h文件，方法同上
> 4. 在main.c 文件里面修改外设初始化函数，以UART升级为例：修改UART_Configure(115200);
> 5. 同样需要实现数据收发，方法同上
> 6. 注意当前MCU平台，M0使用copy向量表到SRAM,其他M0+/M3/M4/M33/STAR-MC1 则可以直接设置SCB->VTOR 进行中断向量表偏移

## 项目配套工具截图

#### 上位机软件界面截图
![image](https://gitee.com/skydiver/mm32-iap-demo/raw/master/screenshots/IAP_Tools.png)

#### 网页版hex合并工具界面截图
![image](https://gitee.com/skydiver/mm32-iap-demo/raw/master/screenshots/Merge_tools_for_web.png)

#### hex合并工具界面截图
![image](https://gitee.com/skydiver/mm32-iap-demo/raw/master/screenshots/Merge_Tools.png)

