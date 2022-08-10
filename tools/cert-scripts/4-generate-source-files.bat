@REM Generate the device certificate and key
@ECHO OFF

IF "%1"=="" (
    ECHO ERROR: Pass the Cellular Module option. & echo.
    ECHO OPTIONS & echo.Quectel - 1  & echo.Renesas/Sequans - 2 & echo.
    ECHO Usage:
    ECHO %0 ^<Option_NO^>
    EXIT /B 1
)

SET /A modem = %1%

ECHO Generating source files...

FOR %%i IN (baltimore_ca_cert.pem ca_cert.pem device_ec_cert.pem device_ec_key.pem) DO CALL :processfile %%i

ECHO The source files have been generated.
ECHO Incorporate these into your program.

EXIT /B 0

:processfile
SET file=%1
ECHO Processing file %file%...
SET var=%file:.=_%
ECHO const char * const %var% => %file%.h
IF %modem%==1 (FOR /F "tokens=*" %%a IN (%1) DO CALL :processline1 %%a
ECHO ;>> %file%.h)
IF %modem%==2 (FOR /F "tokens=*" %%a IN (%1) DO CALL :processline2 %%a
ECHO ;>> %file%.h)

EXIT /B 0

:processline1
ECHO "%*\r\n">> %file%.h
EXIT /B 0

:processline2
ECHO "%*\n">> %file%.h
EXIT /B 0
