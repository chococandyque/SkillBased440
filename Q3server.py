import random
import threading
import socket

quotes = ["“The best way to predict your future is to create it. - Abraham Lincoln",
"I have not failed. I've just found 10,000 ways that won't work. - Thomas Edison",
"Success is not final, failure is not fatal: It is the courage to continue that counts. - Winston Churchill",
"Don't watch the clock; do what it does. Keep going. - Sam Levenson"]


def handle_client(sockfd):
    quote = random.choice(quotes)
    sockfd.sendall(quote.encode())
    sockfd.close()

def main():

    bind_ip = "192.168.234.9"
    bind_port = 8888


    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((bind_ip, bind_port))


    server.listen(5)
    print("Listen on %s:%d for request" % (bind_ip, bind_port))


    while True:
        client, addr = server.accept()
        print("Accepting connection from %s" % str(addr))
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()
main()


