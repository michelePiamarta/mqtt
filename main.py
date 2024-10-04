import paho.mqtt.client as mqtt
import json
import time
version = '3.1.1 '
serverIp = "192.168.5.81"
serverPort = 1886

client = mqtt.Client()

def on_connect(clients, userdata, flags, rc):
    client.subscribe("avi/hacker")

def on_message(clients, userdata, msg):
    print(msg.payload.decode())
    client.publish("avi/hacker", ":3")

client.connect(serverIp, serverPort,60)


client.on_connect = on_connect
client.on_message = on_message

client.loop_start()
time.sleep(1)
client.publish("avi/hacker", ":3")


while True:
    ...
