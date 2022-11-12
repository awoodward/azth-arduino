int rate = 300;
String codes[] = {
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--.."   // Z
};

String message = "captain kirks messenger"; 
int ledPin = 3;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(19200); // open the serial port at 9600 bps:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(ledPin, OUTPUT);
}

int blinkChar(char current)
{
  int c = current;
  if (c == 32)  {
    // space between words
    delay(rate * 4); // already delayed the space between characters and just need to delay the additional amount for a word
    Serial.print(" ");
    return;
  }

  // convert ASCII numbers to array location
  c = (c >= 48 && c <=57) ? c - 48 : c;
  // convert ASCII upper case letters to array location
  c = (c >= 65 && c <=90) ? c - 55 : c;
  // convert ASCII lower case letters to array location
  c = (c >= 97 && c <=122) ? c - 87 : c;
  
  String code = codes[c];
  for (int i = 0; i < code.length(); i++) {
    Serial.print(code.charAt(i));
    switch (code.charAt(i)) {
      case '.':
        digitalWrite(ledPin, HIGH);
        delay(rate);
        digitalWrite(ledPin, LOW);
        break;
      case '-':
        digitalWrite(ledPin, HIGH);
        delay(rate*3);
        digitalWrite(ledPin, LOW);
        break;
    }
    delay(rate);
  }
  delay(rate*3); // delay between letters
}

void loop()
{
  Serial.println();
  for (int i=0; i< message.length() ; i++) {
    char current = message.charAt(i); 
    blinkChar(current);
  }
  delay(rate * 4); // word delay between repeating the sequence
}
