  int speed=0;
  int direction=0;
  int rawSpeed=0;
void setup() {

  Serial.begin(9600);//begin using serial monitor
  pinMode(A0,OUTPUT);//PIN OUT TO OC2
  pinMode(A1,OUTPUT);//PIN OUT TO OC1
  pinMode(A2,INPUT);//DIRECTIONAL INPUT
  pinMode(A3,INPUT);//SPEED INPUT FROM POT
  pinMode(A4,OUTPUT);//PINOUT TO OC3 
  pinMode(A5,OUTPUT);//PINOUT OT OC4
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
direction = digitalRead(A2);//setting direction variable
rawSpeed=analogRead(A3);//reading pot input
speed=(rawSpeed/4);//converting pot input into and output value
if(direction == HIGH){//setting motors to drive forward
  analogWrite(A1,speed);//controlling speed and direction in this pin
  analogWrite(A0,LOW);
}
if(direction == LOW){
   analogWrite(A1,LOW);//controlling speed and direction in this pin
  analogWrite(A0,speed);
}
}

}
