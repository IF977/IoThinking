#include <SPI.h>
#include <Ethernet.h>

int LED_RED = 52;
int LED_WT = 48;

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

//Para conexão com a shield ethernet eu preciso capturar o ip, gateway e subnet 
IPAddress ip(192,168,1,14);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,0,0);

//O servidor que eu quero usar no método GET
char server[] = "http://engenharia-software-pedroclericuzi1.c9users.io";

//Status de internet 
EthernetClient client;

void setup() {

  //Pino e botao
  //pinMode(botao, INPUT_PULLUP);
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, LOW);
  
  //fim de Pino e botao
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  //Ethernet.begin(mac, ip);
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
  sendGET();
}

void sendGET()
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
    //http://projeto-engenharia-iothinking-pedroclericuzi1.c9users.io:8080/ambientes/4
    client.println("GET /ambientes/?leitura=valor HTTP/1.1");
    client.println("http://engenharia-software-pedroclericuzi1.c9users.io");
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
