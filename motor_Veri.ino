int i;
int a;
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  i=analogRead(A0);
  if(Serial.read()=="1")
  {
    Serial.println(i);
    delay(5);
  }
  i=analogRead(A1);
  if(Serial.read()=="2")
  {
    Serial.println(a);
    delay(5);
  }
}
