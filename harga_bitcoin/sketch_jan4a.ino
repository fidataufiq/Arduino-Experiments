#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Reset pin tidak digunakan
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// WiFi Credentials
const char* ssid = "Nanikjatibelanda";  // Ganti dengan nama WiFi Anda
const char* password = "nanik278487";  // Ganti dengan password WiFi Anda

// CoinDesk API
const char* host = "api.coindesk.com";
const int httpsPort = 443;

// Update interval
#define UPDATE_INTERVAL 60000 
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  delay(10);

  // OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Menghubungkan WiFi...");
  display.display();

  // Menghubungkan ke WiFi
  WiFi.begin(ssid, password);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {  // Coba 20 *
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi Connected!");
    display.display();
  } else {
    Serial.println("\nWiFi Connection Failed");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi Failed!");
    display.display();
    return;  // Jika gagal, berhenti
  }

  delay(2000);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= UPDATE_INTERVAL) {
    previousMillis = currentMillis;
    fetchAndDisplayBTC();
  }
}

void fetchAndDisplayBTC() {
  WiFiClientSecure client;
  client.setInsecure();  // Mengabaikan sertifikat SSL

  Serial.print("Menghubungkan ke ");
  Serial.println(host);

  if (!client.connect(host, httpsPort)) {
    Serial.println("Koneksi gagal");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Koneksi gagal");
    display.display();
    return;
  }

  String url = "/v1/bpi/currentprice/BTC.json";
  Serial.print("Meminta URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
              "Host: " + host + "\r\n" +
              "Connection: close\r\n\r\n");

  String payload = "";
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {  // Header selesai
      break;
    }
  }

  while (client.available()) {
    char c = client.read();
    payload += c;
  }

  Serial.println("Payload mentah:");
  Serial.println(payload);

  // Ekstrak JSON dari payload
  String jsonPayload = payload.substring(payload.indexOf("{"));
  Serial.println("JSON Payload:");
  Serial.println(jsonPayload);

  // Deserialisasi JSON
  DynamicJsonDocument doc(2048);
  DeserializationError error = deserializeJson(doc, jsonPayload);

  if (error) {
    Serial.print("Error deserialisasi JSON: ");
    Serial.println(error.c_str());
    return;
  }

  // Data dari JSON
  double rate = doc["bpi"]["USD"]["rate_float"];
  String lastUpdateTime = doc["time"]["updated"];

  //---------------
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1); 
  display.println("Harga Bitcoin (USD):");

  display.setTextSize(2);  
  display.setCursor(0, 20);
  display.print("$");
  display.print(rate, 2); 

  // Tampilkan tanggal dan waktu update (dari API)
  display.setTextSize(1);
  display.setCursor(0, 50);
  display.println(lastUpdateTime.substring(0, 16));  // Ambil hanya tanggal dan jam

  display.display();
}

//hhhhhhh
