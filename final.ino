#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 22
#define COL_2 23
#define COL_3 24
#define COL_4 25
#define COL_5 26
#define COL_6 27
#define COL_7 28

#define COL_8 29

int button1=36;
int button2=38;
int control1;
int controlscore,controlheart,controlface=0;

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

//(1 = ON, 0 = OFF)

byte heart1[] = {B00110110,B01110111,B01111111,B01111111,B00111110,B00011100,B00001000,B00000000};
byte heart2[] = {B00000000,B00110110,B01111111,B01111111,B01111111,B00111110,B00011100,B00001000};
byte heart3[]={B00001000,B00000000,B00110110,B01111111,B01111111,B01111111,B00111110,B00011100};
byte heart4[]={B00011100,B00001000,B00000000,B00110110,B01111111,B01111111,B01111111,B00111110};
byte heart5[]={B00111110,B00011100,B00001000,B00000000,B00110110,B01111111,B01111111,B01111111};
byte heart6[]={B01111111,B00111110,B00011100,B00001000,B00000000,B00110110,B01111111,B01111111};
byte heart7[]={B01111111,B01111111,B00111110,B00011100,B00001000,B00000000,B00110110,B01111111};
byte heart8[]={B01111111,B01111111,B01111111,B00111110,B00011100,B00001000,B00000000,B00110110};

byte smile[]={B00000000,B00110110,B00110110,B00000000,B01111111,B01111111,B00111110,B00011100};
byte sad[]={B00000000,B00110110,B00110110,B00000000,B00111110,B01111111,B01100011,B01000001};
byte angry[]={B01000001,B00100010,B00010100,B00000000,B00111110,B01000001,B01000001,B00111110};
byte happy[]={B00000000,B00100010,B00010100,B00100010,B00000000,B01100011,B00111110,B00011100};

byte Aplus[]={B00100000,B01110000,B00101110,B00010001,B00010001,B00011111,B00010001,B00010001};
byte A[]={B00000000,B00011100,B00100010,B00100010,B00111110,B00100010,B00100010,B00000000};
byte Bplus[]={B00100000,B01110111,B00101001,B00001001,B00000111,B00001001,B00001001,B00000111};
byte B[]={B00011110,B00100010,B00100010,B00011110,B00100010,B00100010,B00100010,B00011110};
byte Cplus[]={B00100000,B01110000,B00101110,B00010001,B00000001,B00000001,B00010001,B00001110};
byte C[]={B00000000,B00011100,B00100010,B00000010,B00000010,B00100010,B00011100,B00000000};
byte F[]={B00111110,B00000010,B00000010,B00011110,B00000010,B00000010,B00000010,B00000010};

float timeCount,timeCount2,timeCount3 = 0;
int a,b,c;

void setup() {
    Serial.begin(9600);
    for (byte i = 2; i <= 9; i++){
    pinMode(i, OUTPUT);
    }
    for (byte i = 22; i <= 28; i++){
    pinMode(i, OUTPUT);
    }
    pinMode(36,INPUT);
    pinMode(38,INPUT);
}




