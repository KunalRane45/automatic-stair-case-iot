const int ir1 = 2;
const int ir2 = 3;
int inputVal = 0;
int decide = 0;

void setup()
{
  pinMode(13, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:
  pinMode(ir1, INPUT); //Pin 2 is connected to the output of proximity sensor
  pinMode(ir2, INPUT); //Pin 3 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop()
{
  if (analogRead(A1) <= 200) {
    if (digitalRead(ir1) == LOW || digitalRead(ir2) == HIGH)   //Check the sensor output
    {
      decide++;
    }
    if (decide % 2 != 0)
    {
      digitalWrite(13, HIGH);   // set the LED on
    }
    else
    {
      digitalWrite(13, LOW);    // set the LED off
    }
  }
  inputVal = digitalRead(ir1);
  Serial.println(inputVal);
  Serial.println(decide);
  delay(500);              // wait for a second

}
