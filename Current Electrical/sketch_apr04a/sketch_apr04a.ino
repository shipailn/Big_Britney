  int speed=0;
  int direction=0;
  int rawSpeed=0;
  int brake=0;
  
void setup() {

  Serial.begin(9600);//begin using serial monitor
  pinMode(A0,OUTPUT);//PIN OUT TO OC2
  pinMode(A1,OUTPUT);//PIN OUT TO OC1
  pinMode(1,INPUT);//DIRECTIONAL INPUT
  pinMode(A3,INPUT);//SPEED INPUT FROM POT1
  pinMode(A4,OUTPUT);//PINOUT TO OC3 
  pinMode(A5,OUTPUT);//PINOUT OT OC4
  pinMode(A6,INPUT);//BRAKE INPUT FROM POT2
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
direction = digitalRead(1);//setting direction variable
rawSpeed=analogRead(A3);//reading pot1 input
brake=analogRead(A2);//reading pot2 input
speed=(rawSpeed/4);//converting pot1 input into and output value
if(direction == HIGH){//setting motors to drive forward
  analogWrite(A1,speed);//controlling speed and direction of motor 1 in this pin
  analogWrite(A0,LOW);
  analogWrite(A4,speed);//controlling speed and direction of motor 2 in this pin
  analogWrite(A5,LOW);
}
if(direction == LOW){//setting motors to drive in reverse
  analogWrite(A1,LOW);//controlling speed and direction of motor 1 in this pin
  analogWrite(A0,speed);
  analogWrite(A4,LOW);//controlling speed and direction of motor 2 in this pin
  analogWrite(A5,speed);
}
if(brake > 20){//setting motors to hard stop
  analogWrite(A1,LOW);//controlling speed and direction of motor 1 in this pin
  analogWrite(A0,LOW);
  analogWrite(A4,LOW);//controlling speed and direction of motor 2 in this pin
  analogWrite(A5,LOW);
}

}
