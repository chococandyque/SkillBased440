import socket

def main():

    server_ip = "192.168.234.9"
    server_port = 8888

    sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    sockfd.connect((server_ip, server_port))

    quote = sockfd.recv(1024)
    print("The best way to predict your future is to create it. - Abraham Lincoln ")
    print("--------------------------------------------------------------------------")
    print("Today quotes is -> %s" % quote.decode())


    sockfd.close()


main()
