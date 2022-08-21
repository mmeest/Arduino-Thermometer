#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>

// Temperature sensor connection
#define ONE_WIRE_BUS 2
// LED strip
#define NLED 59
#define PIN_1 8
#define PIN_2 7

Adafruit_NeoPixel pixels_1 = Adafruit_NeoPixel(NLED, PIN_1, NEO_GRB+NEO_KHZ800);
Adafruit_NeoPixel pixels_2 = Adafruit_NeoPixel(NLED, PIN_2, NEO_GRB+NEO_KHZ800);

// OneWire connection 
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

// Variable for moving temperature display on LED strip
int change = -5;
int deviceCount = 0;
float tempC;
int counter = 10;

void setup(void)
{
Serial.println("Found ");
Serial.println("	#include <OneWire.h>");
Serial.println("#include <DallasTemperature.h>");
Serial.println("#include <Adafruit_NeoPixel.h>");
Serial.println("#define ONE_WIRE_BUS 2");
Serial.println("#define NLED 59");
Serial.println("#define PIN_1 8");
Serial.println("#define PIN_2 7");
Serial.println("Adafruit_NeoPixel pixels_1 = Adafruit_NeoPixel(NLED, PIN_1, NEO_GRB+NEO_KHZ800);");
Serial.println("Adafruit_NeoPixel pixels_2 = Adafruit_NeoPixel(NLED, PIN_2, NEO_GRB+NEO_KHZ800);");
Serial.println("OneWire oneWire(ONE_WIRE_BUS);  ");
Serial.println("DallasTemperature sensors(&oneWire);");
Serial.println("int change = -5;");
Serial.println("int deviceCount = 0;");
Serial.println("float tempC;");
Serial.println("int counter = 10;");
Serial.println("void setup(void)");
Serial.println("{");
Serial.println("  sensors.begin();  // Start up the library");
Serial.println("  Serial.begin(9600);");
Serial.println("  pixels_1.begin();");
Serial.println("  pixels_2.begin();");
Serial.println("  pixels_1.show();");
Serial.println("  pixels_2.show();");
Serial.println("  deviceCount = sensors.getDeviceCount();");
Serial.println("}");
Serial.println("void loop(void)");
Serial.println("{ ");
Serial.println("  sensors.requestTemperatures(); ");
Serial.println("  for (int i = 0;  i < deviceCount;  i++)");
Serial.println("  {");
Serial.println("    tempC = sensors.getTempCByIndex(i);");
Serial.println("  }");
Serial.println("  delay(1000);");
Serial.println("    for (int i = 0; i <= 59; i++){  // 59 LEDs on current project");
Serial.println("    int r_1 = 0;");
Serial.println("    int r_2 = 0;");
Serial.println("    int g_1 = i-19 - change;");
Serial.println("    int g_2 = i-19 - change;");
Serial.println("    int b_1 = (29 - i + change)/2;");
Serial.println("    int b_2 = (29 - i + change)/2;");
Serial.println("    if(i > 28 + change){");
Serial.println("      r_1 = (i - 29 - change)/2;");
Serial.println("      r_2 = (i - 29 - change)/2;");
Serial.println("      g_1 = (40 - i + change)/2;");
Serial.println("      g_2 = (40 - i + change)/2;");
Serial.println("      b_1 = 0;");
Serial.println("      b_2 = 0;");
Serial.println("    }");
Serial.println("      if(counter <= 0){");
Serial.println("      	r_1 = random(0, 10);");
Serial.println("        r_2 = random(0, 10);");
Serial.println("        g_1 = random(0, 10);");
Serial.println("        g_2 = random(0, 10);");
Serial.println("        b_1 = random(0, 10);");
Serial.println("        b_2 = random(0, 10);");
Serial.println("        counter = random(1, 10);");
Serial.println("      }");
Serial.println("    if(i == 29 + change){ g_1 = 30; g_2 = 30; }");
Serial.println("      if((i % 5) == 0){");
Serial.println("      r_1 *= 2;");
Serial.println("      r_2 *= 2;");
Serial.println("      g_1 *= 2;");
Serial.println("      g_2 *= 2;");
Serial.println("      b_1 *= 2;");
Serial.println("      b_2 *= 2;");
Serial.println("      }");
Serial.println("    if(r_1 < 1){ r_1 = 0; }");
Serial.println("    if(r_2 < 1){ r_2 = 0; }");
Serial.println("    if(g_1 < 1){ g_1 = 0; }");
Serial.println("    if(g_2 < 1){ g_2 = 0; }");
Serial.println("    if(b_1 < 1){ b_1 = 0; }");
Serial.println("    if(b_2 < 1){ b_2 = 0; }");
Serial.println("    if(i > 29 + sensors.getTempCByIndex(0) + change){ r_1 = 0; g_1 = 0; b_1 = 0; }");
Serial.println("    if(i > 29 + sensors.getTempCByIndex(1) + change){ r_2 = 0; g_2 = 0; b_2 = 0; }");
Serial.println("    pixels_1.setPixelColor(i,r_1,g_1,b_1);");
Serial.println("    pixels_2.setPixelColor(i,r_2,g_2,b_2);");
Serial.println("    pixels_1.show();");
Serial.println("    pixels_2.show();");
Serial.println("    delay(20);");
Serial.println("  }  ");
Serial.println("  counter -= 1;");
Serial.println("  delay(10000);");
Serial.println("  for(int j = 0; j <= 60; j++){");
Serial.println("    pixels_1.setPixelColor(j,0,0,0);");
Serial.println("    pixels_2.setPixelColor(j,0,0,0);");
Serial.println("    pixels_1.show();");
Serial.println("    pixels_2.show();");
Serial.println("  }");
Serial.println("}");
	
	
  sensors.begin();  // Start up the library
  Serial.begin(9600);
  pixels_1.begin();
  pixels_2.begin();
  pixels_1.show();
  pixels_2.show();
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");
}

