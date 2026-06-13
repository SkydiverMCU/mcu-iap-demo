@echo off
setlocal enabledelayedexpansion

REM 获取脚本所在目录的完整路径
SET "SCRIPT_DIR=%~dp0"
REM 去除路径末尾的反斜杠（如果有）
if "%SCRIPT_DIR:~-1%"=="\" SET "SCRIPT_DIR=%SCRIPT_DIR:~0,-1%"

REM 设置输入输出路径
SET "HEX_PATH=%SCRIPT_DIR%\Objects\Application_CRC.hex"
SET "INPUT_PATH=%SCRIPT_DIR%\Objects\Application_CRC.bin"
SET "BIN_PATH=%SCRIPT_DIR%\Update.bin"

REM 检查 hex2bin.exe 是否存在
if not exist "%SCRIPT_DIR%\hex2bin.exe" (
    ECHO [error] do not find hex2bin.exe,Please ensure it is located in the current directory:%SCRIPT_DIR%
)

REM 检查 HEX 文件是否存在
if not exist "%HEX_PATH%" (
    ECHO [error] HEX file not found:%HEX_PATH%
)

ECHO ========================================
ECHO Converting HEX file to BIN file...
ECHO Input: %HEX_PATH%
ECHO Output %BIN_PATH%
ECHO Fill:  0xFF
ECHO ========================================

REM 执行 hex2bin 转换，使用 -p 参数指定填充值为 0xFF
REM -p 参数格式：-p 填充值（十进制），0xFF 的十进制值为 255
"%SCRIPT_DIR%\hex2bin.exe" -p 0xFF -c "%HEX_PATH%"

if errorlevel 1 (
    ECHO.
    ECHO [Error] Conversion failed. Please check the output information of hex2bin
) else (
    ECHO.
    ECHO [Success] Conversion completed! Generated: %INPUT_PATH%
	ECHO ========================================
	REM ========== 重命名文件 ==========
	ECHO Rename the file name: Update.bin
    if exist "%INPUT_PATH%" (
        copy /y "%INPUT_PATH%" "%BIN_PATH%" >nul
        echo Renamed to: %BIN_PATH%
    ) else (
        echo [Warning] %INPUT_PATH% not found, rename skipped.
    )
)

REM 可选：显示生成的文件大小
if exist "%BIN_PATH%" (
    for %%I in ("%BIN_PATH%") do ECHO File size: %%~zI Byte
)
