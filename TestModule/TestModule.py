import socket
import time
import json
from pprint import pprint
import linecache
import datetime

'''The test module is a simple executable that connects to the server and validate each record in the JSON file'''
'''Module must be ran from the TestModule folder'''

testId = "0156b26ec53c8fd73d000100620009"
recordList = []
addressMap = {}
'''Only keep last record if duplicate elements. This will match the default STL implementation'''
with open("../JSON/registrations.json") as data_file:
    for i, line in enumerate(data_file):
        elem = json.loads(line)
        if elem["addressOfRecord"] in addressMap:
            newDt = datetime.datetime.strptime(elem["created"], '%Y-%m-%dT%H:%M:%S.%fZ')
            oldElemId = addressMap[elem["addressOfRecord"]]
            oldDt = datetime.datetime.strptime(recordList[oldElemId]["created"],'%Y-%m-%dT%H:%M:%S.%fZ')
            if newDt > oldDt:
                recordList[oldElemId] = elem
        else:
            recordList.append(elem)
            addressMap[elem["addressOfRecord"]] = len(recordList)-1



'''Parse the JSON list and check each individual record if it exists in the server'''
def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('localhost',6969))
    '''First send wrong input and check we receive \n'''
    client.send("3563452345235")
    emptyRes = client.recv(2048)
    if emptyRes != "\n":
        print "Server did not return an empty line on bad record address"
        exit()

    '''Validate server against JSON file'''
    for elem in recordList:
        client.send(elem["addressOfRecord"])
        response = client.recv(2048)
        rep = json.loads(response)
        if rep != elem:
            print "Record returned by server does not match :" + rep["addressOfRecord"]
            print rep
            print elem
            exit()
    print "Test executed successfully"


if __name__ == "__main__":
    main()