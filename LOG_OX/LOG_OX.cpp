#include "M5Cardputer.h"
#include <WiFi.h>
#include "M5Unified.h"
#include <FastLED.h>


char SSID[] = "-";
char PSWD[] = "";

const int menu_size = 3;

byte MAC[6];

// IP & IP gateway & IP subnet
IPAddress ip;
IPAddress gateway;
IPAddress subnet;

void setup() {
  M5Cardputer.begin();
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_GREEN);
  M5.Lcd.print("_____________________________ LOG.OX");
}

void loop(){
  M5.update();
  delay(500);
  M5.Lcd.print("CHECKING SSID, PWD \n");
  WiFi.begin(SSID, PSWD);
  delay(10000);

  unsigned long startAttemptTime = millis();

  // If not automatically logged into a network 
  // upon booting, a scanning for networks begins

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000)
  {
    delay(1000);
    // load icon
    M5.Lcd.print(".");
  }

  M5.Lcd.print("/n STATUS: /n");

  // Notify user on the status of the auto WiFi connection
  // whether logged in or not.

  if (WiFi.status() == WL_CONNECTED){
    M5.Lcd.print("CONNECTED \n");

    // IP of shield
    ip = WiFi.localIP();
    M5.Lcd.print("IP: ");
    M5.Lcd.print(ip);

    // MAC of shield
    WiFi.macAddress(MAC);
    M5.Lcd.print("\n MAC:");
    M5.Lcd.print(MAC[5], HEX);

    // GATEWAY IP of shield
    gateway = WiFi.gatewayIP();
    M5.Lcd.print("\n GATEWAY:");
    M5.Lcd.print(gateway);

    // SUBNET
    subnet = WiFi.subnetMask();
    M5.Lcd.print("\n SUBNET MASK : ");
    M5.Lcd.print(subnet);
  } else {
    M5.Lcd.print("\n NOT CONNECTED \n");
  }
  delay(5000);

  // Auto scan for networks and notify how many networks were found, if any
  int networks_found = WiFi.scanNetworks();

  if (networks_found == 0){
    delay(500);
    M5.Lcd.print("\n NETWORKS NONE \n");
    delay(1000);
  } else {
    delay(1000);
    // NUMBER of networks found
    M5.Lcd.print("\n NETWORKS FOUND: \n");
    M5.Lcd.print(networks_found);
  }
  delay(500);
}