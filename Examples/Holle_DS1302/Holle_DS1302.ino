
#include <DS1302.h>

const int port_h1=2; //снимаем состояние
const int port_h2=3; //питание датчика
uint8_t state = 0;


namespace {

const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 6;  // Input/Output
const int kSclkPin = 7;  // Serial Clock

// Create a DS1302 object.
DS1302 rtc(kCePin, kIoPin, kSclkPin);


void printTime() {
  // Get the current time and date from the chip.
  Time t = rtc.time();


  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d", t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  // Print the formatted string to serial so we can see the time.
  Serial.println(buf);
}

}  // namespace

void setup() {
  Serial.begin(9600);
  
  pinMode(port_h1, INPUT);
  pinMode(port_h2, OUTPUT);

  // Initialize a new chip by turning off write protection and clearing the
  // clock halt flag. These methods needn't always be called. See the DS1302
  // datasheet for details.
  rtc.writeProtect(false);
  rtc.halt(false);
  
   //Time t(2015, 04, 26, 21, 20, 10, Time::kSaturday);
   //rtc.time(t);
  
}

// Loop and print the time every second.
void loop() {
  
  digitalWrite (port_h2, HIGH); //включаем питание
  state = digitalRead(port_h1); //опрашиваем датчик
  Serial.println(state);
  delay (1000);
  digitalWrite (port_h2, LOW);//сбрасываем значение датчика в 0
  
  if (state == 1) {
  printTime();
  }
  delay(1000);
}
