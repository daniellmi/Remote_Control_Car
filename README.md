# Remote control car

- Credits to Marcio Henrique Santos, Enzo Alves Cardoso, Alexandre de Souza, Daniel Victor de Macedo Leal from IFBA Jequié as the main creators of this project 
- Marcio Henrique the tutor, the project master developer and technician.

## 🛠 Technologies Used

- C++
- <Ultrasonic.h> library by Erick Simões
  
# Remote Control Car with Arduino and MIT App Inventor

This project is a remote control car built using an Arduino board and a custom Android app developed with MIT App Inventor. The app communicates with the car via Bluetooth, allowing full control of movement.

## 🚗 Features

- Control car movements: forward, backward, left, right, and stop
- Bluetooth communication between Arduino and Android device
- Simple and intuitive mobile interface
<img height=400 width=900 src = "https://github.com/user-attachments/assets/9032a2ee-54e3-4c02-9632-130c0872bd43"/>

## 🧰 Technologies Used

- **Arduino MEGA 2560** (or compatible)
- **L298N Motor Driver**
- **Bluetooth module HC-05**
- **MIT App Inventor** for Android app

<img width=600 height=500 src = "https://github.com/user-attachments/assets/daeb9b5a-21db-4b4e-9f87-7b6ac9f6ae4d"/>

## 📱 App Interface

The app includes buttons for each movement, connected to Bluetooth commands sent to the Arduino.

## 🧠 How It Works

1. The app connects to the HC-05 via Bluetooth.
2. User presses a button (e.g., Forward).
3. The app sends a character via Bluetooth (like `'F'` for forward).
4. The Arduino reads the command and activates the motors accordingly.



