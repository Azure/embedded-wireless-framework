@REM Generate the CA Cert
@ECHO OFF

IF NOT "%1" == "" (
    ECHO ERROR: This script takes no parameters.
    EXIT /B 1
)

WHERE openssl
IF %ERRORLEVEL% NEQ 0 (
    ECHO ERROR: the openssl command was not found.
    EXIT /B 1
) 

ECHO Generating the CA certificate...

openssl ecparam -out ca_key.pem -name prime256v1 -genkey
openssl req -new -days 3650 -nodes -x509 -key ca_key.pem -out ca_cert.pem -subj "/CN=CA Group 1"

ECHO Now validate the certificate in the file "ca_cert.pem" with the IoT Hub
