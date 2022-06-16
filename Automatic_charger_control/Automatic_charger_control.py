import psutil
import serial
import time
from datetime import datetime
import os
arduino = serial.Serial('COM6', 9600)
plugged = psutil.sensors_battery().power_plugged
reached_charged = False
count = None
start_time = time.time()
seconds = 12

now = datetime.now()
current_time = now.strftime("%H:%M:%S")
while 1:
    battery = psutil.sensors_battery()
    current_time = time.time()
    elapsed_time = current_time - start_time

    if elapsed_time > seconds:
        # print("okkkkkk")
        # arduino.write(b'0')
        arduino.write(b'1')
        time.sleep(7)
        plugged = psutil.sensors_battery().power_plugged
        if plugged is False:
            arduino.write(b'0')
        print(psutil.sensors_battery().power_plugged)
        start_time = time.time()

    if plugged is True:
        if battery.percent < 100:
            if battery.percent <= 90 and reached_charged is True:
                if count != 1:
                    print("Charge                True")
                    print("State                 Reached 100%")
                    print("count                 1")
                    print("Time                  " + str(now) + "\n")
                    arduino.write(b'1')
                    count = 1
            elif reached_charged is False:
                if count != 2:
                    print("Charge                True")
                    print("State                 Charging up")
                    print("count                 2")
                    print("Time                  " + str(now) + "\n")
                    # print("Charging: True")
                    arduino.write(b'1')
                    count = 2

        elif battery.percent == 100:
            reached_charged = True
            if count != 3:
                print("Charge                False")
                print("State                 Reached 100%")
                print("count                 3")
                print("Time                  " + str(now) + "\n")
                # print("Charging: False")
                arduino.write(b'0')
                count = 3

    elif plugged is False:
        if count != 0:
            print("Charge                False")
            print("State                 Unplugged")
            print("count                 0")
            print("Time                  " + str(now) + "\n")
            # print("Not Charging")
            arduino.write(b'0')
            count = 0



