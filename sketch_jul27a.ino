//IOT controlled LED using Google Firebase Console and ESP8266 NodeMCU
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define HOST "ledcontroller-d55c2.firebaseio.com"
#define AUTH "cC5VTRuQe9QRQnUMS9bgf658wdVFwm8dgncGvmrOCY"
#define WIFI_SSID "HTC Portable Hotspot 330F"
#define PASS "12345678"
String fireStatus="";
int led=D3;

void setup() {
 Serial.begin(9600);
 delay(1000);
 pinMode(LED_BUILTIN,OUTPUT);
 pinMode(led,OUTPUT);
WiFi.begin(WIFI_SSID,PASS);
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print(".");
  delay(500);
}
Serial.println("conneced to");
Serial.println(WIFI_SSID);
Serial.println(WiFi.localIP());
Firebase.begin(HOST,AUTH);
Firebase.setString("LED_STATUS","OFF");
}

void loop() {
fireStatus=Firebase.getString("LED_STATUS");
if(fireStatus=="ON")
{
  Serial.println("Led turned on");
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(led,HIGH);
}
else if(fireStatus=="OFF")
{
  Serial.println("LED turned off");
    digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(led,LOW);
}
else
{
   Serial.println("Wrong credentials"); 
}
}
