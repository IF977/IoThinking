#include <SD.h>
#include <SPI.h>
#include <Ethernet.h>

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;
const int chipSelect = 4;

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

//Para conexão com a shield ethernet eu preciso capturar o ip, gateway e subnet 
//Rede Casa
//ip: 192,168,25,36
//gateway: 192,168,25,1
//subnet: 255,255,255,0

//Rede BEPiD
//ip:172,16,1,197
//gateway:172,16,0,1
//subnet:255,255,0,0

IPAddress ip(172,16,2,53);
IPAddress gateway(172,16,0,1);
IPAddress subnet(255,255,0,0);

//O servidor que eu quero usar no método GET
char server[] = "http://theiothinking.herokuapp.com";
unsigned long ltmillis, tmillis, timems, previousMillis;


//Status de internet 
EthernetClient client;

void setup() {

 
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print("Initializing SD card...");

  if(!SD.begin(chipSelect)){
    Serial.println("Card failed, or not present");
    return;
  }

  
  
  Serial.println("Card initialized");
  //Ethernet.begin(mac, ip);
  previousMillis = millis();

  emon1.current(1, 61.1);             // Current: input pin, calibration.
  /*// start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");

  */
}

void loop() {

  ltmillis = tmillis;
  tmillis = millis();
  timems = tmillis - ltmillis;
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  float kwhTotal =  (((Irms*127.0)/1000.0) * 1.0/3600.0 * (timems/1000.0));

  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  
      dataFile.println(kwhTotal);
      dataFile.close();
      sendGET(kwhTotal);
   
  // if there are incoming bytes available
  // from the server, read them and print them:
  /*if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }*/
  
  /*// if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }*/
}

void sendGET(float kwhTotal)
{
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    //client.println("GET /search?q=arduino HTTP/1.1");
    //client.println("Host: www.google.com");
    char corrente[10];
    String current;
    dtostrf(kwhTotal,1,5,corrente);
    String valor = String (corrente);
    Serial.println(valor);
    client.println("GET /ambientes/?leitura="+valor+"  HTTP/1.1");
    client.println("Host: http://theiothinking.herokuapp.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

  while(client.connected() && !client.available()) delay(1); //waits for data
  while (client.connected() || client.available()) { //connected or data available
    char c = client.read(); //gets byte from ethernet buffer
    Serial.print(c); //prints byte to serial monitor 
  }

  Serial.println();
  Serial.println("disconnecting.");
  Serial.println("==================");
  Serial.println();
  client.stop(); //stop client

}
