# Steps to create an IoT central application and a device for a quick demo
This readme will guide through creating of IoT central application

# Sign in to the Azure CLI
az login

# Create a resource group for the IoT Central application
az group create --location "mylocation" --name "myresourcegroup"

>Note: run "az account list-locations -o table" to know the locations available

# Create an IoT Central application
Below command will output Application Id, which will be used in the next steps.

az iot central app create --resource-group "myresourcegroup" --name "myiotcentralappname" --subdomain "mysubdomain"  --sku ST1 --template "iotc-pnp-preview"  --display-name "myiotcentralappname"

> **Note**: This readme uses "myiotcentralappname" as name for the IoT central application and "mysubdomain" for subdomain.  You may choose to use your own application name and subdomain.  
Give your IoT Central app a unique name so you can find it later.This will be used as the resource name in the Azure portal and CLI.  Avoid special characters - instead, use lower case letters (a-z), numbers (0-9), and dashes (-).
The subdomain should be a unique URL. Your app will be accessible via https://<mysubdomain>.azureiotcentral.com/  Avoid special characters - instead, use lower case letters (a-z), numbers (0-9), and dashes (-).

# Create the device template
Open your Iot Central app link  in browser  to create a new template or import your template.
Refer [How to setup a template](https://learn.microsoft.com/en-us/azure/iot-central/core/howto-set-up-template?) for more details

Your app will be accessible via https://mysubdomain.azureiotcentral.com/

# Create a device
To create a device:
1. From the application dashboard, select Devices on the side navigation menu.
2. Select Create a device from the All devices pane to open the Create a new device window. (If you're reusing an existing application that already has one or more devices, select + New to open the window.)
3. Fill in the desired Device name and Device ID
4. Leave Device template as Unassigned.
5. Select the Create button.
6. The newly created device will appear in the All devices list. Select on the device name to show details.
7. Select Connect in the top right menu bar to display the connection information used to configure the device
   Copy the ID scope and Device ID as it will be required in configuring the example code.
8. Select Authentication type to "Individual Enrollment"
9. Select Authentication Method to "Certificates (X.509)
10. Upload the primary and secondary certificate files. (For this demo you can upload the same device certificate file for both the options)
11. Clean Save.

# Run the demo application.
Once the application is running on the board go to the IoT Central portal to view the device status
From the application dashboard, select Devices on the side navigation menu.
Confirm that the Device status is updated to Provisioned and there will telemetry data.

For more details refer to [IoT Device Development Documentation](https://learn.microsoft.com/en-us/azure/iot-develop)

# Delete a central application
az iot central app delete --name "myiotcentralappname" --resource-group "myresourcegroup"

