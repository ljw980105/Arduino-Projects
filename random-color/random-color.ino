// pwm channels
#define BLUE 3
#define GREEN 5
#define RED 6 

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
}

int redValue;
int greenValue;
int blueValue;
#define delayTime 1000

void loop() {
  // put your main code here, to run repeatedly:
  redValue = random(0,255);
  greenValue = random(0,255);
  blueValue = random(0,255);

  analogWrite(RED,redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue); 
  delay(delayTime);
}
