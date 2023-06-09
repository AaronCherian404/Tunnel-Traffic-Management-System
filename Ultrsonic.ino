#define trigPin D1
#define echoPin D2
#define trigPin2 D3
#define echoPin2 D4


float duration1, distance1, duration2, distance2 ;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(trigPin,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(echoPin2,INPUT);
  Serial.begin(9600);
}

void loop()
{
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
  
duration1 = pulseIn(echoPin,HIGH); 
distance1 = (duration1/2)*0.0343; 
  
digitalWrite(trigPin2,LOW);
delayMicroseconds(2);
digitalWrite(trigPin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2,LOW);
  
duration2 = pulseIn(echoPin2,HIGH); 
distance2 = (duration2/2)*0.0343; 


Serial.println(distance1); 
Serial.println(distance2); 
if((distance1<=10) && (distance2<=10))
{ 
    Serial.println("Led Turned ON"); 
    digitalWrite(LED_BUILTIN, LOW);  
    delay(1000); 
 
}
else
{
    Serial.println("Led Turned OFF"); 
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(1000);
}

}
