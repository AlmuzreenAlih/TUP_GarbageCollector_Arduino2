#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); // TX Pin, RX Pin

#define StartButton A1
#define StopButton 13
#define GreenLed 5
#define RedLed 6

#define joyX A2
#define joyY A3

#include <millisDelay.h>
millisDelay Timer1;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600); delay(100);
    //Buttons
    pinMode(StartButton, INPUT_PULLUP);                           
    pinMode(StopButton, INPUT_PULLUP);
    pinMode(joyX, INPUT);
    pinMode(joyY, INPUT);
    //Relays
    pinMode(GreenLed, OUTPUT); digitalWrite(GreenLed, LOW);
    pinMode(RedLed, OUTPUT); digitalWrite(RedLed, HIGH);

    // while (1) {
    //     if (mySerial.available()) {break;}
    // } //wait for recvr here...

    digitalWrite(RedLed, LOW);
    Timer1.start(5000);
    // lcd.init();
    // lcd.backlight();
    Serial.println("Initialized!");
}

int Motion = 0;
int xValue;
int yValue;

char receivedChar;
void loop() {

    if (Timer1.justFinished()) {digitalWrite(RedLed, HIGH);}
    if (mySerial.available()) {
        receivedChar = mySerial.read();
             if (receivedChar == 'A') {Serial.print("A");}
        else if (receivedChar == '2') {}
        else if (receivedChar == '3') {}
        else if (receivedChar == '4') {}
    }
    receivedChar = ' ';
    
    // if (digitalRead(StartButton) == LOW) {
    //     int Counter = 0;
    //     while (1) {
    //         Counter++;
    //         delay(100);
    //         if (digitalRead(StartButton) == HIGH) {break;}
    //         if (Counter > 5) {break;}

    //     }
    //     if (Counter > 4) {mySerial.print("1"); digitalWrite(GreenLed, HIGH);}
    //     else             {mySerial.print("0"); digitalWrite(GreenLed, HIGH);}

    //     }
    // if (digitalRead(StopButton) == LOW)  {mySerial.println("Stop"); digitalWrite(GreenLed, LOW);}

    xValue = analogRead(joyX);
    yValue = analogRead(joyY);

    //      if ((xValue < 30  ) && (yValue > 1000)) {if (Motion != 5) {Motion = 5; mySerial.print('Z');}}
    // else if ((xValue > 1000) && (yValue > 1000)) {if (Motion != 6) {Motion = 6; mySerial.print('X'); }}
         if (yValue > 1000) {if (Motion != 4) {Motion = 4; mySerial.print('B'); DBG("B");}}
    else if (xValue < 30)   {if (Motion != 2) {Motion = 2; mySerial.print('R'); DBG("R");}}
    else if (xValue > 1000) {if (Motion != 3) {Motion = 3; mySerial.print('L'); DBG("L");}}
    else if (yValue < 30)   {if (Motion != 1) {Motion = 1; mySerial.print('F'); DBG("F");}}
    else if (digitalRead(StartButton) == LOW)   {if (Motion != 5) {Motion = 5; mySerial.print('C'); DBG("C");}}
    else                    {if (Motion != 0) {Motion = 0; 
    delay(20);
    if (digitalRead(StartButton)==HIGH) {
        mySerial.print('S'); 
    }
    DBG("S");}}
}


void ToggleLH(long delayings, int relayName) {
    digitalWrite(relayName, LOW); delay(delayings);
    digitalWrite(relayName, HIGH);
}

void ToggleHL(long delayings, int relayName) {
    digitalWrite(relayName, HIGH); delay(delayings);
    digitalWrite(relayName, LOW);
}

void RelayLOWwithLimit(int relayName, int MSName) {
    if (digitalRead(MSName) == 1){
        digitalWrite(relayName, LOW); delay(50);
        while(1) {if (digitalRead(MSName) == 0) {break;}}
        digitalWrite(relayName, HIGH);
    }
}

void LCDprint(int x, int y, String z) {
    lcd.setCursor(x,y); lcd.print(z);
}

void LCDClear() {
    LCDprint(0,0,"					");
    LCDprint(0,1,"					");
    LCDprint(0,2,"					");
    LCDprint(0,3,"					");
}
int debug = 1;
void DBG(String str) {
    if (debug) {Serial.println(str);}
}