// Libraries
#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
// Request URL
String URL = "http://192.168.0.2/mq7Data/test_data.php";
// WiFi Information
const char* ssid = "IZZI-4579"; 
const char* password = "3C0461014579"; 
//3C0461014579

// Variables
int R2 = 2000;  
float RS_gas = 0;
float ratio = 0;
float sensorValue = 0;
float sensor_volt = 0;
float R0 = 7200.0;

// Setup Function
void setup() {
  Serial.begin(115200); 
  // Serial.setDebugOutput(true);
  // ESP.eraseConfig();
  // delay(1000);
  // WiFi.disconnect();
  // delay(1000);
  // delay(4000);
  // WiFi.persistent(false);
  // Connecting to Wifi
  WiFi.mode(WIFI_OFF);
  delay(200);
  WiFi.mode(WIFI_STA);
  delay(2000);

  WiFi.begin(ssid, password);
  WiFi.printDiag(Serial);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

// Loop
void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    // Reading Sensor
  int ppm = analogRead(A0);
  
  Serial.print("PPM: ");
  Serial.println(ppm);
  
  String postData = "ppm=" + String(ppm); 

  // Initializing Request to HTTP Server
  WiFiClient client;
  HTTPClient http; 
  http.begin(client, URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Reading Response
  int httpCode = http.POST(postData); 
  String payload = http.getString(); 
  // Printing esponse
  Serial.print("URL : "); Serial.println(URL); 
  Serial.print("Data: "); Serial.println(postData); 
  Serial.print("httpCode: "); Serial.println(httpCode); 
  Serial.print("payload : "); Serial.println(payload); 
  Serial.println("--------------------------------------------------");
  delay(10000);
}

// Connecting to Wifi Function
void connectWiFi() {
  // WiFi.mode(WIFI_OFF);
  // delay(1000);
  // //This line hides the viewing of ESP as wifi hotspot
  // WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

