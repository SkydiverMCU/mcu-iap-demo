@echo off
ECHO Computing CRC
ECHO -------------------------------------
REM Batch script for generating CRC in KEIL project
REM Must be placed at MDK-ARM folder (project folder)

REM Path configuration
SET CRC_ADDRESS=0x17FC
SET TARGET_NAME=Bootloader
SET TARGET_PATH=Objects


REM Derived configuration
SET ELF_FILE=%TARGET_PATH%\%TARGET_NAME%.axf
SET CRC_BLOCK=64

mcu_crc.exe MCU  %ELF_FILE%  --a%CRC_ADDRESS%

ECHO -------------------------------------