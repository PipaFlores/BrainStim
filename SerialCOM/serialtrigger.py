import serial
import time

## To be used with the BIOSEMI trigger interface

# Initialize serial port
serialport = serial.Serial("/dev/ttyUSB0", baudrate=115200) # change to the correct port

try:
    # Send binary value '00000001' (1 in decimal) once
    signal = bytes([1])  # Convert number 1 to bytes
    serialport.write(signal)  # Send the signal
    
    # Keep the program running to maintain the connection
    input("Press Enter to stop the signal...")

except KeyboardInterrupt:
    pass
finally:
    # Send 0 to turn off the signal before closing
    serialport.write(bytes([0]))
    serialport.close()
    print("Signal stopped")