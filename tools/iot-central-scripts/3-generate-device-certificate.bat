@REM Generate the device certificate and key
@ECHO OFF

IF "%1" == "" (
    ECHO ERROR: Pass the device id as parameter.
    ECHO Usage:
    ECHO %0 ^<device-id^>
    EXIT /B 1
)

WHERE openssl
IF %ERRORLEVEL% NEQ 0 (
    ECHO ERROR: the openssl command was not found.
    EXIT /B 1
) 

openssl ecparam -out device_ec_key.pem -name prime256v1 -genkey
openssl req -new -key device_ec_key.pem -out device_ec.csr -subj "/CN=%1%"
openssl x509 -req -in device_ec.csr -CA ca_cert.pem -CAkey ca_key.pem -CAcreateserial -out device_ec_cert.pem -days 365 -sha256 -extensions client_auth

ECHO The device certificate and key has been generated.
ECHO You can generate the source code now.
