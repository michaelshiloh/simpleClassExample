
/*
 * simpleClassExample: A very simple example showing how to create and use a class
 * 
 * The class in this example assumes a sensor attached to an analog input. 
 * The class provides the ability to take multiple readings
 * and then to report their average
 * 
 * This example code is in the public domain
 * 
 * 8 June 2017 - Michael Shiloh - Created
 */
 
const int SENSOR_1_PIN = A0;
const int SENSOR_2_PIN = A1;

// This is how many readings will be taken
const int NUM_SENSOR_READINGS = 10;

class Sensor {

    // Member variables
    int pinNumber;
    int readings[NUM_SENSOR_READINGS];

  public:

    // The function with the same name as the class is a special function called the "constructor".
    // You can think of it as the "Setup" function for the object
    // The constructor takes one argument, which is the pin number of this particular sensor
    Sensor(int x) {
      pinNumber = x;

      pinMode(pinNumber, INPUT);
    } // end of constructor

    void takeReadings() {
      for (int i = 0; i < NUM_SENSOR_READINGS; i++) {
        readings[i] = analogRead(pinNumber);
        delay(1); // pause after each analogRead() to allow it to do its work
      }
    } // end of takeReadings

    int getAverage() {
      int sum = 0;
      int average;

      for (int i = 0; i < NUM_SENSOR_READINGS; i++) {
        sum = sum + readings[i];
      }
      average = sum / NUM_SENSOR_READINGS ;
      return average;

    } // end of getAverage
}; // end of class Sensor


// Create two objects using the Sensor class
Sensor sensor1(SENSOR_1_PIN);
Sensor sensor2(SENSOR_2_PIN);

void setup () {
  Serial.begin(9600);
}

void loop() {

  // Take multiple readings from the two sensors represented by these objects
  sensor1.takeReadings();
  sensor2.takeReadings();

  // Print the average values of those readings
  Serial.print("Sensor 1: ");
  Serial.print(sensor1.getAverage());
  
  Serial.print(" Sensor 2: ");
  Serial.print(sensor2.getAverage());
  Serial.println();

  delay(500);
}



