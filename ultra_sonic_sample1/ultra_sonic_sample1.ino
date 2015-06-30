void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long t = 0;
  int i;
  static int j = 0;
  int f = 40 * 1000;

  tone(10, f); // 40kHz
  //digitalWrite(10, HIGH);
  
  i = (int)analogRead(A5);
  if(j < i) j = i;
  
  if(millis() - t > 500) {
    t = millis();
    Serial.print(t);
    Serial.print(" ");
    Serial.println(j, DEC);
    j = 0;
  }
}
