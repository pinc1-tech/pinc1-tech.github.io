// 2026 pinc1
// Turn on a random PWM pin for one second at a random brightness, then pick a new random PWM pin. If the new PWM pin picked is already on, turn it off.
// pinc1-tech.github.io


int pwms[] = { 6, 7, 8, 10 };
int pwmLength = 4;
const int DELAY_TIME = 1000;
bool state[] = { false, false, false, false };

void setup() {

  randomSeed(analogRead(0));
 for (int i = 0; i < pwmLength; i++) 
    pinMode(pwms[i], OUTPUT);

}

void loop() {
    int i = random(0, pwmLength);  // assigning random value for PWM pin for one second from the four options

    if (!state[i]) {                         // if pin is off (it is false)
      analogWrite(pwms[i], random(1, 256));  // turn it on to a random brightness
      state[i] = true;                       // changes state to true (it is on)

    } else {                    // whene pin is not false (when it is on)
      analogWrite(pwms[i], 0);  // turn it off
      state[i] = false;         //change it to false
    }

    delay(DELAY_TIME);
}

