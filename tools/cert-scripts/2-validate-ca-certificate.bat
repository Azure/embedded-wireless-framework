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

openssl ecparam -out validation_ec_key.pem -name prime256v1 -genkey
openssl req -new -key validation_ec_key.pem -out validation_ec.csr -subj "/CN=%1%"
openssl x509 -req -in validation_ec.csr -CA ca_cert.pem -CAkey ca_key.pem -CAcreateserial -out validation_ec_cert.pem -extensions client_auth -days 30 -sha256

ECHO Upload the validation certificate validation_ec_cert.pem to the IoT Hub
