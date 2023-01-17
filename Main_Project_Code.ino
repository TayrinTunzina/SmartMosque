

//Tech Trends Shameer
//Automatic Door Opening using IR Sensor

#include <Servo.h>

//Door
Servo tap_servo;
int sensor_pin = 4;
int tap_servo_pin =5;
int val;
//window(rain sensor)
Servo tap_servo2;
int sensor_pin2 = 3;
int tap_servo_pin2 =6;
int val2;

//Buzzer
int buzzer = 9;

void setup(){
  
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
   Serial.begin(9600);

     pinMode(sensor_pin2,INPUT);
  tap_servo2.attach(tap_servo_pin2);

   pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);

  pinMode(9,OUTPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
//buzzer
pinMode(buzzer, OUTPUT);
  

}

void loop(){
  val = digitalRead(sensor_pin);
  Serial.println(val);
  if (val==0)
  {
    tap_servo.write(0);
    delay(5000);
    tap_servo.write(90);
  }
  /*if (val==1)
  {
    tap_servo.write(180);
    
  }*/
   val2 = digitalRead(sensor_pin2);

  if (val2==0)
  {tap_servo2.write(0);
  }
  if (val2==1)
  {tap_servo2.write(90);
  
    }
   
     if (digitalRead(10)== LOW)
  {
    digitalWrite(9,HIGH);
    Serial.println("on");

  
 }
  else 
  {
    
    digitalWrite(9,LOW);
   Serial.println("off");

  }

  //irled
  if (digitalRead(7)== LOW)
  {
    digitalWrite(9,HIGH);
    
    delay(10);
  }
  else 
  {
    
    digitalWrite(9,LOW);
    delay(10);
  }
}
