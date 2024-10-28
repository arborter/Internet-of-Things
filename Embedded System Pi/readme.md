A mock OS for an IoT system whose purose is home light control.

This setups uses the computer USB port to establish a connection and then use the Thonny for Micropython interfacce to debug and code in real time.

Once the PICO is hooked up, the program requests a password on the Thonny interface. After 3 attempts the user is locked out and alerted through the analog red LED and a print statement.

A person can click on numerous analog inputs which dictate the power of lights. User can request the temperature through analog input, after which the temperature would appear on the interface.