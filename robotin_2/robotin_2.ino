// ROBOTÍN PART 2 (Arduino Nano)
// ÓSCAR POBLETE SÁENZ
int i=0;
int valdr; // PHOTORESISTOR STATE
int GREENLEDS[]={7,8,9,10};
const int BUZZER=11;
const int WHITELED_ONE=6;
const int WHITELED_TWO=5;
const int PHOTORES=A0;

void setup() {
Serial.begin(9600);
   for(i=0;i<=3;i++){
  pinMode(GREENLEDS[i],OUTPUT);
  }
  pinMode(BUZZER, OUTPUT);
  pinMode(WHITELED_ONE, OUTPUT);
  pinMode(WHITELED_TWO, OUTPUT);
//SILENCE BUZZER
  noTone(BUZZER);
// TURN OFF THE LEDS
  shutLEDs();
}

void loop(){
  ledsv(); // START LEDS (TRUNK DECORATION)
  LDR(); // INITIALIZE LIGHT DETECTION FOR NIGHT LIGHTS
}

// CUSTOM LIGHT SERIES (TRUNK)
void ledsv(){ 
   digitalWrite(GREENLEDS[0],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[0],LOW);
   delay(70);
   digitalWrite(GREENLEDS[2],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[2],LOW);
   delay(70);
   digitalWrite(GREENLEDS[0],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[0],LOW);
   delay(70);
   digitalWrite(GREENLEDS[1],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[1],LOW);
   delay(70);
   digitalWrite(GREENLEDS[3],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[3],LOW);
   delay(70);
   digitalWrite(GREENLEDS[1],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[1],LOW);
   delay(70);
   digitalWrite(GREENLEDS[3],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[3],LOW);
   delay(70);
   digitalWrite(GREENLEDS[1],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[1],LOW);
   delay(70);
   digitalWrite(GREENLEDS[0],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[0],LOW);
   delay(70);
   digitalWrite(GREENLEDS[2],HIGH);
   delay(70);
   digitalWrite(GREENLEDS[2],LOW);
   delay(70);
}

void siren(){
  tone(BUZZER,440,500);
  delay(500);
  noTone(BUZZER);
  tone(BUZZER,349.23,500);
  delay(500);
  tone(BUZZER,440,500);
  delay(500);
  noTone(BUZZER);
  tone(BUZZER,349.23,500);
  delay(500);
}

void LDR(){
  valdr= analogRead(PHOTORES);
  Serial.println(valdr); // Return the value read to our serial monitor on the captured light
  if(valdr <10) //Adjust desired light level to switch white leds
  {
    siren(); // START SIRENS
    digitalWrite(WHITELED_ONE, HIGH); // Turn on the leds in the dark
    digitalWrite(WHITELED_TWO, HIGH);
  }
  else
  {
    digitalWrite(WHITELED_ONE, LOW); //Turn off the leds in the light
    digitalWrite(WHITELED_TWO, LOW); 
    noTone(BUZZER);
  }
}

void shutLEDs()
{
//Turn off all the LEDs
  for(i=0;i<=3;i++){
  digitalWrite(GREENLEDS[i], LOW);
  }
  digitalWrite(WHITELED_ONE, LOW);
  digitalWrite(WHITELED_TWO, LOW);
}