void loop() {

delay(5);

int state1=digitalRead(button1);
int state2=digitalRead(button2);

if( state1 ==0 ){
  control1++;
  if(control1==3){
    control1=0;
  }
  delay(200);
}

if(control1==0){
  drawheart();
}
else if(control1==1){
  drawface();
}
else if(control1==2){
  drawscore();
}

//1번 버튼- 그림 종류 선택
//if(state2==0){
//  control2++;
//  if(control2==2){
//    control2=0;
//  }
//  delay(200);
//}

if(state2==0){
  if(control1==0){
    controlheart++;
    if (controlheart==2){
      controlheart=0;
    }
    delay(200);
  }
  else if(control1==1){
    controlface++;
    if (controlface==2){
      controlface=0;
    }
    delay(200);
  }
  else if(control1==2){
    controlscore++;
    if (controlscore==2){
      controlscore=0;
    }
    delay(200);
  }
}

//1번그림
if(controlheart==0 && control1==0){
  if (a==1){
    drawScreen(heart1); 
  }
  else if(a==2){
    drawScreen(heart2);
  }
  else if(a==3){
    drawScreen(heart3);
  }
  else if(a==4){
    drawScreen(heart4);
  }
  else if(a==5){
    drawScreen(heart5);
  }
  else if(a==6){
    drawScreen(heart6);
  }
  else if(a==7){
    drawScreen(heart7);
  }
  else if(a==8){
    drawScreen(heart8);
  }
  else{
  }
}
else if(controlheart==1 && control1==0){
   if (a==1){
    timeCount=0; 
  }
  else if(a==2){
    timeCount=40;
  }
  else if(a==3){
    timeCount=80;
  }
  else if(a==4){
    timeCount=120;
  }
  else if(a==5){
    timeCount=160;
  }
  else if(a==6){
    timeCount=200;
  }
  else if(a==7){
   timeCount=240;
  }
  else if(a==8){
    timeCount=280;
  }
  else{
  }
}

//2번그림
if(controlface==0 && control1==1){
  if (b==1){
    drawScreen(smile); 
  }
  else if(b==2){
    drawScreen(sad);
  }
  else if(b==3){
    drawScreen(angry);
  }
  else if(b=4){
    drawScreen(happy);
  }
  else{
    drawScreen(smile);
  }
}
else if(controlface==1 && control1==1){
   if (b==1){
    timeCount2=0; 
  }
  else if(b==2){
    timeCount2=40;
  }
  else if(b==3){
    timeCount2=80;
  }
  else if(b==4){
    timeCount2=120;
  }
  else{
  }
}

if(controlscore==0 && control1==2){
  if (c==1){
    drawScreen(Aplus); 
  }
  else if(c==2){
    drawScreen(A);
  }
  else if(c==3){
    drawScreen(Bplus);
  }
  else if(c==4){
    drawScreen(B);
  }
  else if(c==5){
    drawScreen(Cplus);
  }
  else if(c==6){
    drawScreen(C);
  }
  else if(c==7){
    drawScreen(F);
  }
  else{
  }
}
else if(controlscore==1 && control1==2){
   if (c==1){
    timeCount3=0; 
  }
  else if(c==2){
    timeCount3=30;
  }
  else if(c==3){
    timeCount3=60;
  }
  else if(c==4){
    timeCount3=90;
  }
  else if(c==5){
    timeCount3=120;
  }
  else if(c==6){
    timeCount3=150;
  }
  else if(c==7){
   timeCount3=180;
  }
  else{
  }
}

}
//2번 버튼

void drawscore(){
  timeCount3 += 1;
  
if(timeCount3 <  20) {
drawScreen(Aplus);
c=1;
} else if (timeCount3 < 30) {
  
} 
else if (timeCount3 < 50) {
drawScreen(A);
c=2;
} else if (timeCount3 < 60) {
//N
}
else if (timeCount3 < 80) {
drawScreen(Bplus);
c=3;
} else if (timeCount3 < 90) {
//N
}
else if (timeCount3 < 110) {
drawScreen(B);
c=4;
} else if (timeCount3 < 120) {
//N
}
else if (timeCount3 < 140) {
drawScreen(Cplus);
c=5;
} else if (timeCount3 < 150) {
//N
}
else if (timeCount3 < 170) {
drawScreen(C);
c=6;
} else if (timeCount3 < 180) {
//N
}
else if (timeCount3 < 200) {
drawScreen(F);
c=7;
} else if (timeCount3 < 210) {
//N
}
else {
// back to the start
timeCount3 = 0;
}
}


void drawface(){
  timeCount2 += 1;
  
if(timeCount2 <  30) {
drawScreen(smile);
b=1;
} else if (timeCount2 < 40) {
  
} 
else if (timeCount2 < 70) {
drawScreen(sad);
b=2;
} else if (timeCount2 < 80) {
//N
} 
else if (timeCount2<110){
  drawScreen(angry);
  b=3;
}
else if(timeCount2<120){
  
}
else if(timeCount2<150){
  drawScreen(happy);
  b=4;
}
else if(timeCount2<160){
  
}
else {
// back to the start
timeCount2 = 0;
}
}





void drawheart(){
  timeCount += 1;
if(timeCount <  30) {
drawScreen(heart1);
a=1;
} else if (timeCount < 40) {
} 
else if (timeCount < 70) {
drawScreen(heart2);
a=2;
} else if (timeCount < 80) {
//N
} 
else if (timeCount<110){
  drawScreen(heart3);
  a=3;
}
else if(timeCount<120){
  
}
else if (timeCount<150){
  drawScreen(heart4);
  a=4;
}
else if(timeCount<160){
  
}
else if (timeCount<190){
  drawScreen(heart5);
  a=5;
}
else if(timeCount<200){
  
}
else if (timeCount<230){
  drawScreen(heart6);
  a=6;
}
else if(timeCount<240){
  
}
else if (timeCount<270){
  drawScreen(heart7);
  a=7;
}
else if(timeCount<280){
  
}
else if (timeCount<310){
  drawScreen(heart8);
  a=8;
}
else if(timeCount<320){
  
}
else {
// back to the start
timeCount = 0;
}

}







void  drawScreen(byte buffer2[]){
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]); // Set columns for this specific row
        
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
    }
}








void setColumns(byte b) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
    
}