void loop(void)
{ 
  // Send command to all the sensors for temperature conversion
  sensors.requestTemperatures(); 
  
  // Display temperature from each sensor
  for (int i = 0;  i < deviceCount;  i++)
  {
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    tempC = sensors.getTempCByIndex(i);
    Serial.print(tempC);
    Serial.print((char)176);//shows degrees character
    Serial.print("C  |  ");
    Serial.print(DallasTemperature::toFahrenheit(tempC));
    Serial.print((char)176);//shows degrees character
    Serial.println("F");
  }
  
  Serial.println("");
  delay(1000);

    for (int i = 0; i <= 59; i++){  // 59 LEDs on current project
    int r_1 = 0;
    int r_2 = 0;
    int g_1 = i-19 - change;
    int g_2 = i-19 - change;
    int b_1 = (29 - i + change)/2;
    int b_2 = (29 - i + change)/2;
    
    if(i > 28 + change){
      r_1 = (i - 29 - change)/2;
      r_2 = (i - 29 - change)/2;
      g_1 = (40 - i + change)/2;
      g_2 = (40 - i + change)/2;
      b_1 = 0;
      b_2 = 0;
    }
      
            // Easter Egg
      if(counter <= 0){
      	r_1 = random(0, 10);
        r_2 = random(0, 10);
        g_1 = random(0, 10);
        g_2 = random(0, 10);
        b_1 = random(0, 10);
        b_2 = random(0, 10);
        counter = random(1, 10);
      }

    if(i == 29 + change){ g_1 = 30; g_2 = 30; }
      
      if((i % 5) == 0){
      r_1 *= 2;
      r_2 *= 2;
      g_1 *= 2;
      g_2 *= 2;
      b_1 *= 2;
      b_2 *= 2;
      }

    if(r_1 < 1){ r_1 = 0; }
    if(r_2 < 1){ r_2 = 0; }
    if(g_1 < 1){ g_1 = 0; }
    if(g_2 < 1){ g_2 = 0; }
    if(b_1 < 1){ b_1 = 0; }
    if(b_2 < 1){ b_2 = 0; }
      


    if(i > 29 + sensors.getTempCByIndex(0) + change){ r_1 = 0; g_1 = 0; b_1 = 0; }
    if(i > 29 + sensors.getTempCByIndex(1) + change){ r_2 = 0; g_2 = 0; b_2 = 0; }

    pixels_1.setPixelColor(i,r_1,g_1,b_1);
    pixels_2.setPixelColor(i,r_2,g_2,b_2);
    pixels_1.show();
    pixels_2.show();

    Serial.print(r_1);
    Serial.print(" ");
    Serial.print(g_1);
    Serial.print(" ");
    Serial.println(b_1);
    delay(20);
  }  
  
  counter -= 1;
  delay(10000);
  for(int j = 0; j <= 60; j++){
    pixels_1.setPixelColor(j,0,0,0);
    pixels_2.setPixelColor(j,0,0,0);
    pixels_1.show();
    pixels_2.show();
  }
}
