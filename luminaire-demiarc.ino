//analog potentiometer with integrated on/off
//2812WS ledstrip w/FastLED & ATtiny85 °|°)
  
  #include <FastLED.h>
  
 
  #define NUM_LEDS 63 
  #define DATA_PIN 0// Data out to ledstrips
  
  int pot = A1;//from potentiometre (central pin)
  int clicpot = A3;//on/off clic from potentiometer.
  
  int brightness = 250;
  int onoffState = 0;
  
  // Define the array of leds
  //CRGB leds[NUM_LEDS];
  CRGBArray<NUM_LEDS> leds;//la variable leds est une array (un tableau) CRGB

  void setup() { 
  	//delay(3000); // in case we do something stupid. We dont want to get locked out.

  	FastLED.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS).setCorrection( TypicalSMD5050 );
  
    pinMode (pot, INPUT);
    pinMode (clicpot, INPUT);
  }
  
  
  
  void loop() { 
  brightness =map(analogRead(pot), 0, 1023, 0, 255);
  //Serial.prinln(brightness);

  onoffState=analogRead(clicpot);
 
 // First, clear the existing led values
 FastLED.clear();
        
  leds = CRGB::White;
 
 if (onoffState > 1){  
      //set britghness
      FastLED.setBrightness(brightness);
   }
      else{
      FastLED.setBrightness(0);
      }
      
      // Show the leds
      FastLED.show(); 
    
      // Wait a little bit before we loop around and do it again
      FastLED.delay(10);  
      }

      
      
   

 
