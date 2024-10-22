#include <Adafruit_NeoPixel.h>

#define RGB_PIN 23      // Пін для RGB (GP23)
#define NUMPIXELS 1     // Кількість пікселів

Adafruit_NeoPixel pixels(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

// Налаштування яскравості у відсотках (0-100)
int brightness[7] = {5, 5, 5, 5, 5, 5, 5}; // Яскравість: Червоний, Зелений, Синій, Жовтий, Фіолетовий, Блакитний, Білий

// Налаштування інтенсивності мигання (секунди, мілісекунди) для кожного кольору
int blinkDuration[7][2] = {
  {1, 0}, // Червоний
  {1, 0}, // Зелений
  {1, 0}, // Синій
  {1, 0}, // Жовтий
  {1, 0}, // Фіолетовий
  {1, 0}, // Блакитний
  {1, 0}  // Білий
};

void setup() {
  pixels.begin();  // Ініціалізація бібліотеки
}

void loop() {
  // Червоний
  blinkColor(0, 255, 0, 0); // Червоний
  // Зелений
  blinkColor(1, 0, 255, 0); // Зелений
  // Синій
  blinkColor(2, 0, 0, 255); // Синій
  // Жовтий
  blinkColor(3, 255, 255, 0); // Жовтий
  // Фіолетовий
  blinkColor(4, 128, 0, 128); // Фіолетовий
  // Блакитний
  blinkColor(5, 0, 255, 255); // Блакитний
  // Білий
  blinkColor(6, 255, 255, 255); // Білий
}

void blinkColor(int colorIndex, int red, int green, int blue) {
  // Обчислити фактичні значення кольору на основі яскравості
  int r = red * brightness[colorIndex] / 100;
  int g = green * brightness[colorIndex] / 100;
  int b = blue * brightness[colorIndex] / 100;

  // Увімкнути колір
  setColor(r, g, b);
  
  // Тривалість мигання
  delay(blinkDuration[colorIndex][0] * 1000 + blinkDuration[colorIndex][1]);
  
  // Вимкнути колір
  setColor(0, 0, 0);
  
  // Тривалість вимкнення (можна налаштувати за потребою)
  delay(500);
}

void setColor(int red, int green, int blue) {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.show();  // Оновити кольори
}