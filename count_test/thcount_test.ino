// Test program to load test the counting program by emulating a barcode scanner output
void setup() {
  // put your setup code here, to run once:
  Serial.begin( 19200 );
  //randomSeed();
}

void loop() {
  // put your main code here, to run repeatedly:
  int car = random(1, 99);
  int codeType = random(0, 2);
  int clue = random(25);
  char clueLetter = 65 + clue;
  char buff[50];
  //sprintf(buff, "Car: %d, Clue: %d, Code: %d\n", car, clue, codeType);
  //Serial.println(buff);
  switch(codeType) {
    case 0: // clue
      sprintf(buff, "%d-CL-%c\r\n", car, clueLetter);
      break;
    default: //emergency
      sprintf(buff, "%d-EM-%d\r\n", car, clue);
      break;
  }
  Serial.print(buff);
  delay(200);
}
