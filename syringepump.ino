#include <Key.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>
LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
#define Password_Length 5
char Data[Password_Length];
char Master1[Password_Length] = "1000";
char Master2[Password_Length] = "2000";
char Master3[Password_Length] = "3000";
char Master4[Password_Length] = "4000";
char Master5[Password_Length] = "5000";
char Master6[Password_Length] = "6000";
byte data_count = 0, master_count = 0;

char customKey;
boolean flag = 0;


const int motor1Pin1 = 8;
const int motor1Pin2 = 9;

char keys[ROWS][COLS] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = { 10, 2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 6, 7}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("WELCOME");
  delay(500);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  lcd.init();
  lcd.backlight();
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  enter();
}

void motoron()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
}
void motoron1()
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
}
void motoroff()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
}

void enter()
{
  customKey = keypad.getKey (); // Create a variable named key of type char to hold the characters pressed
  if (customKey)
  { // if the key variable contains
    Serial.println (customKey); // output characters from Serial Monitor
    delay(200);
  }
lcd.setCursor(0,0);
lcd.print("Enter \"ml\"");
  if (customKey) {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    delay(200);
    Serial.println (Data[data_count]);
    delay(200);
    data_count++;
  }

  if (data_count == Password_Length - 1)
  {
    lcd.clear();
    delay(200);
    if (!strcmp(Data, Master1) ) {

      lcd.print("1ml");
      motoron();
      delay(1000);
      motoron1();
      delay(1000);
      motoroff();
      Serial.println ("1ml");
      delay(1000);
      flag = 1;
    }
    
    else if (!strcmp(Data, Master2) ) {
      lcd.print("2ml");
      motoron();
      delay(1500);
      motoron1();
      delay(1500);
      motoroff();
      Serial.println ("2ml");
      delay(1000);
      flag = 1;
    }

    else if (!strcmp(Data, Master3) ) {
      lcd.print("3ml");
      motoron();
      delay(2000);
      motoron1();
      delay(2000);
      motoroff();
      Serial.println ("3ml");
      delay(1000);
      flag = 1;
    }

    else if (!strcmp(Data, Master4) ) {
      lcd.print("4ml");
      motoron();
      delay(2500);
      motoron1();
      delay(2500);
      motoroff();
      Serial.println ("4ml");
      delay(1000);
      flag = 1;
    }
    
    else if (!strcmp(Data, Master5) ) {
      lcd.print("5ml");
      motoron();
      delay(3000);
      motoron1();
      delay(3000);
      motoroff();
      Serial.println ("5ml");
      delay(1000);
      flag = 1;
    }
    
    else if (!strcmp(Data, Master6) ) {
      lcd.print("6ml");
      motoron();
      delay(3200);
      motoron1();
      delay(3200);
      motoroff();
      Serial.println ("6ml");
      delay(1000);
      flag = 1;
    }

    else  {
      lcd.print("InCorrect");
      delay(500);
      Serial.println ("InCorrect");
      delay(200);
      flag = 0;
    }
    lcd.clear();
    clearData();
  }
}

void clearData()
{
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}
