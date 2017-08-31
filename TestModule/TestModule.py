import socket

testId = "01549c6d56040787f4000100620009"
def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('localhost',6969))
    client.send(testId)
    response = client.recv(2048)
    if(len(response)):
        print response

if __name__ == "__main__":
    main()