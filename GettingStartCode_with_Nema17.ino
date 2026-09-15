#include <AccelStepper.h>

// STEP and DIR pins
#define STEP_PIN 2
#define DIR_PIN 3
#define EN_PIN 8

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup()
{
  Serial.begin(115200);

  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);     // Enable Driver

  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(1000);
  stepper.setCurrentPosition(0);

  Serial.println("Stepper Ready");

  printMenu();
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
        forward1000();
        break;

      case '2':
        backward1000();
        break;

      case '3':
        gotoZero();
        break;

      case '4':
        rotateCW();
        break;

      case '5':
        rotateCCW();
        break;

      case '6':
        stopMotor();
        break;

      case '7':
        emergencyStop();
        break;

      case '8':
        setSpeedDemo();
        break;

      case '9':
        printInfo();
        break;

      case 'a':
        disableMotor();
        break;

      case 'b':
        enableMotor();
        break;

      case 'c':
        resetPosition();
        break;
    }
  }
}

void printMenu()
{
  Serial.println();
  Serial.println("1 Forward 1000");
  Serial.println("2 Backward 1000");
  Serial.println("3 Go Home");
  Serial.println("4 Rotate CW");
  Serial.println("5 Rotate CCW");
  Serial.println("6 Stop");
  Serial.println("7 Emergency Stop");
  Serial.println("8 Speed Demo");
  Serial.println("9 Print Info");
  Serial.println("a Disable Driver");
  Serial.println("b Enable Driver");
  Serial.println("c Reset Position");
}

void forward1000()
{
  stepper.move(1000);
}

void backward1000()
{
  stepper.move(-1000);
}

void gotoZero()
{
  stepper.moveTo(0);
}

void rotateCW()
{
  stepper.setSpeed(800);
  while(!Serial.available())
  {
    stepper.runSpeed();
  }
}

void rotateCCW()
{
  stepper.setSpeed(-800);
  while(!Serial.available())
  {
    stepper.runSpeed();
  }
}

void stopMotor()
{
  stepper.stop();
}

void emergencyStop()
{
  stepper.setCurrentPosition(stepper.currentPosition());
  stepper.stop();
}

void setSpeedDemo()
{
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(2000);
}

void printInfo()
{
  Serial.print("Current Position : ");
  Serial.println(stepper.currentPosition());

  Serial.print("Target Position : ");
  Serial.println(stepper.targetPosition());

  Serial.print("Distance To Go : ");
  Serial.println(stepper.distanceToGo());

  Serial.print("Speed : ");
  Serial.println(stepper.speed());
}

void disableMotor()
{
  digitalWrite(EN_PIN, HIGH);
}

void enableMotor()
{
  digitalWrite(EN_PIN, LOW);
}

void resetPosition()
{
  stepper.setCurrentPosition(0);
}
