/*Theremin - a program by Nate Weeks using the sparkfun inventors kit to create
a theremin style instrument - November 2018

resources:

https://forum.arduino.cc/index.php?topic=64988.0
SparkFun Inventor’s Kit
Circuit 3B-Distance Sensor


View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code

Circuit 2b-Digital Trumpet
View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

const int trigPin = 11;           //connects to the echo pin on the distance sensor
const int echoPin = 12;           //connects to the trigger pin on the distance sensor

float distance = 0;               //stores the distance measured by the distance sensor

int buzzerPin = 9;                //connects to the buzzer outputs in hertz
int pitch = 100;                  //stores the pitch based on distance
float oldDistance;
float distanceDifference;
float oldPitch;
int modePin = 2;                  //stores the button that toggles the mode

void setup()
{
  Serial.begin (9600);        //set up a serial connection with the computer

  pinMode(trigPin, OUTPUT);   //the trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);    //the echo pin will measure the duration of pulses coming back from the distance sensor

  //set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  //set button pin as input
  pinMode(modePin, INPUT_PULLUP);

}

void loop() {

// handle for when the mode button is pressed down

  while(digitalRead(modePin) == LOW){    //toggle to slide mode
    distance = getDistance();   //variable to store the distance measured by the sensor
    distanceDifference = distance - oldDistance;    // variable to store the change in distance
    oldPitch = oldDistance * 50;                    // variable to store the old pitch
    if(distance < 20 && abs(distanceDifference) > 0.8){  // max distance read consistantly is around 20 inches
      pitch = distance * 50;
      if(oldPitch < pitch){                   // handle for moving down pitch and glide there
        while(oldPitch < pitch){
          oldPitch += 0.1;
          tone(buzzerPin, oldPitch);
        }
      }
       else if(oldPitch > pitch){            //handle for moving up pitch and glide there
        while(oldPitch > pitch){
          oldPitch -= 0.1;
          tone(buzzerPin, oldPitch);
        }
       }
      // debugging
      Serial.print(distanceDifference);
      Serial.println(" in");      //print units after the distance
    }
  oldDistance = distance;
  delay(100);      //delay 100ms between each reading
  }

// handle for when the mode button isn't pressed down

  distance = getDistance();   //variable to store the distance measured by the sensor
  distanceDifference = distance - oldDistance;
  if(distance < 20 && abs(distanceDifference) > 0.4){
    pitch = distance * 50;
    tone(buzzerPin, pitch);

    //debugging
    Serial.print(distanceDifference);
    Serial.println(" in");      //print units after the distance
  }
  oldDistance = distance;
  delay(80);      //delay 80ms between each reading
}

//------------------FUNCTIONS-------------------------------

//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calcualtedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
                                          //pulse to bounce back to the sensor

  calcualtedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)

  return calcualtedDistance;              //send back the distance that was calculated
}
