import serial
import time

def send_at_command(command):
    ser.write(command.encode('utf-8'))
    time.sleep(0.1)  # Add a short delay to allow the module to process the command
    response = ser.readline().decode('utf-8')
    return response.strip()

try:
    # Open the serial port
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)  # Replace with your actual serial port and baud rate

    # Send AT command to check communication with the LoRa module
    response = send_at_command('AT\r\n')
    print('Response to AT command:', response)

    # Set LoRa module to receive mode
    response = send_at_command('AT+MODE=1\r\n')
    print('Response to MODE command:', response)

    # Send data through LoRa module
    data_to_send = "Hello, LoRa!"  # Replace with the data you want to send
    response = send_at_command('AT+SEND=' + data_to_send + '\r\n')
    print('Response to SEND command:', response)

    # Wait for response from LoRa module
    time.sleep(1)  # Adjust the time as needed based on the expected response time

    # Read the received data from LoRa module
    response = send_at_command('AT+RECV\r\n')
    print('Received data:', response)

except serial.SerialException as e:
    print('Serial Port Error:', str(e))

except Exception as e:
    print('Error:', str(e))

finally:
    # Close the serial port when done
    if ser.is_open:
        ser.close()
