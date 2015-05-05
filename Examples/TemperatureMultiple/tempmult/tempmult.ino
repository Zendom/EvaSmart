
#define ONE_WIRE_BUS 8      // назначаем пин для шины OneWire и датчиков температуры
#define TIME_REFRESH 2000       // Задаем время обновления показаний

// Подключаем библиотеку Dallas
#include <OneWire.h>
#include <DallasTemperature.h>

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// Переменная показаний температуры
float tempSensor1 = 1.0;
float tempSensor2 = 1.0;


void setup() 
{
  Serial.begin(9600);     
  Serial.println("Setup...");

  // Start up the Dallas Temperature library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
  
  Serial.println("Setup complete.");
}


void loop() 
{ 
  Serial.println("\n\r\n\r******** loop() begin ********");
  sensorTempRead();  // Опрос датчика температуры
  delay (TIME_REFRESH);
}


// Опрос датчиков температуры
void sensorTempRead()
{   
  Serial.println("Reading sensors...");
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  sensors.requestTemperatures(); // Send the command to get temperatures
  tempSensor1 = sensors.getTempCByIndex(0);
  tempSensor2 = sensors.getTempCByIndex(1);

  Serial.print("Tsensor1: ");
  Serial.println(tempSensor1);
  Serial.print("Tsensor2: ");
  Serial.println(tempSensor2);
}

