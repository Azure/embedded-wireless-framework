@REM Generate the CA Cert
@ECHO OFF

IF "%1" == "" (
    ECHO ERROR: Pass path to include directory in the example project.
    ECHO Usage:
    ECHO %0 ^<Path to common dir^>
    EXIT /B 1
)


ECHO Copying the source files...

FOR %%i IN (baltimore_ca_cert.pem.h ca_cert.pem.h device_ec_cert.pem.h device_ec_key.pem.h) do COPY /Y %%i %1%

ECHO Source files copied.
