const unsigned long updateRate = 50; // micro seconds
int frequency = 100;
const int samples = 256;
uint8_t sineTable[samples];
float phase = 0;
float step = 0;
unsigned long time_of_last_update = 0;
unsigned long current_time = 0;



#define DAC 25

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter a new frequency value:");
  calculateSineTable();
  calculateStep();

}

void calculateSineTable() {
  for (int i = 0; i < samples; i++) {
      float angle = ((2 * PI * i) / samples);
      sineTable[i] = 128 +(50*sin(angle));
    }
}

void calculateStep () {
  step = (frequency * float(samples) / (1000000/updateRate));
}


void loop() {
  // put your main code here, to run repeatedly
  if (Serial.available() > 0) {
    // Read the incoming integer
    int incomingFrequency = Serial.parseInt();
    
    // Clear out any leftover newline/carriage return characters
    while (Serial.available() > 0) {
      Serial.read();
    }
    if (incomingFrequency > 0) {
      frequency = incomingFrequency;
      calculateStep();
    }
  }


  current_time = micros();
  if (current_time - time_of_last_update >= updateRate) {
    dacWrite(DAC, sineTable[(int)phase]);
    phase += step;
    time_of_last_update +=updateRate;
    if (phase >= samples) phase -=samples;
  }
}
