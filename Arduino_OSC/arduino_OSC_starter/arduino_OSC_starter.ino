#include "secrets.h"

#include <WiFiNINA.h>
#include <WiFiUDP.h>
#include <OSCMessage.h>

WiFiUDP udp;

//enter your own IP address, separated by commas (NOT dots)
IPAddress myIP(10,23,11,192);
const int port = 8888; //pick any port # (above 8000 recommended)


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // if WiFi module doesn't work/exist
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true); //do nothing forever
  }

  //connect to WiFi network
  Serial.println("Connecting to WiFi");
  WiFi.begin(WiFiSSID, WiFiPass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
    WiFi.begin(WiFiSSID, WiFiPass);
  }
  Serial.println("\nWiFi connected!");
  
  digitalWrite(LED_BUILTIN, HIGH);
  
  udp.begin(8888);
  
}

void loop() {
  float num = .5; //get data from inputs (analog, accelerometer, sensors, etc.)
  
  //give your message an OSC address (must begin with "/")
  OSCMessage msg("/address"); 
  
  //you can also create multiple message objects with different OSC addresses
  
  msg.add(num); //add 1 (or more) data points to message
  //repeat as needed
  
  udp.beginPacket(myIP, port);
  msg.send(udp);
  udp.endPacket();
  msg.empty();

  //repeat with additional OSC messages
  
  delay(50);
}
