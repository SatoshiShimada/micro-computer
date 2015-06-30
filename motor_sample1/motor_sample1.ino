void Motor_speed(int s);
void Motor_turn(int t);

void setup()
{
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  //pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  static int i = 0, t = 70;
  
  if(t == 150) {
    t = 70;
    Motor_speed(0);
    delay(100);
    if(i == 1) {
      Motor_turn('r');
      i = 0;
    } else {
      Motor_turn('l');
      i = 1;
    }
  }
  Motor_speed(t++);
  //delayMicroseconds(100);
  delay(100);

  return;
}

void Motor_speed(int s)
{
  if(s <= 0 || s > 255) s = 0;
  analogWrite(3, s);

  return;
}

void Motor_turn(int t)
{
  if(t == 'r') {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  } else if(t == 'l') {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
  }
}

