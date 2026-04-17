#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

// Telegram
#define BOT_TOKEN "YOUR_NEW_TOKEN"
#define CHAT_ID "1054454968"

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
#define CURRENT_PIN 35
#define MOISTURE_PIN 34
#define RELAY_PIN 5

// Variables
float current = 0;
float voltage = 0;
int moisture = 0;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.print("Connecting WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  lcd.clear();
  lcd.print("WiFi Connected");

  client.setInsecure();

  bot.sendMessage(CHAT_ID, "✅ Smart Switchboard ONLINE", "");
}

void loop() {

  // -------- SENSOR READINGS --------
  int rawValue = analogRead(CURRENT_PIN);
  voltage = rawValue * (3.3 / 4095.0);
  current = (voltage - 2.5) / 0.100; // ACS712

  moisture = analogRead(MOISTURE_PIN);

  // -------- LCD DISPLAY --------
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("I:");
  lcd.print(current,1);
  lcd.print("A");

  lcd.setCursor(0,1);
  lcd.print("M:");
  lcd.print(moisture);

  if(digitalRead(RELAY_PIN) == HIGH){
    lcd.print(" ON");
  } else {
    lcd.print(" OFF");
  }

  // -------- SAFETY LOGIC --------

  if(current > 5.0){
    digitalWrite(RELAY_PIN, LOW);
    bot.sendMessage(CHAT_ID, "⚠️ Overload! Power OFF", "");
    delay(3000);
  }

  if(moisture > 2000){
    digitalWrite(RELAY_PIN, LOW);
    bot.sendMessage(CHAT_ID, "💧 Moisture detected!", "");
    delay(3000);
  }

  // -------- TELEGRAM COMMANDS --------

  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  for (int i = 0; i < numNewMessages; i++) {

    String text = bot.messages[i].text;

    if (text == "/start") {
      bot.sendMessage(CHAT_ID,
        "Smart Switchboard\n"
        "/status\n"
        "/on\n"
        "/off", "");
    }

    if (text == "/status") {
      String msg = "⚡ Current: " + String(current) + "A\n";
      msg += "💧 Moisture: " + String(moisture);
      bot.sendMessage(CHAT_ID, msg, "");
    }

    if (text == "/off") {
      digitalWrite(RELAY_PIN, LOW);
      bot.sendMessage(CHAT_ID, "❌ Power OFF", "");
    }

    if (text == "/on") {
      digitalWrite(RELAY_PIN, HIGH);
      bot.sendMessage(CHAT_ID, "✅ Power ON", "");
    }
  }

  delay(2000);
}