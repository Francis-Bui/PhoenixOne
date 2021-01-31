#include<SoftwareSerial.h>

#define IN1 5
#define IN2 4
#define IN3 3
#define IN4 2

#define RPIN 6
//#define EN1 6
//#define EN2 5

SoftwareSerial mySerial(0, 1);//RX, TX

String data;
int btVal;

void setup() 
{  
  //Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(RPIN, OUTPUT);
  //pinMode(EN1, OUTPUT);
  //pinMode(EN2, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  //analogWrite(EN1,63);
  //analogWrite(EN2,63);
  mySerial.begin(9600);
}

void loop()
{
 if(Serial.available())
 {
  {  
      data = Serial.read();
      //Serial.print(str);             
  } 
    
  Serial.println(data);    



/*  switch (data) 
   {
      case 1:                                
        //Serial.println("Forward");
        forward();
        break;

      case 2:                 
       //Serial.println("Reverse");
        reverse();
        break;

      case 3:         
       //Serial.println("Left");
        left();
        break;
        
      case 4:                     
        //Serial.println("Right");
        right();
        break;
        
      case 5:                                            
        //Serial.println("Stop");
        stoprobot();
        break;     
*/
       //case 6:   
       if(data == 'r'){                                         
        Serial.println("Relay");
        //relay();
        //;     
       }
  //}
 
                                                              
   if (mySerial.available() < 0)                              
    {
     //Serial.println("No Bluetooth Data ");          
    }
  
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stoprobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void relay()
{
  digitalWrite(RPIN, HIGH);
}
