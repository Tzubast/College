#define TRIG_PIN D5
#define ECHO_PIN D6
#define LED_PIN D4

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(TRIG_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Memulai pengukuran
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Membaca durasi dari sensor ultrasonik
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Menghitung jarak dalam cm
  distance = (duration / 2) / 29.1;
  
  // Debugging, cetak jarak ke Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Menyalakan atau mematikan LED berdasarkan jarak
  if (distance < 10) { // Jika jarak kurang dari 10 cm
    digitalWrite(LED_PIN, HIGH); // Nyalakan LED
  } else {
    digitalWrite(LED_PIN, LOW); // Matikan LED
  }
  
  // Delay sebelum pengukuran berikutnya
  delay(100);
}
