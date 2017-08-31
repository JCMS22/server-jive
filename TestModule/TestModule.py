import socket
import time

testId = "0156b26ec53c8fd73d000100620009"
def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('localhost',6969))
    while(1):
        client.send(testId)
        response = client.recv(2048)
        if(len(response)):
            print response
        time.sleep(1)

if __name__ == "__main__":
    main()