# Wi-SUN - SoC Empty

The Wi-SUN Empty sample application is a bare-bones application. This application can be used as a template to develop a Wi-SUN application.

## Getting Started

To get started with Wi-SUN and Simplicity Studio, see [QSG181: Wi-SUN SDK Quick Start Guide](https://www.silabs.com/documents/public/quick-start-guides/qsg181-wi-sun-sdk-quick-start-guide.pdf).

The SoC term stands for "System on Chip", meaning that this is a standalone application running on the EFR32 without any external MCU required.

As the name implies, the example is an empty template that only has the bare minimum to make a working Wi-SUN application. For this purpose, the example includes the Wi-SUN stack component and its dependencies (RTOS, cryptographic library...).This skeleton can be extended with application logic.

The development of a Wi-SUN application consists of two main steps:

* Responding to the events raised by the Wi-SUN stack
* Implementing additional application logic

## Responding to Wi-SUN Events

A Wi-SUN application is event-driven. The Wi-SUN stack generates events when a connection is successful, data has been sent, or an IP packet is received. The application has to handle these events in the *sl_wisun_on_event()* function. The prototype of this function is implemented in *app.c*. To handle more events, the switch-case statement of this function must be created and extended. For the list of Wi-SUN events, see [Wi-SUN API Reference](https://docs.silabs.com/wisun/latest/).

## Implementing Application Logic

Additional application logic can be implemented in the *app_task()* function. Find the definition of this function in *app.c*. The *app_task()* function is called once when the device is booted and after the Wi-SUN stack initialization.

The first step in most Wi-SUN applications is to call *sl_wisun_join()* to connect the Wi-SUN device to a Wi-SUN border router. The remaining implementation is up to the developer. Refer to the [Wi-SUN API Reference](https://docs.silabs.com/wisun/latest/) to check the list of Wi-SUN APIs available to the application.

## Troubleshooting

Before programming the radio board mounted on the WSTK, ensure the power supply switch is in the AEM position (right side), as shown.

![Radio Board Power Supply Switch](readme_img0.png)

## Resources

* [Wi-SUN Stack API documentation](https://docs.silabs.com/wisun/latest)
* [AN1330: Wi-SUN Mesh Network Performance](https://www.silabs.com/documents/public/application-notes/an1330-wi-sun-network-performance.pdf)
* [AN1332: Wi-SUN Network Setup and Configuration](https://www.silabs.com/documents/public/application-notes/an1332-wi-sun-network-configuration.pdf)
* [AN1364: Wi-SUN Network Performance Measurement Application](https://www.silabs.com/documents/public/application-notes/an1364-wi-sun-network-performance-measurement-app.pdf)
* [QSG181: Wi-SUN Quick-Start Guide](https://www.silabs.com/documents/public/quick-start-guides/qsg181-wi-sun-sdk-quick-start-guide.pdf)
* [UG495: Wi-SUN Developer's Guide](https://www.silabs.com/documents/public/user-guides/ug495-wi-sun-developers-guide.pdf)

## Report Bugs & Get Support

You are always encouraged and welcome to ask any questions or report any issues you found to us via [Silicon Labs Community](https://community.silabs.com/s/topic/0TO1M000000qHc6WAE/wisun).

## Cloning GitHub repository

### Step 1: Go to "https://github.com/vaibhavnaware01/FAN10_FSK_FG12".

### Step 2: Download as zip.

![08 06 2024_11 18 21_REC](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/b93ada4c-cd7e-4685-86fa-f4f2028c8436)

### Step 3: Extract the .zip file 

### Step 4: Open "Simplicity Studio" 

![image](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/ef438c46-18e9-4cd0-b7c0-677016fd6ba0)

### Step 5: Go to Install-->Manage Install Packages-->SDK and check geckoSDK version = 4.2.2

![Screenshot 2024-06-08 120726](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/ce27de5d-9667-4704-b2c3-6918435e8882)

![Screenshot 2024-06-08 120935](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/f53cd783-f70d-4572-a526-6fef80c3170f)

![Screenshot 2024-06-08 115212](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/8bec5568-93df-46c2-bebf-bf2abaa55596)

If geckoSDK version is not 4.2.2 you can go to "add-->version-->selecte version 4.2.2-->click FINISH"

![Screenshot 2024-06-08 115803](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/e21c109b-1ac4-4cdf-b1ec-fbfd9f86255b)

![Screenshot 2024-06-08 115951](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/5cb746d2-5993-4a8c-9c97-aae312a4fc34)

![Screenshot 2024-06-08 120112](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/fa194de3-02d3-4a22-a36c-91a9df2df967)

The installation will take some time 

### Step 6: After completing the installation we will import the "FAN1.0_FSK_FG12-main" in our Simplicity Studio.

![Screenshot 2024-06-08 123053](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/88942299-e4f4-44c1-a056-a2c0c9fdbf16)

![Screenshot 2024-06-08 123243](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/79a2fc3c-cb9e-4876-9562-1dfdb529408c)

![Screenshot 2024-06-08 123455](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/651ee260-4004-4cc7-9105-61b608e4a79a)

![Screenshot 2024-06-08 123611](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/73a5ffa5-5a7e-4e0a-90d7-f992c0512ae2)

![Screenshot 2024-06-08 123908](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/1727caa7-2e18-44d3-93f1-86824fd10b90)

![Screenshot 2024-06-08 124200](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/7987cfc6-f1f9-43d2-8d50-53899d61c0d3)

![Screenshot 2024-06-08 125317](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/5198bff7-648d-43ce-ade9-e8db8ef4eb7f)

![Screenshot 2024-06-08 133458](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/15ce06e2-4eb9-4d05-9fda-1f4bb5eb9307)

![Screenshot 2024-06-08 133659](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/e5e170d8-8513-4f71-b63b-803af1807f1c)

![Screenshot 2024-06-08 134253](https://github.com/vaibhavnaware01/FAN10_FSK_FG12/assets/123818719/3dde2e63-8e8e-42c3-a164-fde12cd7694e)


