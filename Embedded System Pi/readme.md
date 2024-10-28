A mock OS for an IoT system whose purpose is home light control.

This setups uses the computer USB port to establish a connection with a Raspberry Pi PICO, then use <i>Thonny</i> for Micropython interface to debug and code in real time.

Once the PICO is hooked up and program begun, it requests a password on the interface. After 3 attempts the user is locked out and alerted through the analog red LED and a print statement.

Should the user type the correct password, he is greeted on the screen, after which the user can click the buttons to turn lights on, off, and even check the temperature. Whichever button is pressed, the screen logs which one it was.
