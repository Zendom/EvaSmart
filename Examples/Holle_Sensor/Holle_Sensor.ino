int port_h1=2; //снимаем состояние
int port_h2=3; //питание датчика
uint8_t state = 0;

void setup()
{
  pinMode(port_h1, INPUT);
  pinMode(port_h2, OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  digitalWrite (port_h2, HIGH); //включаем питание
   state = digitalRead(port_h1); //опрашиваем датчик
  Serial.println(state);
 delay (1000);
  digitalWrite (port_h2, LOW);//сбрасываем значение датчика в 0
}
