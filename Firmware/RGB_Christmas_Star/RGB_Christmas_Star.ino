/*
 * Name: RGB_Christmas_Star
 * Author: EEJeffMan
 * Date: 11/24/19
 * 
 * Description:
 *    Control 150 RGB LEDs.
 *    
 *    Currently using WS2812 RGB LEDs.
 *    
 *    Started with code from RGB_Lights project.
 *    
 *    LED strip used: 16.4ft 150 pixel waterproof strip https://smile.amazon.com/gp/product/B01LSF4Q00/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1
 *    
 *    Start by proving out on the Arduino Pro Mini 5V/16MHz, may change to something else later...
 *    
 *    May not use the entire strip, but start by driving all of them to determine current draw and prove the concept. 
 *    
 *    RGB's use "FastLED" library, credit to tutorial in link below:
 *    https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/
 *     
 *    To prove the concept: start with 6 colors, indexed in this order:
 *      Purple
 *      Blue
 *      Red
 *      Orange
 *      Green
 *      Yellow
 *    
 *    MK I: LEDs illuminated all the time.
 *    
 *    11/24/19:     Created project yesterday, updated description. May get time to edit source code later...
 */

#include <FastLED.h>

#define NUM_LEDS      150   //6
#define LED_PIN       11
#define COLOR_ORDER   GRB

// color table

/*
 * Values curtesy of https://www.rapidtables.com/web/color/RGB_Color.html
 */

 #define RED_R  255
 #define RED_G  0
 #define RED_B  0

 #define GREEN_R  0
 #define GREEN_G  255
 #define GREEN_B  0

 #define BLUE_R 0
 #define BLUE_G 0 
 #define BLUE_B 255

 #define YELLOW_R 255
 #define YELLOW_G 255
 #define YELLOW_B 0

 #define PURPLE_R  127
 #define PURPLE_G  0
 #define PURPLE_B  255

 #define ORANGE_R  255
 #define ORANGE_G  128
 #define ORANGE_B  0   

 // LED index (aka order of colors)
 /*#define PURPLE_LED   0b00000001
 #define BLUE_LED     0b00000010
 #define RED_LED      0b00000100
 #define ORANGE_LED   0b00001000
 #define GREEN_LED    0b00010000
 #define YELLOW_LED   0b00100000

 // first proof of concept... hard code to one of the 6 colors defined below - variables red[], green[], and blue[]
 #define HARD_CODED_COLOR_INDEX   5
*/
 //#define led_pin 16

 void set_leds();//unsigned int led_configuration);

CRGB leds[NUM_LEDS];
/*
const unsigned int red[6] = {YELLOW_R,GREEN_R,PURPLE_R,BLUE_R,RED_R,ORANGE_R};
const unsigned int green[6] = {YELLOW_G,GREEN_G,PURPLE_G,BLUE_G,RED_G,ORANGE_G};
const unsigned int blue[6] = {YELLOW_B,GREEN_B,PURPLE_B,BLUE_B,RED_B,ORANGE_B};
*/
void setup() {

  unsigned int i;

  Serial.begin(9600);

  //pinMode(led_pin, OUTPUT);

  //digitalWrite(led_pin, LOW);
  
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  //set_leds(PURPLE_LED | BLUE_LED | RED_LED | ORANGE_LED | GREEN_LED | YELLOW_LED);
/*
  for (i=0;i<NUM_LEDS;i++)
  {
    // assign colors to each pixel.
    set_leds();
  }
*/
  //digitalWrite(led_pin,HIGH);

  //FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:

 // Fade in/fade out
  for(int j = 0; j < 3; j++ ) {
    memset(leds, 0, NUM_LEDS * 3);
    for(int k = 0; k < 256; k++) {
      for(int i = 0; i < NUM_LEDS; i++ ) {
        switch(j) {
          case 0: leds[i].r = k; break;
          case 1: leds[i].g = k; break;
          case 2: leds[i].b = k; break;
        }
      }
      FastLED.show();
      delay(3);
    }
    for(int k = 255; k >= 0; k--) {
      for(int i = 0; i < NUM_LEDS; i++ ) {
        switch(j) {
          case 0: leds[i].r = k; break;
          case 1: leds[i].g = k; break;
          case 2: leds[i].b = k; break;
        }
      }
      FastLED.show();
      delay(3);
    }
  }

  FastLED.show();
}

/*void set_leds()//unsigned int *led_configuration)
{
  / loop through bitmask to check if each LED should be on.
   * if it should be on, set the appropriate RGB values. 
   * if it shouldnt be on, set the RGB values to 0.
   * 
   * bitmask order follows that of the LED RGB const arrays.
   * 
   * 11/24/19 
   * Need to update this so that led_configuration is an array instead of a singla variable, to handle more pixels.
   * For now, a max of 150 pixels will be fine.         
   * 
   * change led_configuration to a pointer to an array
   * 
   * 
   /

  unsigned int i;
  //unsigned int temp_mask;

  //temp_mask = PURPLE_LED;   // TODO: instead of hard-coding to a value here, change it to a #define such as INITIAL_COLOR.
  for (i = 0; i<=NUM_LEDS; i++)
  {
    /if (led_configuration[j++] & temp_mask)
    {/
      leds[i] = CRGB(red[HARD_CODED_COLOR_INDEX], green[HARD_CODED_COLOR_INDEX], blue[HARD_CODED_COLOR_INDEX]);
    /}
    else
    {
      leds[i] = CRGB(0,0,0);
    }
    temp_mask = temp_mask << 1;   //next bitmask.
    /
  }
}*/

//end of file.
