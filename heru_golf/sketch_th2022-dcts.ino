#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'kingcharlescypher', 128x64px
// inverted bits
const unsigned char epd_bitmap_kingcharlescypher [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x7a, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x02, 0x0f, 0x8b, 0x0c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x05, 0xfc, 0xc1, 0xcc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x08, 0xf8, 0xf0, 0xec, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x78, 0xf1, 0xc0, 0x31, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x7c, 0xf0, 0x00, 0x19, 0x80, 0x00, 0x00, 
  0x06, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xc0, 0x3f, 0xf0, 0xe0, 0x0c, 0x00, 0x00, 0x00, 
  0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1, 0xe0, 0x3f, 0xf1, 0xf0, 0x06, 0x60, 0x00, 0x00, 
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xe0, 0x3f, 0xf0, 0x70, 0x03, 0x60, 0x00, 0x00, 
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xf0, 0x1e, 0x38, 0x7f, 0x81, 0x80, 0x00, 0x00, 
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x70, 0x1e, 0x1f, 0xff, 0x81, 0x98, 0x00, 0x00, 
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x38, 0x1e, 0x1f, 0xff, 0x00, 0xd8, 0x00, 0x00, 
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x38, 0x1e, 0x1f, 0xf0, 0x00, 0xc0, 0x00, 0x00, 
  0x03, 0x80, 0x00, 0x18, 0x00, 0x3f, 0xff, 0xc0, 0x18, 0x1e, 0x1c, 0x38, 0x00, 0x64, 0x00, 0x00, 
  0x06, 0x01, 0xc0, 0x18, 0x00, 0x00, 0x01, 0xc0, 0x1c, 0x0f, 0x1c, 0x38, 0x00, 0x6e, 0x00, 0x00, 
  0x00, 0x01, 0xc0, 0x18, 0x00, 0x00, 0x00, 0xc0, 0x1c, 0x0f, 0xf8, 0x78, 0x00, 0x24, 0x00, 0x00, 
  0x00, 0x01, 0x80, 0x18, 0x00, 0x00, 0x00, 0xc0, 0x1c, 0x0f, 0xf8, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x00, 0x03, 0x80, 0x18, 0x1f, 0xff, 0x00, 0xc0, 0x1c, 0x0f, 0xf8, 0xfc, 0x00, 0x08, 0x00, 0x00, 
  0x00, 0x03, 0x80, 0x18, 0x1f, 0xff, 0x00, 0xc0, 0x0c, 0x0f, 0xf8, 0x78, 0x00, 0xf8, 0x00, 0x00, 
  0x00, 0x03, 0x80, 0x38, 0x00, 0x01, 0x00, 0xc0, 0x0c, 0x0f, 0xbc, 0x38, 0xff, 0xe3, 0xc3, 0xc0, 
  0x00, 0x03, 0x80, 0x38, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x0f, 0x1e, 0x31, 0xb8, 0x07, 0xe1, 0x90, 
  0x00, 0x03, 0x80, 0x78, 0x18, 0x01, 0x00, 0xc0, 0x0c, 0x0f, 0x0f, 0xf7, 0x80, 0x4b, 0xfd, 0xb0, 
  0x00, 0x03, 0x80, 0x78, 0x1f, 0xff, 0x00, 0xc0, 0x0c, 0x0e, 0x0f, 0xff, 0xb7, 0xed, 0xff, 0xf0, 
  0x00, 0x03, 0x81, 0xf8, 0x1f, 0xff, 0x01, 0xc0, 0x0c, 0x0f, 0x0f, 0xff, 0xb6, 0x6d, 0xff, 0xf0, 
  0x00, 0x03, 0x83, 0xf8, 0x00, 0x00, 0x01, 0xc0, 0x1c, 0x0f, 0x1e, 0x33, 0x80, 0x07, 0xf9, 0x90, 
  0x00, 0x03, 0x87, 0xfc, 0x00, 0x00, 0x01, 0xc0, 0x1c, 0x0f, 0xbc, 0x39, 0xff, 0x87, 0xe3, 0xc0, 
  0x00, 0x01, 0x9f, 0xfc, 0x1f, 0xff, 0x01, 0xc0, 0x1c, 0x0f, 0xf8, 0x78, 0x01, 0xf9, 0x83, 0xc0, 
  0x00, 0x01, 0xbf, 0xec, 0x1f, 0xff, 0x03, 0x80, 0x1c, 0x0f, 0xf8, 0xbc, 0x00, 0x18, 0x00, 0x00, 
  0x00, 0x01, 0xbf, 0xce, 0x00, 0x00, 0x03, 0x80, 0x18, 0x0f, 0xf8, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x00, 0x01, 0xff, 0x8f, 0x00, 0x00, 0x07, 0x80, 0x38, 0x0f, 0xf8, 0xf0, 0x00, 0x6c, 0x00, 0x00, 
  0x00, 0x06, 0xde, 0x07, 0x00, 0x00, 0x0f, 0x00, 0x38, 0x1e, 0x38, 0x78, 0x00, 0x6c, 0x00, 0x00, 
  0x00, 0x0e, 0xdc, 0x07, 0xc0, 0x00, 0x1f, 0x00, 0x30, 0x1c, 0x3c, 0x78, 0x00, 0x4c, 0x00, 0x00, 
  0x00, 0x1e, 0xe0, 0x03, 0xe0, 0x00, 0x3e, 0x00, 0x70, 0x1c, 0x3f, 0xf0, 0x00, 0xc0, 0x00, 0x00, 
  0x00, 0x7f, 0x60, 0x03, 0xfc, 0x01, 0xfe, 0x00, 0x70, 0x1c, 0x3f, 0xfe, 0x01, 0xb0, 0x00, 0x00, 
  0x00, 0xff, 0x70, 0x01, 0xff, 0xff, 0xfc, 0x00, 0xe0, 0x3c, 0x3f, 0xff, 0x01, 0xb8, 0x00, 0x00, 
  0x01, 0xff, 0x70, 0x00, 0xff, 0xff, 0xf8, 0x01, 0xe0, 0x3e, 0xf0, 0xff, 0x83, 0x00, 0x00, 0x00, 
  0x03, 0xfc, 0x38, 0x00, 0x7f, 0xff, 0xf0, 0x01, 0xc0, 0x3f, 0xe0, 0xe0, 0x06, 0x40, 0x00, 0x00, 
  0x03, 0xf8, 0x38, 0x00, 0x1f, 0xff, 0xc0, 0x03, 0xc0, 0x7f, 0xe1, 0xe0, 0x0e, 0xc0, 0x00, 0x00, 
  0x07, 0xf0, 0x1c, 0x00, 0x07, 0xff, 0x00, 0x07, 0x80, 0x7f, 0xe0, 0xe0, 0x1c, 0x40, 0x00, 0x00, 
  0x07, 0xc0, 0x1e, 0x00, 0x00, 0x70, 0x00, 0x0f, 0x80, 0xf9, 0xe6, 0x00, 0x3b, 0x00, 0x00, 0x00, 
  0x07, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0xf1, 0xe3, 0x80, 0x73, 0x00, 0x00, 0x00, 
  0x07, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x11, 0xf1, 0xe1, 0xc0, 0x00, 0x00, 0x00, 
  0x06, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0xff, 0x00, 0x0b, 0xf9, 0x83, 0x98, 0x00, 0x00, 0x00, 
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1f, 0x1e, 0x18, 0x00, 0x00, 0x00, 
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0xc0, 0x00, 0x00, 0x00, 
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf6, 0xc0, 0x00, 0x00, 0x00, 
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const int startPins[] = {
    2, 3, 4, 5, 6, 7, 8
}; 

const int endPins[] = {
    9, 10, 11, 12, A1, A2, A3
}; 

const int switchPin = A0;

const int pinCount = 7;

int cycles = 0;

bool isShorted() {
  bool shorted = false;
  char strbuf [50];
  for (int i = 0; i < pinCount - 1; i++) {
    // Check start pin
    int currentStartPin = startPins[i];
    pinMode(currentStartPin, OUTPUT);
    digitalWrite(currentStartPin, LOW);
    for (int j = i + 1 ; j < pinCount; j++) {
      pinMode(startPins[j], INPUT_PULLUP);
      int value = digitalRead(startPins[j]);
      if (value == LOW) {
        sprintf(strbuf, "Start Pin %d is shorted to %d", currentStartPin, startPins[j]);    
        Serial.println(strbuf); 
        //Serial.println("Pin ", startPins[j], " is shorted.")
        shorted = true;
        break;
      }
    }
    pinMode(currentStartPin, INPUT_PULLUP);
    if (shorted) {
      break;
    }
    // Check end pin
    int currentEndPin = endPins[i];
    pinMode(currentEndPin, OUTPUT);
    digitalWrite(currentEndPin, LOW);
    for (int j = i + 1 ; j < pinCount; j++) {
      pinMode(endPins[j], INPUT_PULLUP);
      int value = digitalRead(endPins[j]);
      if (value == LOW) {
        sprintf(strbuf, "End Pin %d is shorted to %d", currentEndPin, endPins[j]);    
        Serial.println(strbuf); 
        shorted = true;
        break;
      }
    }
    pinMode(currentEndPin  , INPUT_PULLUP);
    if (shorted) {
      break;
    }
  }
  return shorted;
}

void initPins() {
    for (int i = 0; i < pinCount - 1; i++) {
      pinMode(startPins[i], INPUT_PULLUP);
      pinMode(endPins[i], INPUT_PULLUP);
    }
    pinMode(switchPin, INPUT_PULLUP);

}

int checkSolve() {
    int solved = 0;
    char strbuf [50];
    for (int i = 0; i < pinCount; i++) {
      int currentStartPin = startPins[i];
      pinMode(currentStartPin, OUTPUT);
      digitalWrite(currentStartPin, LOW);   
      pinMode(endPins[i], INPUT_PULLUP);
      int value = digitalRead(endPins[i]);
      pinMode(currentStartPin, INPUT_PULLUP);
      sprintf(strbuf, "Pin %d to %d set to %d", currentStartPin, endPins[i], value);
      Serial.println(strbuf);   
      if (value == LOW) {
        solved++;
      }
    }
    return solved;
}

bool switchCheck() {
      int value = digitalRead(switchPin);
      if (value == LOW) {
        return true;
      }
      return false;
}

void displayMessage(char* msg, int textSize) {
  display.clearDisplay();
  display.setCursor(0,0);             // Start at top-left corner
  display.setTextSize(textSize);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.print(msg);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();  
}

void displayMessage(const __FlashStringHelper *msg, int textSize) {
  display.clearDisplay();
  display.setCursor(0,0);             // Start at top-left corner
  display.setTextSize(textSize);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.print(msg);
  display.display();
  delay(8000);
  display.clearDisplay();
  display.display();  
}

void displayEmoji() {
  display.clearDisplay();
  display.setCursor(0,0);             // Start at top-left corner
  display.drawBitmap(0, 0, epd_bitmap_kingcharlescypher, 128, 64, 1);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  initPins();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  //display.display();
  //delay(2000); // Pause for 2 seconds

  //displayEmoji();
  //delay(5000);
  // Clear the buffer
  Serial.println(F("Clear Display"));
  display.clearDisplay();
  display.print("ready");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  bool swChk = switchCheck();
  if (!swChk)
  {
    delay(100);
    return;
  }
  bool shorted = isShorted();
  if (shorted) {
    Serial.println(F("Shorted"));
    displayMessage(F("Short Detected!\nPlease remove wires\nand try again.\nEach red port must\nconnect to a black port."), 1);
    return;
  }
  int solved = checkSolve();
  if (solved == 0) {
    cycles = 0;
    Serial.println(F("No wires connected correctly"));
    displayMessage(F("No wires connected\ncorrectly.\nConnect the wires\nbetween the black and\nred ports.\nNo wire should cross\nanother.\n"), 1);
    return;
  }
  if (solved == 2) {
    displayMessage(F("Incorrect.\nHint: Not all wires\ngo in a straight\nline."), 1);
    return;
  }
  if (solved >= pinCount-1) {
    Serial.println(F("Solved"));
    displayEmoji();
    initPins();
    cycles=0;
    return;
  } 
  Serial.println(cycles);
  if(cycles == 0  || cycles % 11 != 0) {
    char* msg = "Incorrect!\nTry again";
    Serial.println(msg);    
    displayMessage(msg, 2);
    cycles++;
    return;
  }
  char strbuf [50];
  sprintf(strbuf, "%d of %d\nwires are\ncorrect", solved, pinCount);
  Serial.println(strbuf);    
  displayMessage(strbuf, 2);
  cycles++;
}
