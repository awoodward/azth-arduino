#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {12, 5, 6, 10}; 
byte colPins[COLS] = {11, 7, 9}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

bool timerActive;
unsigned long timerLength;
unsigned long startTime;
unsigned long duration;
String solution;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  timerLength = 1;     // Default to 1 minutes
  timerActive = false;  // Timer in inactive state

  displayHome();

  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nMatrix Scanner");
}

void displayHome()
{
  solution = String(""); 
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.display();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("C0FFEE OR DECAF?");
  lcd.setCursor(0,1);

  startTimer();
}

void hideDisplay()
{
      lcd.noBacklight();
      lcd.noDisplay();  
}

void displaySolution()
{
  lcd.clear();
  lcd.display();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("BEEF");
  lcd.setCursor(0,1);

  // count down to clearing the display
  for (int i=4; i > 0; i--){
    lcd.print(String(i) + "..");
    delay(1000);
  }
  timerActive=false;
  hideDisplay();
}

void displayMakeThat(String text){
  lcd.setCursor(0,0);
  lcd.print(text);
  lcd.setCursor(0,1);
  for (int i=3; i > 0; i--){
    lcd.print(".. ");
    delay(1000);
  }
  displayHome();
}

void startTimer()
{
  timerActive = true;       
  // Record the start time in milliseconds
  startTime = millis();     
  // Calculate duration to activate timer for in milliseconds
  // Calculation will be using unsigned long aritmatic 
  // as first argument is an unsigned long
  duration = 30 * 1000;  
}

void loop()
{
  while(timerActive) {
    // Display is visible
    char customKey = customKeypad.getKey();
    
    if (customKey){
      Serial.println(customKey);
      // restart the timer since user hit a key
      startTimer();
      
      if (isDigit(customKey)){
        // add digit to the solution
        //lcd.print(customKey);
        lcd.print("*");
        solution += customKey;
      } else {
        // * or # is enter key
        Serial.println(solution); 
        lcd.clear();
        delay(500);
        if (solution == "13500399") {
          displaySolution(); 
        } else {
          delay(1000);
          if (solution == "") {
            displayMakeThat("Enter order.");
          } else {
            displayMakeThat("Not found.");            
          }
          
          //Serial.println(12648430 | 912559);
          displayHome();
        }
      }
    }
    
    if(millis() - startTime > duration) {
      timerActive = false;
      hideDisplay();
      Serial.println("Timeout");
    }
  }
  while(!timerActive) {
    char customKey = customKeypad.getKey();
    
    if (customKey){
      Serial.println(customKey);
      displayHome();
    }
    
  }
}
