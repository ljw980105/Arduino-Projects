int buzzer = 12;
int button = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

int interval = 0; // interval of time between buzzer sounds

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;
  
  while (1){
    for (i = 0; i < 100; i++){

      if (digitalRead(button) == LOW){
        interval += 3;
        if (interval > 30) {
          interval = 0;
        }
        Serial.println(interval);
        delay(150); // compensate for button debouncing
      }
      
      digitalWrite(buzzer,HIGH);
      delay(interval);
      digitalWrite(buzzer,LOW);
      delay(interval);
    }
  }

}
