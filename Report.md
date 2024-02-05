






![ref1]![ref2]![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.003.png)



























![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.004.png)![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.005.jpeg)![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.006.png)![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.007.png)![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.008.jpeg)
<a name="_hlk155091873"></a>5



![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.009.png)



|<p></p><p><a name="_hlk103290827"></a>**NAME**</p><p></p>|<p></p><p>**ID**</p>|
| - | - |
|<p></p><p>**Kareem Moataz**</p><p></p>|<p></p><p>**20P4361**</p>|
|<p></p><p>**Youssef Emad**</p><p></p>|<p></p><p>**20P3844**</p>|
|<p></p><p>**Mohamed Amr**</p><p></p>|<p></p><p>**20P3485**</p>|
|<p></p><p>**Heba Hesham**</p><p></p>|<p></p><p>**20P8736**</p>|

![A red and white logo

Description automatically generated](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.010.png)[\[Project Link\](https://drive.google.com/drive/folders/1xKaWiwnQjYaOrV8l7MpXtJE68NL3piak?usp=drive_link)](https://drive.google.com/drive/folders/1xKaWiwnQjYaOrV8l7MpXtJE68NL3piak?usp=sharing)

[](https://drive.google.com/drive/folders/1xKaWiwnQjYaOrV8l7MpXtJE68NL3piak?usp=sharing)

# Table of Contents
[1.	Table of Figures	5](#_toc155099181)

[2.	Introduction	6](#_toc155099182)

[2.1.	Li-Fi Technology Overview	6](#_toc155099183)

[2.2.	Purpose of the Hazard Detection System	6](#_toc155099184)

[2.3.	Project Scope	6](#_toc155099185)

[3.	System Overview	7](#_toc155099186)

[3.1.	Sender Board	7](#_toc155099187)

[3.2.	Receiver Board	8](#_toc155099188)

[4.	3. List of components	9](#_toc155099189)

[4.1.	Components	9](#_toc155099190)

[4.1.1.	Sender Board	9](#_toc155099191)

[4.1.2.	Receiver Board	10](#_toc155099192)

[4.2.	Operation	11](#_toc155099193)

[5.	Contribution of Group Members	11](#_toc155099194)

[6.	Circuits Wiring	12](#_toc155099195)

[6.1.	Individual components	12](#_toc155099196)

[6.2.	Whole Circuit	13](#_toc155099197)

[7.	Mobile App Discussion	14](#_toc155099198)

[7.1.	Serial Bluetooth Terminal	14](#_toc155099199)

[7.2.	Key Features	14](#_toc155099200)

[7.2.1.	Bluetooth Pairing	14](#_toc155099201)

[7.2.2.	Real-time Alerts	14](#_toc155099202)

[7.2.3.	Detailed Notifications	14](#_toc155099203)

[7.3.	Functionality in Action	15](#_toc155099204)

[7.3.1.	Bluetooth Pairing Process	15](#_toc155099205)

[7.3.2.	Receiving and Displaying Alerts	15](#_toc155099206)

[7.3.3.	User Interaction	15](#_toc155099207)

[7.4.	Steps	16](#_toc155099208)

[7.4.1.	Application on play store	16](#_toc155099209)

[7.4.2.	Open application	16](#_toc155099210)

[7.4.3.	Connect to Bluetooth	17](#_toc155099211)

[7.4.4.	Initializing global list with mapping each item to its block	17](#_toc155099212)

[7.4.1.	Mobile Application Features & Screen	18](#_toc155099213)

[8.	Flowchart of the main flow of the program	19](#_toc155099214)

[9.	Problems Faced and Solutions:	20](#_toc155099215)





1. # <a name="_toc155099181"></a>Table of Figures
[Figure 1: Sender Board	7](#_toc155098666)

[Figure 2: Reciver Board	8](#_toc155098667)

[Figure 3: Tiva C (TM4C123GH6PM)	9](#_toc155098668)

[Figure 4: Ultrasonic	9](#_toc155098669)

[Figure 5: Magnetic Sensor	9](#_toc155098670)

[Figure 6: Temperature Sensor	9](#_toc155098671)

[Figure 7: Arduino Uno	10](#_toc155098672)

[Figure 8: LDR	10](#_toc155098673)

[Figure 9: Buzzer	10](#_toc155098674)

[Figure 10: LCD Shield with Keypad	10](#_toc155098675)

[Figure 11: Bluetooth Module	10](#_toc155098676)

[Temperature SensorFigure 12 SYSTEM LAYOUT	12](D:\Fall 2023\Introduction to embedded system\Project\Report\Report.docx#_Toc155098677)

[Figure 13: Sender Board Simulation	13](#_toc155098678)

[Figure 14: Receiver Board Simulation	13](#_toc155098679)

[Figure 15: MIT App in play store	16](#_toc155098680)

[Figure 16: MIT App Home Screen	16](#_toc155098681)

[Figure 17: Bluetooth Connection	17](#_toc155098682)

[Figure 18: Initializing global list and Splitting list sent items at “, " and maps each item to its block.	17](#_toc155098683)

[Figure 19: Mobile Application Features	18](#_toc155098684)

[Figure 20: Main Program Flow Chart	19](#_toc155098685)









![ref1]![A blue and white logo

Description automatically generated][ref2]![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.011.png)

1. # <a name="_toc155088971"></a><a name="_toc155099182"></a><a name="_toc154723991"></a>Introduction
The Li-Fi Hazard Detection System harnesses the innovative capabilities of Li-Fi technology, a wireless communication paradigm that utilizes light to transmit data across devices. Unlike traditional wireless communication methods, Li-Fi operates within the visible light spectrum, offering theoretical speeds of up to 100 Gbit/sec. This project explores the integration of Li-Fi for residential hazard detection, emphasizing its unique advantages for secure and interference-free data transmission.
1. ## <a name="_toc155088972"></a><a name="_toc155099183"></a>Li-Fi Technology Overview
Li-Fi, or Light Fidelity, exploits the properties of light, including visible light, infrared, or ultraviolet spectrums, to transmit data seamlessly. Its core advantage lies in the inability of light signals to penetrate through walls, ensuring a secure communication channel within confined spaces. The system's transmission via light also circumvents interference with radar waves, making it suitable for deployment in areas with electromagnetic interference.
1. ## <a name="_toc155088973"></a><a name="_toc155099184"></a>Purpose of the Hazard Detection System
The primary objective of our Li-Fi Hazard Detection System is to enhance home safety by integrating sensors and smart communication protocols. The system consists of a sender platform (TM4C123GH6PM) connected to sensors such as a Fume Sensor, Ultrasonic Sensor, and Magnetic Sensor. When these sensors detect potential hazards, the system triggers an alert mechanism through two channels: Li-Fi transmission to a receiver platform and Bluetooth communication with a mobile app.

- The unique characteristics of Li-Fi offer a distinct advantage for home security.
- Intrusion Prevention: Since light signals cannot penetrate walls, the Li-Fi system ensures that signals remain within the confines of the home, preventing remote hacking.
- Electromagnetic Compatibility: The transmission over light does not interfere with radar waves, making it safe for use in environments with electromagnetic interference.
  1. ## <a name="_toc155088974"></a><a name="_toc155099185"></a>Project Scope
This project extends beyond theoretical exploration by implementing a functional prototype. The sender platform integrates sensors for hazard detection, while the receiver platform activates alarms, including a flashing lamp, buzzer, and an LCD display conveying relevant information about the detected event (e.g., "Fire is reported"). Additionally, the system incorporates a Bluetooth module to communicate with a mobile app, providing real-time alerts to homeowners.

The hazard detection system is designed to be user-friendly, featuring start/stop pushbuttons for easy operation and a mute pushbutton to silence alarms when necessary. The system remains operational even after alarms are muted, ensuring continuous monitoring of the home environment.
1. # <a name="_toc155099186"></a>System Overview
   1. ## <a name="_toc155099187"></a>Sender Board













![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.012.png)

<a name="_hlk155089108"></a><a name="_toc155098666"></a>*Figure 1: Sender Board*


<a name="_toc154723994"></a>
1. ## <a name="_toc155088993"></a><a name="_toc155088994"></a><a name="_toc155099188"></a>Receiver Board












![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.013.png)

<a name="_toc155098667"></a>*Figure 2: Reciver Board*












1. # <a name="_toc155088995"></a><a name="_toc155099189"></a>3. List of components
   1. ## <a name="_toc155088996"></a><a name="_toc155099190"></a>Components
      1. ### <a name="_toc155099191"></a>Sender Board

- ![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.014.jpeg)Sender platform (TM4C123GH6PM) 

<a name="_toc155092762"></a><a name="_toc155098668"></a>*Figure 3: Tiva C (TM4C123GH6PM)*

- Sensors (Temperature, Ultrasonic, Magnetic)


|<p>![Ultrasonic Sensor Module – Future Electronics Egypt]</p><p><a name="_toc155098669"></a>*Figure 4: Ultrasonic*</p>|<p>![Magnetic Switch Door Sensor (MC-38) - Lampatronics](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.016.jpeg)</p><p></p><p><a name="_toc155098670"></a>*Figure 5: Magnetic Sensor*</p><p></p>|<p>![Temperature Sensor - TMP36 | Sparkfun SEN-10988 | Core Electronics Australia](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.017.jpeg)</p><p></p><p><a name="_toc155098671"></a>*Figure 6: Temperature Sensor*</p><p></p>|
| :-: | :-: | :-: |




1. ### <a name="_toc155099192"></a>Receiver Board
   1. #### Receiver Platform
      ![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.018.png)

<a name="_toc155098672"></a>*Figure 7: Arduino Uno*
1. #### Sensors (LDR, buzzer, LCD)


|<p>![LDR Light Dependent Resistor, 12 V](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.019.jpeg)</p><p><a name="_toc155098673"></a>*Figure 8: LDR*</p>|<p>![Buzzers](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.020.jpeg)</p><p><a name="_toc155098674"></a>*Figure 9: Buzzer*</p><p></p>|<p>![LCD (Character LCD 2x16) Blue - RAM Electronics](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.021.jpeg)</p><p><a name="_toc155098675"></a>*Figure 10: LCD Shield with Keypad*</p>|
| :-: | :-: | :-: |

1. #### Bluetooth module for mobile phone communication
![Bluetooth Module HC-05 , Serial TTL "Most Popular" - RAM Electronics](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.022.jpeg)

<a name="_toc155098676"></a>*Figure 11: Bluetooth Module*


1. ## <a name="_toc155088999"></a><a name="_toc155099193"></a>Operation
1. Hazard detection by sensors triggers alarms.
1. Alarms transmitted via light and Bluetooth to receiver and mobile app.
1. Pushbuttons for start/stop operations.
1. Mute pushbutton to silence alarms.


1. # <a name="_toc155099194"></a>Contribution of Group Members
<a name="_toc155089000"></a>” Kareem Motaz”

Role: Sensor Integration Specialist

- Implemented the integration of various sensors, including the Temperature Sensor, Ultrasonic Sensor, and Magnetic Sensor, with the TM4C123GH6PM platform.
- Ensured accurate sensor readings and data transmission to the central processing unit.
- Collaborated with team members on circuit wiring and troubleshooting during the sensor integration phase.

` `“Heba Hesham”

Role: Bluetooth and Mobile App Developer

- Developed the communication module for Bluetooth connectivity between the Li-Fi Hazard Detection System and the mobile app.
- Implemented Bluetooth data transmission protocols and ensured seamless communication with the HC-05 Bluetooth module.
- Developed the mobile app using App Inventor, incorporating the Serial Bluetooth Terminal functionality for real-time monitoring and user interaction.
- Created detailed documentation, including system layout, component lists, circuit wiring diagrams, and flow charts.

` `“Youssef Emad”

Role: Alarm and Interface Design Engineer

- Designed and implemented the alarm system, including the flashing lamp, buzzer, and LCD display, for effective hazard alert notifications.
- Collaborated with Member 2 to integrate the alarm system with the Bluetooth and mobile app functionalities.
- Contributed to the creation of the solid structure for fixing the light source to enhance Li-Fi transmission efficiency.

` `“Mohamed Amr”

Role: System Integration and User Interface Specialist

- Led the overall system integration, ensuring seamless communication between sensors, alarms, and communication modules.
- Designed the user interface for the TM4C123GH6PM platform, incorporating start/stop pushbuttons and mute functionality.
- Collaborated with Member 3 on the alignment of the light source structure with the Li-Fi module for optimal data transmission.
1. # <a name="_toc155089001"></a><a name="_toc155099195"></a>Circuits Wiring

1. ## <a name="_toc155089002"></a><a name="_toc155099196"></a>Individual components


|<p></p><p></p><p></p><p></p><p>![ref3]</p>|<p>
</p><p></p><p></p><p>![ref3]</p>|
| :- | :- |
|<p>
</p><p></p><p></p><p>![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.024.png)</p>|<p>
</p><p></p><p></p><p>![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.025.png)![ref3]</p>|


1. ## <a name="_toc155098677"></a><a name="_toc155089003"></a><a name="_toc155099197"></a>Whole Circuit

![A circuit board with wires connected to it

Description automatically generated](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.026.jpeg)

<a name="_toc155098678"></a>*Figure 13: Sender Board Simulation*

![A circuit board with wires

Description automatically generated](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.027.jpeg)

<a name="_toc155098679"></a>*Figure 14: Receiver Board Simulation*



1. # <a name="_toc155089004"></a> <a name="_toc155099198"></a>Mobile App Discussion
The mobile app developed for the Li-Fi Hazard Detection System utilizes the Serial Bluetooth Terminal functionality to establish communication with the HC-05 Bluetooth module. Here's an overview of the app's key functionalities and features:

1. ## <a name="_toc155089005"></a><a name="_toc155099199"></a>Bluetooth App

The Bluetooth App serves as a crucial interface between the Li-Fi Hazard Detection System and the user's mobile device. It leverages the capabilities of the HC-05 Bluetooth module to facilitate two-way communication, allowing users to monitor alerts, receive detailed notifications, and exercise control over the system.

1. ## <a name="_toc155089006"></a><a name="_toc155099200"></a>Key Features

1. ### <a name="_toc155099201"></a>Bluetooth Pairing
The app enables users to pair their mobile devices with the HC-05 Bluetooth module, establishing a secure and reliable connection for data exchange.

1. ### <a name="_toc155099202"></a>Real-time Alerts
Users receive real-time hazard alerts from the Li-Fi Hazard Detection System through the Bluetooth connection. The app acts as a conduit for these alerts, ensuring users are promptly informed.

1. ### <a name="_toc155099203"></a>Detailed Notifications
The app displays detailed information about detected hazards, providing users with specific details related to fire detection, door openings, or intrusions.




1. #### User Control
Users can take immediate action by interacting with the system through the mobile app. The app provides buttons or controls for functionalities like silencing alarms or acknowledging alerts.

1. #### Bluetooth Connectivity
The app establishes, maintains, and monitors the Bluetooth connection with the HC-05 module, ensuring a stable link for continuous communication.

1. ## <a name="_toc155089007"></a><a name="_toc155099204"></a>Functionality in Action

1. ### <a name="_toc155099205"></a>Bluetooth Pairing Process
Users initiate the Bluetooth pairing process within the app, selecting the HC-05 module from available devices, and establishing a secure connection.

1. ### <a name="_toc155099206"></a>Receiving and Displaying Alerts
Upon detecting a hazard, the Li-Fi Hazard Detection System sends alerts via the HC-05 Bluetooth module. The app receives and displays these alerts, keeping users informed.

1. ### <a name="_toc155099207"></a>User Interaction
The app allows users to interact with the system by sending commands through the Bluetooth module. For instance, users can mute alarms or acknowledge alerts using the app's interface.

1. ## <a name="_toc155089008"></a><a name="_toc155099208"></a>Steps

1. ### <a name="_toc155089009"></a><a name="_toc155099209"></a>Application on play store
![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.028.jpeg)

<a name="_toc155098680"></a>*Figure 15: MIT App in play store*

1. ### <a name="_toc155089010"></a><a name="_toc155099210"></a>Open application
![A cell phone with a white screen

Description automatically generated](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.029.png)

<a name="_toc155098681"></a>*Figure 16: MIT App Home Screen*


1. ### <a name="_toc155089011"></a><a name="_toc155099211"></a>Connect to Bluetooth
![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.030.png)

<a name="_toc155098682"></a>*Figure 17: Bluetooth Connection*
1. ### <a name="_toc155089012"></a><a name="_toc155099212"></a>Initializing global list with mapping each item to its block
![A computer screen shot of a computer program

Description automatically generated with medium confidence](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.031.jpeg)

<a name="_toc155098683"></a>*Figure 18: Initializing global list and Splitting list sent items at “, " and maps each item to its block.*
1. ### <a name="_toc155099213"></a>Mobile Application Features & Screen
![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.032.png)

<a name="_toc155098684"></a>*Figure 19: Mobile Application Features*


1. # <a name="_toc155099214"></a>Flowchart of the main flow of the program
![](Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.033.png)

<a name="_toc155098685"></a>*Figure 20: Main Program Flow Chart*


1. # <a name="_toc155099215"></a>Problems Faced and Solutions:

**Problem:**

- Connecting sender and receiver through light, used PWM to control LED output intensity.

**Solution**:

- Employed PWM (Pulse Width Modulation) to control the intensity of the LED, facilitating communication between the sender and receiver via light.

**Problem:**

- Using Split timers on Timer 0, solution involved utilizing both Timer 0 and Timer 2.

**Solution:**

- Effectively employed Timer 0 and Timer 2 for split timer functionality, optimizing the use of timers in the embedded system.

**Problem:**

- Integrating all sensors in the main system, solution provisioned a timer. When its interrupt elapses, all sensors are checked, and flags are raised for sensors surpassing the threshold.

**Solution:**

- Integrated all sensors into the main system, implementing a timer-based solution. Upon interrupt, the system checks all sensors, raising flags for those surpassing the threshold.

**Problem:**

- Using blocking delays, solution involved using SysTick interrupts to produce non-blocking delays.

**Solution:**

- Overcame the issue of blocking delays by implementing SysTick interrupts, ensuring non-blocking delays in the embedded system.
20

[ref1]: Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.001.png
[ref2]: Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.002.jpeg
[Ultrasonic Sensor Module – Future Electronics Egypt]: Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.015.jpeg
[ref3]: Aspose.Words.41a30f1d-6cb4-4bf6-88d9-5aaa7a8c7e22.023.png
