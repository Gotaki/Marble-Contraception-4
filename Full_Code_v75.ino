#include <Adafruit_TiCoServo.h>
#include <known_16bit_timers.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        3
#define NUMPIXELS 6
#define DELAYVAL 500
#define extInt 2
#define sensor1 8
#define sensor2 5
#define sensor3 6
#define sensor4 11
#define sensor5 12
#define motor1 9
#define motor2 10
#define LEDpin 4 // used for debugging
#define LED1start 0
#define LED1stop 6 // 6 x LEDs ( From 0 to 5)
#define LED2start 0//6  
#define LED2stop 6//11
#define LED3start 0//12
#define LED3stop 6//17
#define LED4start 0//18
#define LED4stop 6//18
#define delay1 400 // delay for LED strip 1
#define delay2 200 // delay for LED strips 2 and 3
#define delay3 1 // delay for LED strip 4
#define lightTimeout 10000 
#define posClose1 0
#define posClose2 0
#define posOpen1 90
#define posOpen2 90
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int colourArray[12][3]={{255,0,0},{0,255,0},{0,0,255},{255,255,0},{255,0,255},{0,255,255}, {255,128,0},{255,0,128}, {128,255,0},{0,255,128},{0,128,255},{128,0,255}};
int showArray[766]={255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};

int flagS1=0;
int flagS2=0;
int flagS3=0;
int flagS4=0;
int flagS5=0;
long counter1=0;
int scenario1=0;
int LED1 =0;
int red1=0;
int blue1=0;
int green1=0;
int delta1=0;
long counter2=0;
int scenario2=0;
int LED2 =0;
int red2=0;
int blue2=0;
int green2=0;
int delta2=0;
long counter3=0;
int scenario3=0;
int LED3 =0;
int red3=0;
int blue3=0;
int green3=0;
int delta3=0;
long counter4=0;
int scenario4=0;
int LED4 =0;
int red4=0;
int blue4=0;
int green4=0;
int delta4=50;
int idx=0;
int idxRed=0;
int idxGreen=0;
int idxBlue=0;
long timeoutCounter=0;
int onFlag=0;
int gate1=0;
int gate2=0;
int scenario5=0;
int scenario6=0;
unsigned long time5=0;
unsigned long time6=0;
Adafruit_TiCoServo servo1;
Adafruit_TiCoServo servo2;
void setup() {
  pinMode (sensor1,INPUT);
  pinMode (sensor2,INPUT);
  pinMode (sensor3,INPUT);
  pinMode (sensor4,INPUT);
  pinMode (sensor5,INPUT);
  pinMode (motor1,OUTPUT);
  pinMode (motor2,OUTPUT);
  servo1.attach(motor1);
  servo2.attach(motor2);
  pinMode (LEDpin,OUTPUT);
  pinMode (extInt,INPUT_PULLUP);
  digitalWrite (8, LOW);
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  pixels.clear();
  pixels.show();
  attachInterrupt(digitalPinToInterrupt(extInt), readSensors, RISING);
  randomSeed(analogRead(0));
  servo1.write(posClose1);
  servo2.write(posClose2);
}

void readSensors(){
  flagS1=digitalRead(sensor1);
  flagS2=digitalRead(sensor2);
  flagS3=digitalRead(sensor3);
  flagS4=digitalRead(sensor4);
  flagS5=digitalRead(sensor5);
 }
