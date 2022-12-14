#include <Servo.h>
#include <cvzone.h>

SerialData serialData(1,1);
int valsRec[1];

int laser1 = 10;
int laser2 = 11;

Servo head;
Servo back;
Servo right_arm;
Servo left_arm;
Servo right_bow;
Servo left_bow;
Servo right_w;
Servo left_w;


void setup() {
   Serial.begin(9600);
   head.attach(7);
  back.attach(8);
  left_arm.attach(9);
  right_arm.attach(2);
  left_bow.attach(3);
  right_bow.attach(4);
  left_w.attach(5);
  right_w.attach(6);
   pinMode(laser1, OUTPUT);
   pinMode(laser2, OUTPUT);
   shoulder_open();
   delay(1000);
   shoulder_close();
   delay(1000);
   //angry();
   
}

void loop() {
     //dance();
     serialData.Get(valsRec);
     if(valsRec[0] == 1){
      dance();
     }
     else if(valsRec[0] == 2){
      happy();
     }
     else if(valsRec[0] == 3){
      angry();
     }
  
}

void angry(){
  shoulder_open();
  move(right_bow, 1000);
  move(left_bow, 2000);
  delay(600);
  move(right_bow, 1500);
  move(left_bow, 1500);
  delay(500);
  move(left_w, 2000);
   move(right_w, 1000);
   delay(200);
   move(left_w, 1500);
   move(right_w, 1500);
   delay(500);
   move(right_bow, 2000);
  move(left_bow, 1000);
  delay(400);
  move(right_bow, 1500);
  move(left_bow, 1500);
  delay(500);
  move(right_w, 2000);
   move(left_w, 1000);
   delay(200);
   move(left_w, 1500);
   move(right_w, 1500);
  shoulder_close();

}

void happy(){
    move(left_arm, 2000);
    move(right_arm, 1000);
    delay(700);
    move(left_arm, 1500);
    move(right_arm, 1500);
    delay(500);
    move(left_bow, 2000);
    move(right_bow, 1000);
    delay(200);
    move(left_bow, 1500);
    move(right_bow, 1500);
    delay(500);
    move(left_arm, 1000);
    move(right_arm, 2000);
    delay(500);
    move(left_arm, 1500);
    move(right_arm, 1500);
    delay(500);
    move(left_bow, 1000);
    move(right_bow, 2000);
    delay(200);
    move(left_bow, 1500);
    move(right_bow, 1500);
}

void dance(){
   move(left_arm, 2000);
   move(right_arm, 1000);
   delay(300);
   move(left_arm, 1500);
   move(right_arm, 1500);
   delay(500);
   move(right_bow, 1000);
   move(left_bow, 2000);
   delay(300);
   move(left_bow, 1500);
   move(right_bow, 1500);
   delay(500);
   move(left_w, 2000);
   move(right_w, 1000);
   delay(200);
   move(left_w, 1500);
   move(right_w, 1500);
   delay(100);
   move(head, 1000);
   delay(250);
   move(head, 2000);
   delay(450);
   move(head, 1000);
   delay(250);
   move(head, 1500);
   delay(500);
   move(left_bow, 1000);
   move(right_bow, 2000);
   delay(250);
   move(left_bow, 1500);
   move(right_bow, 1500);
   delay(500);
   move(left_w, 1000);
   move(right_w, 2000);
   delay(200);
   move(left_w, 1500);
   move(right_w, 1500);
   delay(500);
   move(left_arm, 1000);
   move(right_arm, 2000);
   delay(200);
   move(left_arm, 1500);
   move(right_arm, 1500);
   delay(500);

}

void shoulder_open(){
   move(back, 1000);
   delay(300);
   move(back, 1500);
   digitalWrite(laser1, HIGH);
   digitalWrite(laser2, HIGH);
   delay(500);
}

void shoulder_close(){
   digitalWrite(laser1, LOW);
   digitalWrite(laser2, LOW);
   move(back, 2000);
   delay(300);
   move(back, 1500); 
   delay(500);
}

void move(Servo s, int position) {
   /*Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   Serial.print(" T");
   Serial.println(1);
   delay(1);*/
   if(position == 1500){
    s.write(90);
   }
   else if(position == 1000){
    s.write(45);
   }
   else if(position == 2000){
    s.write(135);
   }
   //s.detach();
}
