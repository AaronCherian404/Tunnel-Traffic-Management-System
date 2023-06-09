#include <SD.h>

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#define FIREBASE_HOST "nodemcu-350de-default-rtdb.firebaseio.com"                     // the project name address from firebase id
#define FIREBASE_AUTH "89AYqHsTaIBDgduUmiz9VH3POABj6KXSaXgYQaJe"                              // the secret key generated from firebase
                                  
const char* WIFI_SSID = "oplus_co_aptste"; //--> Your wifi name or SSID.
const char* WIFI_PASSWORD  = "rjwr4640"; //--> Your wifi password.
FirebaseData firebaseData;
int val;                                             // led status received from firebase


void setup() {
  Serial.begin(115200);
  delay(1000); 
  pinMode(LED_BUILTIN, OUTPUT);                 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  // try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);}
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                        // print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                          // connect to firebase
}

void loop() {
  Firebase.getInt(firebaseData, "LED"); 
  val = firebaseData.intData();   
  Serial.println(val);// get ld status input from firebase
  if (val==1) {                                             // compare the input of led status received from firebase
    Serial.println("Led Turned ON");                         
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);// make external led ON
  } 
  else if (val==0) {                                       // compare the input of led status received from firebase
    Serial.println("Led Turned OFF");
    digitalWrite(LED_BUILTIN, HIGH);                                   // make external led OFF
    delay(3000);
  }
 
  else  { 
      Serial.print("Getting /Value failed :");
     
  }
}