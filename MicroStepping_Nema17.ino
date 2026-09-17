#include <AccelStepper.h>
#define STEP_PIN 4
#define DIR_PIN 3
#define EN_PIN 2
#define MS1_PIN 5
#define MS2_PIN 6
#define MS3_PIN 7
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);
int currentMicrostep = 1;

void setup()
{
  Serial.begin(115200);

  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);

  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS3_PIN, OUTPUT);

  stepper.setMaxSpeed(1500);
  stepper.setAcceleration(800);

  setMicrostep(1);      // Default Full Step

  Serial.println("===== A4988 Microstepping Demo =====");
  Serial.println("1 = Full Step");
  Serial.println("2 = Half Step");
  Serial.println("3 = Quarter Step");
  Serial.println("4 = 1/8 Step");
  Serial.println("5 = 1/16 Step");
}

void loop()
{
  stepper.run();

  if (Serial.available())
  {
    char cmd = Serial.read();

    switch(cmd)
    {
      case '1':
        setMicrostep(1);
        rotateOneRevolution();
        break;

      case '2':
        setMicrostep(2);
        rotateOneRevolution();
        break;

      case '3':
        setMicrostep(4);
        rotateOneRevolution();
        break;

      case '4':
        setMicrostep(8);
        rotateOneRevolution();
        break;

      case '5':
        setMicrostep(16);
        rotateOneRevolution();
        break;
    }
  }
}

void rotateOneRevolution()
{
  int steps;

  switch(currentMicrostep)
  {
    case 1:  steps = 200;  break;
    case 2:  steps = 400;  break;
    case 4:  steps = 800;  break;
    case 8:  steps = 1600; break;
    case 16: steps = 3200; break;
  }

  stepper.move(steps);

  Serial.print("Moving ");
  Serial.print(steps);
  Serial.println(" steps");
}

void setMicrostep(int mode)
{
  currentMicrostep = mode;

  switch(mode)
  {
    case 1:
      digitalWrite(MS1_PIN, LOW);
      digitalWrite(MS2_PIN, LOW);
      digitalWrite(MS3_PIN, LOW);
      Serial.println("Full Step");
      break;

    case 2:
      digitalWrite(MS1_PIN, HIGH);
      digitalWrite(MS2_PIN, LOW);
      digitalWrite(MS3_PIN, LOW);
      Serial.println("Half Step");
      break;

    case 4:
      digitalWrite(MS1_PIN, LOW);
      digitalWrite(MS2_PIN, HIGH);
      digitalWrite(MS3_PIN, LOW);
      Serial.println("Quarter Step");
      break;

    case 8:
      digitalWrite(MS1_PIN, HIGH);
      digitalWrite(MS2_PIN, HIGH);
      digitalWrite(MS3_PIN, LOW);
      Serial.println("1/8 Step");
      break;

    case 16:
      digitalWrite(MS1_PIN, HIGH);
      digitalWrite(MS2_PIN, HIGH);
      digitalWrite(MS3_PIN, HIGH);
      Serial.println("1/16 Step");
      break;
  }
}
