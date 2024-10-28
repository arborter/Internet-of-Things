
from machine import Pin
from time import sleep
from machine import ADC

led = Pin('LED', Pin.OUT)
led_ex = Pin(16, Pin.OUT)
button = Pin(15, Pin.IN, Pin.PULL_UP)
touch_pad = Pin(13, Pin.IN, Pin.PULL_UP)
temp = ADC(27)
led_green = Pin(17, Pin.OUT)
led_red = Pin(0 ,Pin.OUT)

correct = "pi"
chances = 3

while chances > 0:
    password = input("What is the password?")
    if password == correct:
        print("Access granted")
        led_green.on()
        sleep(.5)
        while True:
            if button.value() != 1:
                led.on()
                led_ex.on()
                print("LIGHTS ON. PRESSED. Temperature is {}".format(temp.read_u16()))
            elif touch_pad.value() == 1:
                touch_pad.toggle()
                led_ex.on()
                led_green.on()
                print("LIGHT ON. TOUCH PAD")
            else:
                led.off()
                led_ex.off()
                led_green.off()
                led_red.off()
            sleep(.5)
        break
    else:
        chances -= 1
        if chances > 0:
            led_red.on()
            sleep(.5)
            led_red.off()
            print("Wrong password. {} attempts left".format(chances))
        else:
            print("Access Denied")
            led.off()
            led_red.on()
            sleep(.5)
            led_red.off()