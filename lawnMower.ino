
// Include Libraries
#include "Arduino.h"


// Pin Definitions
#define DCMOTORDRIVERL298_1_PIN_ENA  5
#define DCMOTORDRIVERL298_1_PIN_INT1  2
#define DCMOTORDRIVERL298_1_PIN_INT2  3
#define DCMOTORDRIVERL298_1_PIN_ENB 6
#define DCMOTORDRIVERL298_1_PIN_INT3  4
#define DCMOTORDRIVERL298_1_PIN_INT4  7
#define DCMOTORDRIVERL298_2_PIN_ENA 9
#define DCMOTORDRIVERL298_2_PIN_INT1  8
#define DCMOTORDRIVERL298_2_PIN_INT2  11
#define DCMOTORDRIVERL298_2_PIN_ENB 10
#define DCMOTORDRIVERL298_2_PIN_INT3  12
#define DCMOTORDRIVERL298_2_PIN_INT4  13
#define PUSHBUTTONMOMENTARY_1_PIN_2 A3
#define PUSHBUTTONMOMENTARY_2_PIN_2 A4
#define PUSHBUTTONMOMENTARY_3_PIN_2 A1
#define PUSHBUTTONMOMENTARY_4_PIN_2 A5



// Global variables and defines

// object initialization
//DCMDriverL298 dcMotorDriverL298_1(DCMOTORDRIVERL298_1_PIN_ENA,DCMOTORDRIVERL298_1_PIN_INT1,DCMOTORDRIVERL298_1_PIN_INT2,DCMOTORDRIVERL298_1_PIN_ENB,DCMOTORDRIVERL298_1_PIN_INT3,DCMOTORDRIVERL298_1_PIN_INT4);
//DCMDriverL298 dcMotorDriverL298_2(DCMOTORDRIVERL298_2_PIN_ENA,DCMOTORDRIVERL298_2_PIN_INT1,DCMOTORDRIVERL298_2_PIN_INT2,DCMOTORDRIVERL298_2_PIN_ENB,DCMOTORDRIVERL298_2_PIN_INT3,DCMOTORDRIVERL298_2_PIN_INT4);
Button pushButtonMomentary_1(PUSHBUTTONMOMENTARY_1_PIN_2);
Button pushButtonMomentary_2(PUSHBUTTONMOMENTARY_2_PIN_2);
Button pushButtonMomentary_3(PUSHBUTTONMOMENTARY_3_PIN_2);
Button pushButtonMomentary_4(PUSHBUTTONMOMENTARY_4_PIN_2);



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pushButtonMomentary_1.init();
    pushButtonMomentary_2.init();
    pushButtonMomentary_3.init();
    pushButtonMomentary_4.init();
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    /*
    if(menuOption == '1') {
    // L298N Motor Driver Board Module #1 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298_1.setMotorA(200,1);
    dcMotorDriverL298_1.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298_1.stopMotors();
    delay(2000);

    }
    else if(menuOption == '2') {
    // L298N Motor Driver Board Module #2 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298_2.setMotorA(200,1);
    dcMotorDriverL298_2.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298_2.stopMotors();
    delay(2000);

    }
    else*/ if(menuOption == '3') {
    // Momentary Push Button - Panel Mount (Red) #1 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButtonMomentary_1.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButtonMomentary_1Val = pushButtonMomentary_1.read();
    Serial.print(F("Val: ")); Serial.println(pushButtonMomentary_1Val);
    }
    else if(menuOption == '4') {
    // Momentary Push Button - Panel Mount (Red) #2 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButtonMomentary_2.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButtonMomentary_2Val = pushButtonMomentary_2.read();
    Serial.print(F("Val: ")); Serial.println(pushButtonMomentary_2Val);
    }
    else if(menuOption == '5') {
    // Momentary Push Button - Panel Mount (Red) #3 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButtonMomentary_3.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButtonMomentary_3Val = pushButtonMomentary_3.read();
    Serial.print(F("Val: ")); Serial.println(pushButtonMomentary_3Val);
    }
    else if(menuOption == '6') {
    // Momentary Push Button - Panel Mount (Red) #4 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButtonMomentary_4.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButtonMomentary_4Val = pushButtonMomentary_4.read();
    Serial.print(F("Val: ")); Serial.println(pushButtonMomentary_4Val);
    }
    
    
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) L298N Motor Driver Board Module #1"));
    Serial.println(F("(2) L298N Motor Driver Board Module #2"));
    Serial.println(F("(3) Momentary Push Button - Panel Mount (Red) #1"));
    Serial.println(F("(4) Momentary Push Button - Panel Mount (Red) #2"));
    Serial.println(F("(5) Momentary Push Button - Panel Mount (Red) #3"));
    Serial.println(F("(6) Momentary Push Button - Panel Mount (Red) #4"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {
            if(c == '1') 
          Serial.println(F("Now Testing L298N Motor Driver Board Module #1"));
        else if(c == '2') 
          Serial.println(F("Now Testing L298N Motor Driver Board Module #2"));
        else if(c == '3') 
          Serial.println(F("Now Testing Momentary Push Button - Panel Mount (Red) #1"));
        else if(c == '4') 
          Serial.println(F("Now Testing Momentary Push Button - Panel Mount (Red) #2"));
        else if(c == '5') 
          Serial.println(F("Now Testing Momentary Push Button - Panel Mount (Red) #3"));
        else if(c == '6') 
          Serial.println(F("Now Testing Momentary Push Button - Panel Mount (Red) #4"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
            }
        }
    }
