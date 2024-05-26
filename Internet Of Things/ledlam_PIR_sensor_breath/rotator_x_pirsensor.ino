#define LED_PIN_1 D1 // Pin untuk LED 1
#define LED_PIN_2 D3 // Pin untuk LED 2
#define LED_PIN_3 D5 // Pin untuk LED 3
#define LED_PIN_4 D7 // Pin untuk LED 4
#define PIR_PIN D2    // Pin untuk sensor PIR

#define FADE_DELAY 10 // Waktu jeda antara setiap iterasi fading (dalam milidetik)
#define MAX_BRIGHTNESS 1023 // Tingkat kecerahan maksimum
#define MIN_BRIGHTNESS 0 // Tingkat kecerahan minimum

bool motionDetected = false;

void setup() {
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(PIR_PIN);
  if (sensorValue == HIGH) {
    motionDetected = true;
  }

  if (motionDetected) {
    rotateLights(100); // Kecepatan rotasi lampu dalam milidetik
    motionDetected = false; // Reset flag deteksi gerakan setelah menyalakan lampu
  }

  // Treshold untuk menentukan apakah ada objek atau tidak
  if (sensorValue == HIGH) {
    Serial.println(sensorValue);
    Serial.println("object detected");
  } else {
    Serial.println(sensorValue);
    Serial.println("no object");
  }

  delay(250);
}

void rotateLights(int speed) {
  int brightness = MIN_BRIGHTNESS;
  int fadeAmount = 5;

  while (brightness < MAX_BRIGHTNESS) {
    analogWrite(LED_PIN_1, brightness);
    analogWrite(LED_PIN_2, brightness);
    analogWrite(LED_PIN_3, brightness);
    analogWrite(LED_PIN_4, brightness);
    brightness += fadeAmount;
    delay(speed);
  }

  brightness = MAX_BRIGHTNESS;

  while (brightness > MIN_BRIGHTNESS) {
    analogWrite(LED_PIN_1, brightness);
    analogWrite(LED_PIN_2, brightness);
    analogWrite(LED_PIN_3, brightness);
    analogWrite(LED_PIN_4, brightness);
    brightness -= fadeAmount;
    delay(speed);
  }
}
