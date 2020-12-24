#include <Servo.h> 

#define SERVO_PIN 2
#define SPEAKER_PIN 13
#define SOUND_PIN A0

Servo servo;

const int sampleWindow = 6; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() {
  servo.attach(SERVO_PIN);
  pinMode(SPEAKER_PIN,OUTPUT);
  digitalWrite(SPEAKER_PIN,LOW);
  
  Serial.begin(57600);
}

void loop() {
  //sweep();
  //delay(2000); 

//  chirp(); 
//  delay(2000);  
//  meow();
//  delay(2000);  
//  meow2();
//  mew();
//  delay(2000);    
//  ruff();
//  delay(2000);  
//  arf();
//  delay(2000);

//  rickroll(); 
//  delay(2000);


  //int sound_level = analogRead(SOUND_PIN);
  //Serial.println(sound_level);
  //delay(100);

  double volts = readMic();
  Serial.println(volts);

}

/*
 * SERVO
 */

void sweep()
{
  int pos;
  for(pos = 10; pos <= 170; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 170; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}


/*
 * SPEAKER
 */

void chirp() {  // Bird chirp
  for(uint8_t i=200; i>180; i--)
     playTone(i,9);
}
 
void meow() {  // cat meow (emphasis ow "me")
  uint16_t i;
  playTone(5100,50);        // "m" (short)
  playTone(394,180);        // "eee" (long)
  for(i=990; i<1022; i+=2)  // vary "ooo" down
     playTone(i,8);
  playTone(5100,40);        // "w" (short)
}
 
void meow2() {  // cat meow (emphasis on "ow")
  uint16_t i;
  playTone(5100,55);       // "m" (short)
  playTone(394,170);       // "eee" (long)
  delay(30);               // wait a tiny bit
  for(i=330; i<360; i+=2)  // vary "ooo" down
     playTone(i,10);
  playTone(5100,40);       // "w" (short)
}
 
void mew() {  // cat mew
  uint16_t i;
  playTone(5100,55);       // "m"   (short)
  playTone(394,130);       // "eee" (long)
  playTone(384,35);        // "eee" (up a tiny bit on end)
  playTone(5100,40);       // "w"   (short)
}


void ruff() {   // dog ruff
  uint16_t i;
  for(i=890; i<910; i+=2)     // "rrr"  (vary down)
     playTone(i,3);
  playTone(1664,150);         // "uuu" (hard to do)
  playTone(12200,70);         // "ff"  (long, hard to do)
}
 
void arf() {    // dog arf
  uint16_t i;
  playTone(890,25);          // "a"    (short)
  for(i=890; i<910; i+=2)    // "rrr"  (vary down)
     playTone(i,5);
  playTone(4545,80);         // intermediate
  playTone(12200,70);        // "ff"   (shorter, hard to do)
}

// play tone on a piezo speaker: tone shorter values produce higher frequencies
//  which is opposite beep() but avoids some math delay - similar to code by Erin Robotgrrl
void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
     digitalWrite(SPEAKER_PIN, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(SPEAKER_PIN, LOW);
     delayMicroseconds(tone1);
  }     
}

int c = 262;
int d = 294;
int e = 330;
int f = 349;
int g = 392;
int a = 440;
int b = 494;
int bf = 466;
int C = 523;
int frequency[145] = {
  f, g, c, g, a, C, bf, a, f, g, c, c, c, d, f, f, f, g, c, g, a, C, bf, a, f, g, c, e, f, f, 
  f, f, f, //33
  d, e, f, f, g, e, d, c, d, d, e, f, d, c, //47
  C, C, g, d, d, e, f, d, f, g, e, d, c, //64
  d, d, e, f, d, c, g, g, g, a, g, f, g, a, f, //80
  g, g, g, a, g, c, d, e, f, d, g, a, g,
  c, d, f, d, a, a, g, c, d, f, d, g, g, f, e, d, c, d, f, d, f, g, e, d, c, c, g, f,
  c, d, f, d, a, a, g, c, d, f, d, C, e, f, e, d, c, d, f, d, f, g, e, d, c, c, g, f
  };
int duration[145] = {
  620, 620, 410, 620, 620, 100, 100, 200, 620, 620, 1440, 100, 100, 100, 200, 100,
  620, 620, 410, 620, 620, 100, 100, 200, 620, 620, 410, 200, 200, 830, 100, 200, 510,
  200, 200, 200, 200, 200, 300, 100, 1660, 200, 200, 200, 200, 410, 200,
  410, 200, 1240, 200, 200, 200, 200, 200, 200, 200, 410, 200, 1240,
  200, 200, 200, 200, 200, 410, 200, 200, 200, 200, 830, 1030, 200, 200, 200,
  200, 200, 200, 200, 410, 1240, 200, 200, 200, 410, 200, 200, 620,
  120, 120, 120, 120, 360, 360, 720, 120, 120, 120, 120, 360, 360, 480, 120, 240, 120, 120, 120, 120,
  480, 240, 360, 120, 480, 240, 480, 960,
  120, 120, 120, 120, 360, 360, 720, 120, 120, 120, 120, 360, 360, 480, 120, 240, 120, 120, 120, 120,
  480, 240, 360, 120, 480, 240, 480, 960
  };

void rickroll(){ 
  for(int i=0; i<145; i++){ //run loop for all values of i 0 to __ 
    tone(SPEAKER_PIN, frequency[i]); //play tones in order from the frequency array
    delay(duration[i]);   //play all above tones for the corresponding duration in the duration array
    noTone(SPEAKER_PIN);   //turn off speaker for 30ms before looping back to the next note
    delay(10);
  }
}


// SOUND

double readMic() {
     unsigned long startMillis= millis();  // Start of sample window
     unsigned int peakToPeak = 0;   // peak-to-peak level
  
     unsigned int signalMax = 0;
     unsigned int signalMin = 1024;
     // collect data for sampleWindow mS
     while (millis() - startMillis < sampleWindow)
     {
        sample = analogRead(SOUND_PIN);
        if (sample < 1024)  // toss out spurious readings
        {
           if (sample > signalMax)
           {
              signalMax = sample;  // save just the max levels
           }
           else if (sample < signalMin)
           {
              signalMin = sample;  // save just the min levels
           }
        }
     }
     peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
     double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
     Serial.println(volts);
     return volts;

}
