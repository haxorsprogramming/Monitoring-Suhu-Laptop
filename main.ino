#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define relay 16

#define ONE_WIRE_BUS D4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  printLcd("Sistem monitoring", "suhu laptop");
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  delay(1000);
}

void loop() {
  printLcd("Baca suhu", "sekarang");
  delay(1000);
  printLcd("Pedih,,", "...");
  sensors.requestTemperatures();
  printLcd("Temperature is: ",String(sensors.getTempCByIndex(0)));
  //  Serial.println("Hidup");
  //  digitalWrite(relay, LOW);
  //  delay(2000);
  //  Serial.println("Mati");
  //  digitalWrite(relay, HIGH);
  delay(2000);
}

void printLcd(String teks, String teks2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(teks);
  lcd.setCursor(0, 1);
  lcd.print(teks2);
}
