
import socket


def fahrenheit_to_celsius(fahrenheit):
    celsius = (fahrenheit - 32) * (5/9)
    return celsius


server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


server_socket.bind(('192.168.234.9', 22))


server_socket.listen(1)
print("Hello!")
print("Collecting info from client...")

while True:
    connection, address = server_socket.accept()
    print("CONNECTED TO CLIENT!")

    temperature_in_fahrenheit = connection.recv(1024).decode()
    temperature_in_fahrenheit = float(temperature_in_fahrenheit)
    temperature_in_celsius = fahrenheit_to_celsius(temperature_in_fahrenheit)
    connection.send(str(temperature_in_celsius).encode())

    connection.close()

