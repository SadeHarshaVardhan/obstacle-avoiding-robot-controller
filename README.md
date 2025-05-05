# obstacle-avoiding-robot-controller

This project is an Arduino-based robot capable of both **autonomous obstacle avoidance** and **manual control** via a Bluetooth-enabled smartphone app created with MIT App Inventor.

## 🧰 Hardware Used
- Arduino Uno
- L298N Motor Driver
- HC-05 Bluetooth Module
- HC-SR04 Ultrasonic Sensor
- 2 DC Motors (with wheels)
- Battery Pack (9V or 12V)
- Jumper Wires, Chassis

## ⚙️ Modes

### 🔹 `auto-mode`
This mode enables the robot to **autonomously avoid obstacles** using the ultrasonic sensor. It’s a fully automated driving experience—just turn it on and watch it go!

### 🔹 `auto_self`
In this mode, the robot is controlled via the MIT App Inventor Bluetooth interface. You can **toggle between self control (manual RC-style)** and **auto obstacle-avoiding mode**. This hybrid setup allows it to function both as a smart autonomous robot and a fun RC toy.

## 🕹️ Bluetooth Commands
| Command | Action              |
|---------|---------------------|
| F       | Move Forward        |
| B       | Move Backward       |
| L       | Turn Left           |
| R       | Turn Right          |
| S       | Stop                |
| A       | Enable Auto Mode    |
| M       | Disable Auto Mode   |

## 📲 MIT App Inventor Controller
Create an app with buttons that send the characters above via Bluetooth.
- Connect the app to the HC-05 at 9600 baud.
- Use the buttons to control movement or switch modes.

## 🛠️ Setup
1. Wire the components according to the pin configuration in the Arduino sketch.
2. Upload the sketch to your Arduino Uno.
3. Pair your phone with the HC-05 module.
4. Open the MIT App, connect via Bluetooth, and control the robot.

## 📷 Prototype & MIT APP

![image](https://github.com/user-attachments/assets/074c1dc9-e92d-4718-8cc3-365972d45ce0)     

![WhatsApp Image 2025-05-05 at 12 04 43_3c572f65](https://github.com/user-attachments/assets/3a631f8c-9ad3-466e-a248-f552087f5115)
 
## 💻 Arduino Code

1.The complete Arduino code is available in the auto momde_car successful.ino file which is only auto mode.

2.The complete Arduino code is available in the auto_self.ino file which is both auto mode and self control 

  RC toy.you can control via MIT APP INVENTOR My_Robo_Controller.apk file.

## 📄 Documentation & Support
- You can refer to the provided documentation for setup and troubleshooting.
- For any questions or assistance, feel free to contact: **sade.harshavardhan@gmail.com**

