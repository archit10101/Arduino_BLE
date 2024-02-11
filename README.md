## Arduino BLE

This Arduino code is designed to facilitate the control of Electric Muscle Stimulation (EMS) devices via Bluetooth Low Energy (BLE) communication. The code allows adjustment of three key properties: intensity, frequency, and pulse width, as well as triggering the start command. This can easily be editted to fit any purpose.

### Instructions:

1. **Install ArduinoBLE Library**: Make sure you have the `ArduinoBLE` library installed in your Arduino IDE. You can install it via the Library Manager in the Arduino IDE.

2. **Setup the BLE Service and Characteristics**: The code sets up a BLE service and four characteristics for intensity, pulse width, frequency, and start command. Ensure that the UUIDs for the service and characteristics match your requirements.

3. **Pairing with Smartwatch**: Pair your Android smartwatch with the Arduino device.

4. **Edit the UUIDs**: If necessary, edit the UUIDs in the code to match your specific requirements.

5. **Uploading the Code**: Upload the code to your Arduino board.

6. **Usage**: Use the Android EMS Calibration Control App to adjust the intensity, frequency, and pulse width settings. The changes made in the app will be reflected in the Arduino code through BLE communication.

### Code Explanation:

- The code initializes the BLE service and characteristics required for EMS control.
- It continuously listens for incoming BLE data from the connected device (smartwatch).
- Upon receiving data for intensity, frequency, pulse width, or start command, it prints the received values to the serial monitor.

### Note:

- Ensure that the Bluetooth module on your Arduino device is compatible with Bluetooth Low Energy (BLE).
- Customize the code as per your requirements, especially the UUIDs and any additional functionality needed.

**Disclaimer**: Use this code responsibly and at your own risk.

---

Feel free to modify and enhance the code according to your project's needs. If you have any questions or suggestions, please don't hesitate to reach out.
