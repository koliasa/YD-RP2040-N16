#define LED_PIN 25  // Пін для синього світлодіода (GP25)

// Налаштування для LED
bool ledStatus = false;        // Статус світлодіода (включений/вимкнений)
unsigned long previousMillisLED = 0; // Зберігає останній момент часу для LED
const int ledBlinkInterval = 500; // Інтервал мигання синього світлодіода

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Встановлюємо LED_PIN як вихід
}

void loop() {
  blinkLED();
}

// Функція для асинхронного мигання LED
void blinkLED() {
  unsigned long currentMillis = millis(); // Отримати поточний час

  if (currentMillis - previousMillisLED >= ledBlinkInterval) {
    ledStatus = !ledStatus; // Змінити статус світлодіода
    digitalWrite(LED_PIN, ledStatus ? HIGH : LOW); // Включити/вимкнути світлодіод
    previousMillisLED = currentMillis; // Оновити час останнього мигання
  }
}
