@REM Validate the CA certificate
@ECHO OFF

IF "%1" == "" (
    ECHO ERROR: Pass the validation code as parameter.
    ECHO Usage:
    ECHO %0 ^<validation code^>
    EXIT /B 1
)

WHERE openssl
IF %ERRORLEVEL% NEQ 0 (
    ECHO ERROR: the openssl command was not found.
    EXIT /B 1
) 

openssl ecparam -out validationkey.pem -name prime256v1 -genkey
openssl req -new -key validationkey.pem -out validation_.csr -subj "/CN=%1%"
openssl x509 -req -in validation_.csr -CA ca_cert.pem -CAkey ca_key.pem -CAcreateserial -out validationcert.pem -extensions client_auth -days 30 -sha256

ECHO Upload the validation certificate validationcert.pem to the IoT Hub