void sequence1(){
  if ( counter1==0){
    switch (scenario1) {
      case 0:
        //flash all red
        for(int i=LED1start; i<=LED1stop; i++){
          pixels.setPixelColor(i, pixels.Color(255, 0, 0));
        }
        counter1=delay1;
        scenario1=1;
        break;
      case 1:
        //clear strip1
        for(int i=LED1start; i<=LED1stop; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        counter1=delay1;
        scenario1=2;
        LED1=LED1start;
        delta1=255/(LED1stop-LED1start+1);
        break;
      case 2:
        //Single LED Running light
        if (LED1<LED1stop){
          red1=255-delta1*(LED1-LED1start);
          green1=0+delta1*(LED1-LED1start);
          blue1=0;
        }
        else{
          red1=0;
          green1=255;
          blue1=0;
          scenario1=3;
        }
        pixels.setPixelColor(LED1, pixels.Color(red1,green1,blue1));
        if (LED1!=LED1start){
          pixels.setPixelColor(LED1-1, pixels.Color(0,0,0));
        }
        counter1=delay1;
        LED1++;
        break;
      case 3:
        //turn off strip1
        for(int i=LED1start; i<=LED1stop; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        counter1=delay1;
        scenario1=0;
        flagS1=0;
        break;
      
     
    }
    pixels.show();
  }
  else{
    counter1--;
  }
 
}
void sequence2(){
  int temp=0;
  if ( counter2==0){
    switch (scenario2) {
      case 0:
        //Initiate the sequence
        for(int i=LED2start; i<=LED2stop; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        counter2=1;
        scenario2=1;
        LED2=LED2start;
        break;
      case 1:
        //Running light up
        if (LED2<=LED2stop){
          temp=random(0,11);
          red2=colourArray[temp][0];
          green2=colourArray[temp][1];
          blue2=colourArray[temp][2];
        }
        
        if (LED2==LED2stop){
          scenario2=2;
        }
        pixels.setPixelColor(LED2, pixels.Color(red2,green2,blue2));
        
        counter2=delay2;
        LED2++;
        break;
      case 2:
        //Running light off
        if (LED2>=LED2start){
           pixels.setPixelColor(LED2, pixels.Color(0,0,0));
        }
        if (LED2==LED2start){
          scenario2=0;
          flagS4=0;
        }
        
        
        counter2=delay2;
        LED2--;
        break;
      
     
    }
    pixels.show();
  }
  else{
    counter2--;
  }
 
}
void sequence3(){
  int temp=0;
  if ( counter3==0){
    switch (scenario3) {
      case 0:
        //Initiate the sequence
        for(int i=LED3start; i<=LED3stop; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        counter3=1;
        scenario3=1;
        LED3=LED3start;
        break;
      case 1:
        //Running light up
        if (LED3<=LED3stop){
          temp=random(0,11);
          red3=colourArray[temp][0];
          green3=colourArray[temp][1];
          blue3=colourArray[temp][2];
        }
        
        if (LED3==LED3stop){
          scenario3=2;
        }
        pixels.setPixelColor(LED3, pixels.Color(red3,green3,blue3));
        
        counter3=delay2;
        LED3++;
        break;
      case 2:
        //Running light off
        if (LED3>=LED3start){
           pixels.setPixelColor(LED3, pixels.Color(0,0,0));
        }
        if (LED3==LED3start){
          scenario3=0;
          flagS5=0;
        }
        
        
        counter3=delay2;
        LED3--;
        break;
      
     
    }
    pixels.show();
  }
  else{
    counter3--;
  }
 
}  

void sequence4(){
  if ( counter4==0){
    switch (scenario4) {
      case 0:
        //Initialize
        for(int i=LED4start; i<=LED4stop; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        timeoutCounter=lightTimeout;
        counter4=1;
        scenario4=1;
        idx=0;
        break;
      case 1:
        //Run the light show
        if(idx==765){
          idx=0;
        }
        for(int i=LED4start; i<=LED4stop; i++){
          idxRed=(idx+(i-LED4start)*delta4)%765;
          idxGreen=(idx+510+(i-LED4start)*delta4)%765;
          idxBlue=(idx+255+(i-LED4start)*delta4)%765;
          red4=showArray[idxRed];
          green4=showArray[idxGreen];
          blue4=showArray[idxBlue];
          pixels.setPixelColor(i, pixels.Color(red4,green4,blue4));
        }
        timeoutCounter--;
        if (timeoutCounter==0){
          scenario4=2;
        }
        
        idx++;
        counter4=delay3;
        break;
      case 2:
        //turn off
        for(int i=LED4start; i<=LED4stop; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        onFlag=0;
        break;
      
    }
    pixels.show();
  }
  else{
    counter4--;
  }
 
}  
void sequence6(){
  switch (scenario6) {
      case 0:
        //Initialize 1 sec delay
        time6=millis();
        scenario6=1;
        break;
      case 1:
        // wait for one second
        if ((millis()-time6)>1000){
          scenario6=2;
          servo2.write(posOpen2);
          time6=millis();
        }
        break;
      case 2:
       // wait for one second and close the gate
       if ((millis()-time6)>1000){
        scenario6=0;
        flagS3=0;
        servo2.write(posClose2);
       }
       break;
  }       
}

void sequence5(){
  switch (scenario5) {
      case 0:
        //Initialize 1 sec delay
        time5=millis();
        scenario5=1;
        break;
      case 1:
        // wait for one second
        if ((millis()-time5)>1000){
          scenario5=2;
          servo1.write(posOpen1);
          time5=millis();
        }
        break;
      case 2:
       // wait for one second and close the gate
       if ((millis()-time5)>1000){
        scenario5=0;
        flagS2=0;
        servo1.write(posClose1);
       }
       break;
  }       
}

void loop() {
     
  if(onFlag==1){
    sequence4();
    
  }
  if (flagS1==1){
    sequence1();
    onFlag=1;
    timeoutCounter=lightTimeout;
  }
  
  if (flagS4==1){
    sequence2();
  }
    
  if (flagS5==1){
    sequence3();
  }
      
  if (flagS2==1){
    sequence5();
  }

  if (flagS3==1){
    sequence6();
  }
          
   pixels.show();
          
  

}
