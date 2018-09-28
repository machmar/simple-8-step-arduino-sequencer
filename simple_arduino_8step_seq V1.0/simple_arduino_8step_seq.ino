const int muxA = 10;
const int muxB = 11;
const int muxC = 12;

int stepNumber = 0;
int stepCount = 8;
int clockVar = 0;
int lastClock = 1;
int stepCheck = 0;
int stepKnobVar = 0;
int stepCvVar = 0;
int stepDetectVar = 1;
int resetVar = 0;
int holdVar = 0;
int holdStage = 0;
int lastStep = 0;

int aniSpeed = 50;
int aniSpeedVar = 50;
int aniMode = 0;
int aniModeVar = 0; 
int aniModeLast = 1;

int resetIn = 3;
int holdIn = 4;
int clockIn = 2;
int stepDetectIn = 5;
int stepKnobIn = 20;
int stepCvIn = 21;

void mux(int muxBin) {
if  (muxBin == 0) {
  digitalWrite(muxA, 0);
  digitalWrite(muxB, 0);
  digitalWrite(muxC, 0);
}

if  (muxBin == 1) {
  digitalWrite(muxA, 1);
  digitalWrite(muxB, 0);
  digitalWrite(muxC, 0);
}

if  (muxBin == 2) {
  digitalWrite(muxA, 0);
  digitalWrite(muxB, 1);
  digitalWrite(muxC, 0);
}

if  (muxBin == 3) {
  digitalWrite(muxA, 1);
  digitalWrite(muxB, 1);
  digitalWrite(muxC, 0);
}

if  (muxBin == 4) {
  digitalWrite(muxA, 0);
  digitalWrite(muxB, 0);
  digitalWrite(muxC, 1);
}

if  (muxBin == 5) {
  digitalWrite(muxA, 1);
  digitalWrite(muxB, 0);
  digitalWrite(muxC, 1);
}

if  (muxBin == 6) {
  digitalWrite(muxA, 0);
  digitalWrite(muxB, 1);
  digitalWrite(muxC, 1);
}

if  (muxBin == 7) {
  digitalWrite(muxA, 1);
  digitalWrite(muxB, 1);
  digitalWrite(muxC, 1);
}

}

void clockSense() {
  clockVar = digitalRead(clockIn);

  if (clockVar == 0 && lastClock == 0) { 
    stepNumber++;   
    lastClock = 1;
  }
  if (clockVar == 1 && lastClock == 1) {
    stepCheck = 1;
    lastClock = 0;
  }
  if (stepNumber >= stepCount) stepNumber = 0;
}

void resetSense() {
  resetVar = digitalRead(resetIn);
  if (resetVar == 1) {
    stepNumber = 0;
  }
}

void hold() {
holdVar = digitalRead(holdIn);
if (holdStage == 0) {
  if (holdVar == 1) {
    lastStep = stepNumber;
    holdStage = 1;
  }
}
if (holdStage == 1){
  if (holdVar == 1) {
    stepNumber = lastStep;
  }
  else holdStage = 0;
} 
}  
  
void animation(int aniNum, int aniDelay) {
  if (aniNum == 0) {
  mux(0);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  }
  if (aniNum == 1) {
  mux(0);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  }
  if (aniNum == 2) {
  mux(0);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  }
  if (aniNum == 3) {
  mux(0);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  }
  if (aniNum == 4) {
  mux(0);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  }
  if (aniNum == 5) {
  mux(0);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  }
  if (aniNum == 6) {
  mux(0);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(0);
  delay(aniDelay);
  mux(1);
  delay(aniDelay);
  mux(2);
  delay(aniDelay);
  mux(3);
  delay(aniDelay);
  mux(7);
  delay(aniDelay);
  mux(6);
  delay(aniDelay);
  mux(5);
  delay(aniDelay);
  mux(4);
  delay(aniDelay);
  }
  if (aniNum == 7) {
  mux(0);
  mux(1);
  mux(2);
  mux(3);
  mux(4);
  mux(5);
  mux(6);
  mux(7);

  }
}

void setup() {

  Serial.begin(2000000);
  
  pinMode(muxA, OUTPUT);
  pinMode(muxB, OUTPUT);
  pinMode(muxC, OUTPUT);
  pinMode(resetIn, INPUT);
  pinMode(holdIn, INPUT);
  pinMode(clockIn, INPUT);
  pinMode(stepDetectIn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(clockIn), clockSense, CHANGE);
  attachInterrupt(digitalPinToInterrupt(resetIn), resetSense, CHANGE);
  mux(0);
  delay(50);
  mux(1);
  delay(50);
  mux(2);
  delay(50);
  mux(3);
  delay(50);
  mux(7);
  delay(50);
  mux(6);
  delay(50);
  mux(5);
  delay(50);
  mux(4);
  delay(50);
  mux(0);
  delay(50);
  mux(1);
  delay(50);
  mux(2);
  delay(50);
  mux(3);
  delay(50);
  mux(7);
  delay(50);
  mux(6);
  delay(50);
  mux(5);
  delay(50);
  mux(4);
  delay(50);
  mux(0); 
}

void loop() {
  stepDetectVar = digitalRead(stepDetectIn);

if (stepCheck == 0) {
  aniModeVar = digitalRead(holdIn);
  aniSpeedVar = analogRead(stepKnobIn);
  aniSpeed = map(aniSpeedVar, 0, 1023, 1, 150);
  
  if (aniModeVar == 0 && aniModeLast == 0) { 
    aniModeLast = 1;
  }
  if (aniModeVar == 1 && aniModeLast == 1) {
    aniMode++;
    aniModeLast = 0;
  }
  if(aniMode >= 8) aniMode = 0;
  animation(aniMode, aniSpeed); 
}

  hold();
  clockSense();
  mux(stepNumber);
  resetSense();
  if (stepDetectVar == 1){
    stepKnobVar = analogRead(stepKnobIn);
    stepCount = map(stepKnobVar, 0, 1023, 1, 9);
  }
  if (stepDetectVar == 0){
    stepCvVar = analogRead(stepCvIn);
    stepCount = map(stepCvVar, 0, 1023, 1, 9);
  }
    Serial.println(stepCount);
}
