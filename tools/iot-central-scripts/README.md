# Steps to create an IoT central application and a device for a quick demo  
This readme will guide through creating of IoT central application  
  
# Sign in to the Azure CLI  
az login  

# Create a resource group for the IoT Central application  
az group create --location "mylocation" --name "myresourcegroup"  

> Note: List of available regions for the resource type 'Microsoft.IoTCentral/IoTApps' is 'australiaeast,canadacentral,centralus,eastus,eastus2,japaneast,northeurope,southeastasia,southcentralus,uksouth,westcentralus,westeurope,westus'.  

# Create an IoT Central application  
Below command will output Application Id, which will be used in the next steps.  

az iot central app create --resource-group "myresourcegroup" --name "myiotcentralappname" --subdomain "mysubdomain"  --sku ST1 --template "iotc-pnp-preview"  --display-name "myiotcentralappname"  
  
> **Note**: This readme uses "myiotcentralappname" as name for the IoT central application and "mysubdomain" for subdomain.  You may choose to use your own application name and subdomain.  
Give your IoT Central app a unique name so you can find it later. This will be used as the resource name in the Azure portal and CLI.  
Avoid special characters - instead, use lower case letters (a-z), numbers (0-9), and dashes (-).  
The subdomain should be a unique URL. Your app will be accessible via https://<mysubdomain>.azureiotcentral.com/  Avoid special characters - instead, use lower case letters (a-z), numbers (0-9), and dashes (-).  

