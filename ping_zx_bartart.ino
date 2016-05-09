#include <Wire.h>
#include <ZX_Sensor.h>
//#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Constants
const int ZX_ADDR = 0x10;  // ZX Sensor I2C address

// Global Variables
ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);
uint8_t x_pos;
uint8_t z_pos;

//int potPin = A0;  // potentiometer
//int potVal = 0;

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define P1             3
#define P2             4
#define P3             5
#define P4             6
#define P5             7
#define P6             8
#define P7             9
#define NUMPIXELS      1

Adafruit_NeoPixel px1 = Adafruit_NeoPixel(NUMPIXELS, P1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel px2 = Adafruit_NeoPixel(NUMPIXELS, P2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel px3 = Adafruit_NeoPixel(NUMPIXELS, P3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel px4 = Adafruit_NeoPixel(NUMPIXELS, P4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel px5 = Adafruit_NeoPixel(NUMPIXELS, P5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel px6 = Adafruit_NeoPixel(NUMPIXELS, P6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel px7 = Adafruit_NeoPixel(NUMPIXELS, P7, NEO_GRB + NEO_KHZ800);

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int x;
int z;
int p1b = 1;
int p2b = 1;
int p3b = 1;
int p4b = 1;
int p5b = 1;
int p6b = 1;
int p7b = 1;


void setup() {
  
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  zx_sensor.init();
  /*
  uint8_t ver; 

  if ( zx_sensor.init() ) {
    Serial.println("ZX Sensor initialization complete");
  } else {
    Serial.println("Something went wrong during ZX Sensor init!");
  }

  ver = zx_sensor.getModelVersion();
  if ( ver == ZX_ERROR ) {
    Serial.println("Error reading model version number");
  } else {
    Serial.print("Model version: ");
    Serial.println(ver);
  }
  if ( ver != ZX_MODEL_VER ) {
    Serial.print("Model version needs to be ");
    Serial.print(ZX_MODEL_VER);
    Serial.print(" to work with this library. Stopping.");
    while(1);
  }
  
  // Read the register map version and ensure the library will work
  ver = zx_sensor.getRegMapVersion();
  if ( ver == ZX_ERROR ) {
    Serial.println("Error reading register map version number");
  } else {
    Serial.print("Register Map Version: ");
    Serial.println(ver);
  }
  if ( ver != ZX_REG_MAP_VER ) {
    Serial.print("Register map version needs to be ");
    Serial.print(ZX_REG_MAP_VER);
    Serial.print(" to work with this library. Stopping.");
    while(1);
  }
  */
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  px1.begin(); // This initializes the NeoPixel library.
  px2.begin();
  px3.begin();
  px4.begin();
  px5.begin();
  px6.begin();
  px7.begin();
}

void loop() {

  // send data via serialport
  // using substring and delimiter
//  if(sonar.ping_cm()){
//    Serial.print("{\"ping\":");
//    Serial.print(sonar.ping_cm());
//    Serial.println("}");
//  }
  if ( zx_sensor.positionAvailable() ) {
    x_pos = zx_sensor.readX();
    if ( x_pos != ZX_ERROR ) {
      Serial.print("{\"x\":");
      Serial.print(x_pos);
      Serial.println("}");
      x = x_pos;
    }
    z_pos = zx_sensor.readZ();
    if ( z_pos != ZX_ERROR ) {
      Serial.print("{\"z\":");
      Serial.print(z_pos);
      Serial.println("}");
      z = z_pos;
    }
  }
//  potVal = analogRead(potPin);
//  Serial.println(potVal);  

/*  
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  // If there is position data available, read and print it
  if ( zx_sensor.positionAvailable() ) {
    x_pos = zx_sensor.readX();
    if ( x_pos != ZX_ERROR ) {
      Serial.print("X: ");
      Serial.print(x_pos);
      Serial.print("Ping: ");
      Serial.println(sonar.ping_cm());
    }
    z_pos = zx_sensor.readZ();
    if ( z_pos != ZX_ERROR ) {
      Serial.print(" Z: ");
      Serial.println(z_pos);
    }
  }
*/
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
 //for(int i=0;i<NUMPIXELS;i++){
    
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    px1.setPixelColor(0, px1.Color(255,0,255)); // magenta
    px1.show();
    //px1.setBrightness(0);
    px2.setPixelColor(0, px2.Color(0,0,255));   // blue
    px2.show();
    //px2.setBrightness(0);
    px3.setPixelColor(0, px3.Color(0,125,255)); // ocean
    px3.show();
    //px3.setBrightness(0);
    px4.setPixelColor(0, px4.Color(0,255,125)); // turquoise
    px4.show();
    //px4.setBrightness(0);
    px5.setPixelColor(0, px5.Color(0,255,0));   // green
    px5.show();
    //px5.setBrightness(0);
    px6.setPixelColor(0, px6.Color(255,255,0)); // yellow
    px6.show();
    //px6.setBrightness(0);
    px7.setPixelColor(0, px7.Color(255,0,0));   // red
    px7.show();
    //px7.setBrightness(0);
    if(z < 30){
      p1b++; //= 64;
      p2b++; //= 64;
      p3b++; //= 64;
      p4b++; //= 64;
      p5b++; //= 64;
      p6b++; //= 64;
      p7b++; //= 64;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else{
    if(x < 34){
      p1b = 0;
      p2b = 0;
      p3b = 0;
      p4b = 0;
      p5b = 0;
      p6b = 16;
      p7b = 64;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else if(x < 68){
      p1b = 0;
      p2b = 0;
      p3b = 0;
      p4b = 0;
      p5b = 16;
      p6b = 64;
      p7b = 16;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else if(x < 102){
      p1b = 0;
      p2b = 0;
      p3b = 0;
      p4b = 16;
      p5b = 64;
      p6b = 16;
      p7b = 0;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else if(x < 136){
      p1b = 0;
      p2b = 0;
      p3b = 16;
      p4b = 64;
      p5b = 16;
      p6b = 0;
      p7b = 0;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else if(x < 171){
      p1b = 0;
      p2b = 16;
      p3b = 64;
      p4b = 16;
      p5b = 0;
      p6b = 0;
      p7b = 0;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else if(x < 205){
      p1b = 16;
      p2b = 64;
      p3b = 16;
      p4b = 0;
      p5b = 0;
      p6b = 0;
      p7b = 0;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
    else{
      p1b = 64;
      p2b = 16;
      p3b = 0;
      p4b = 0;
      p5b = 0;
      p6b = 0;
      p7b = 0;
      px7.setBrightness(p7b);
      px7.show();
      px6.setBrightness(p6b);
      px6.show();
      px5.setBrightness(p5b);
      px5.show();
      px4.setBrightness(p4b);
      px4.show();
      px3.setBrightness(p3b);
      px3.show();
      px2.setBrightness(p2b);
      px2.show();
      px1.setBrightness(p1b);
      px1.show();
    }
//    if(p1b <= 1){
//      p1b = 0;  
//    }
//    else if(p1b >= 63){
//      p1b = 64;
//    }
//    if(p2b <= 1){
//      p2b = 0;  
//    }
//    else if(p2b >= 63){
//      p2b = 64;
//    }
//    if(p3b <= 1){
//      p3b = 0;  
//    }
//    else if(p3b >= 63){
//      p3b = 64;
//    }
//    if(p4b <= 1){
//      p4b = 0;  
//    }
//    else if(p4b >= 63){
//      p4b = 64;
//    }
//    if(p5b <= 1){
//      p5b = 0;  
//    }
//    else if(p5b >= 63){
//      p5b = 64;
//    }
//    if(p6b <= 1){
//      p6b = 0;  
//    }
//    else if(p6b >= 63){
//      p6b = 64;
//    }
//    if(p7b <= 1){
//      p7b = 0;  
//    }
//    else if(p7b >= 63){
//      p7b = 64;
//    }
    }
  //}
}
