## Generating the device certificates

0. Pre-requisites

These instructions assumes the user has access to an Azure IoT Hub and has created a X.509 CA signed device registered to that hub.
Follow this [link](https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal) for instructions.<br/>
<br/>
[OpenSSL](https://www.openssl.org/) is used by the scripts, it needs to be installed in the system and in the path.<br/>
<br/>
Open a command interpreter and follow the steps below.<br/>
<br/>
1. Run 1-generate-ca-certificate.bat

```
.\1-generate-ca-certificate.bat
openssl.exe
Generating the CA certificate...
Now validate the certificate in the file "ca_cert.pem" with the IoT Hub
```

2. Open Azure Cloud portal and then open the IoT Hub created.
Select Certificates (Left side of the window, Security settings->Certificates)
and then Click Add
Add Certificate name, upload "ca_cert.pem" and then click Save.

3. Now open the created Certifcate and click on 'Generate verfification code'
Copy the verification code.

4. Run 2-validate-ca-certificate.bat and pass the verification code as argument

```
.\2-validate-ca-certificate.bat XYZXYZXYZXYZXYZ
C:\Program Files\OpenSSL-Win64\bin\openssl.exe
Signature ok
subject=CN = XXXXXXXXXXXX
Getting CA Private Key
Upload the validation certificate validation_ec_cert.pem to the IoT Hub
```
This will generate validation_ec_cert.pem file.
Upload this file to the Certificate created on Azure portal and click Verify.
Your certificate is now verified.

3. Run 3-generate-device-certificate.bat and pass the name of the CA signed device that you created

```
.\3-generate-device-certificate.bat mydevice-cert
openssl.exe
Signature ok
subject=CN = mydevice-cert
Getting CA Private Key
The device certificate and key has been generated.
You can generate the source code now.
```

4. Run 4-generate-source-files.bat and pass the Modem option( 1: Quectel 2: Renesas/Sequans) as argument to generate source files
```
.\4-generate-source-files.bat 1
Generating source files...
Processing file baltimore_ca_cert.pem...
Processing file ca_cert.pem...
Processing file device_ec_cert.pem...
Processing file device_ec_key.pem...
The source files have been generated.
Incorporate these into your program.
```

5. Copy the generated .h files in previous step to the required certificates project, preferrable to directory 
where other header files are located to ensure that path is included in the project.