# Create the device template  
Open your Iot Central app link  in browser  to create a new template or import your template. For this example demo you can import the Thermostat.json  
Refer [How to setup a template](https://learn.microsoft.com/en-us/azure/iot-central/core/howto-set-up-template?) for more details  
  
Your app will be accessible via https://mysubdomain.azureiotcentral.com/  
  
> Note: The "mysubdomain" in the above link should be replaced with the subdomain set while the iot central app create step above. 
  
## How to connect devices with X.509 certificates to IoT Central Application  
This guide shows two ways to use X.509 certificates - group enrollments and individual enrollments...  
  
0. Pre-requisites  
[OpenSSL](https://www.openssl.org/) is used by the scripts, it needs to be installed in the system and in the path.  
These instructions assumes the user has access to [Microsoft Azure portal](https://portal.azure.com)  
  
### Use individual enrollment  
Use X.509 certificates with an individual enrollment to test your device and solution.  
In an individual enrollment, there's no root or intermediate X.509 certificate in your IoT Central application.  Devices use a self-signed X.509 certificate to connect to your application.  
  
#### Generate self-signed device certificate for Individual Enrollment  
  
> **Warning**  
> This way of generating X.509 certs is for testing only. For a production environment you should use your official, secure mechanism for certificate generation.  
  
Open a command interpreter and follow the steps below.  
  
1. Run **1-generate-ca-certificate.bat**  
  
```
.\1-generate-ca-certificate.bat
openssl.exe
Generating the CA certificate...
```
  
3. Run **3-generate-device-certificate.bat** and pass the name of the device that you will create on IoT Central.  
  
```
.\3-generate-device-certificate.bat mydevice-cert
openssl.exe
Signature ok
subject=CN = mydevice-cert
Getting CA Private Key
The device certificate and key has been generated.
You can generate the source code now.
```
  
3. Run **4-generate-source-files.bat** and pass the Modem option( 1: Quectel 2: Renesas/Sequans) as argument to generate source files  
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
  
4. Copy the generated .h files in generated in the previous step to the required certificate provsioning project, preferable to directory whose path is included in the project.
Once the certifcate example is run, it will provision the certificates onto the modem.  
  

# Create a device (Individual enrollment)  
To create a device:  
1. From the application dashboard, select Devices on the side navigation menu.  
2. Select Create a device from the All devices pane to open the Create a new device window. (If you're reusing an existing application that already has one or more devices, select + New to open the window.)  
3. Fill in the desired Device name and Device ID  
4. Select the device template, thermostat device template if that was created previously or anyother that user has configured.  
5. Open the device you created and select Connect. Note the ID scope value that will be used in the later steps  
6. Select **Individual enrollment** as the **Authentication type** and **Certificates (X.509)** as the **Authentication method**.  
7. Upload the primary and secondary certificate files. (For this demo you can upload the same device certificate file device_ec_cert.pem, which was generated previously for both the options)  
8. Click Save. The device now has an individual enrollment with X.509 certificates.  
  
### Use group enrollment  
Use X.509 certificates with a group enrollment in a production environment.  In a group enrollment, you add a root or intermediate X.509 certificate to your IoT Central application. Devices with leaf certificates derived from the root or intermediate certificate can connect to your application.  

#### Generate root and device certificates for Group Enrollment  
  
> **Warning**  
> This way of generating X.509 certs is for testing only. For a production environment you should use your official, secure mechanism for certificate generation.  
  
1. Run **1-generate-ca-certificate.bat**  
  
```
.\1-generate-ca-certificate.bat
openssl.exe
Generating the CA certificate...
```
  
2. Create a Group Enrollement on IoT Central Application  
  
    a. Open your IoT Central application and navigate to Permissions in the left pane and select Device connection groups.  
    b. Select + New to create a new enrollment group called MyX509Group with an attestation type of Certificates (X.509) and click Save.  
    c. In the enrollment group you created, select Manage primary.  
    d. In the Primary certificate panel, and select Add certificate.  
    e. Upload the "ca_cert.pem" that you generated previously.  
    f. If you're using an intermediate or root certificate authority that you trust and know you have full ownership of the certificate,  you can self-attest that you've verified the certificate by setting certificate status verified on upload to On. Otherwise, set certificate status verified on upload to Off.  
    g. If you set certificate status verified on upload to Off, select Generate verification code.  
    h. Copy the verification code  
  
3. Run **2-validate-ca-certificate.bat** and pass the verification code as argument  
  
```
.\2-validate-ca-certificate.bat XYZXYZXYZXYZXYZ
C:\Program Files\OpenSSL-Win64\bin\openssl.exe
Signature ok
subject=CN = XXXXXXXXXXXX
Getting CA Private Key
Upload the validation certificate validation_ec_cert.pem to the IoT Hub
```
  
This will generate validation_ec_cert.pem file.  Select Verify to upload the signed verification certificate validation_ec_cert.pem to complete the verification.  
  
4. The status of the primary certificate is now Verified. Close the Primary Certficate window.  
5. After you save the enrollment group, make a note of the ID scope  
6. Run **3-generate-device-certificate.bat** and pass the name for the device that you want to be created on your IoT Central Application  
  
```
.\3-generate-device-certificate.bat mydevice-cert
openssl.exe
Signature ok
subject=CN = mydevice-cert
Getting CA Private Key
The device certificate and key has been generated.
You can generate the source code now.
```
  
7. Run **4-generate-source-files.bat** and pass the Modem option( 1: Quectel 2: Renesas/Sequans) as argument to generate source files  
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
8. Copy the generated .h files in generated in the previous step to the required certificate provsioning project, preferable to directory whose path is included in the project.
Once the certifcate example is run, it will provision the certificates onto the modem.  
9. Reapeat Steps 6-8 for provisioning certificates to more devices. Make sure you use a unique name for the device in step 6.  
  
# Create a device (Group enrollment)  
In group enrollement, the process to create a device like the one mentioned in the above Individual enrollment section is not required.  
  
# Run the demo application.  
Update the EWF_CONFIG_ID_SCOPE, EWF_CONFIG_REGISTRATION_ID value in ewf_example.config.h file.  
Once the application is running on the board go to the IoT Central portal to view the device status  
From the application dashboard, select Devices on the side navigation menu.  
Confirm that the Device status is updated to Provisioned and there will telemetry data.  

For more details refer to [IoT Device Development Documentation](https://learn.microsoft.com/en-us/azure/iot-develop)  
  
# Delete a central application  
az iot central app delete --name "myiotcentralappname" --resource-group "myresourcegroup"  
  
az group delete --name "myresourcegroup"  
  