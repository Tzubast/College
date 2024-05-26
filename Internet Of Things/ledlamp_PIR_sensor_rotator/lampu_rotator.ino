#define LED_PIN_1 D1 // Pin untuk LED 1
#define LED_PIN_2 D3 // Pin untuk LED 2
#define LED_PIN_3 D5 // Pin untuk LED 3
#define LED_PIN_4 D7 // Pin untuk LED 4

#define FADE_DELAY 10 // Waktu jeda antara setiap iterasi fading (dalam milidetik)
#define MAX_BRIGHTNESS 1023 // Tingkat kecerahan maksimum
#define MIN_BRIGHTNESS 0 // Tingkat kecerahan minimum

void setup() {
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
}

void loop() {
  breathLights(2000); // Waktu siklus pernapasan (dalam milidetik)
}

void breathLights(int cycleTime) {
  int brightness = MIN_BRIGHTNESS;
  int fadeAmount = 5;
  
  while (true) {
    // Meningkatkan kecerahan
    while (brightness < MAX_BRIGHTNESS) {
      analogWrite(LED_PIN_1, brightness);
      analogWrite(LED_PIN_2, brightness);
      analogWrite(LED_PIN_3, brightness);
      analogWrite(LED_PIN_4, brightness);
      brightness += fadeAmount;
      delay(FADE_DELAY);
    }
    
    // Mengurangi kecerahan
    while (brightness > MIN_BRIGHTNESS) {
      analogWrite(LED_PIN_1, brightness);
      analogWrite(LED_PIN_2, brightness);
      analogWrite(LED_PIN_3, brightness);
      analogWrite(LED_PIN_4, brightness);
      brightness -= fadeAmount;
      delay(FADE_DELAY);
    }
  }
}
