/*
 * Author: Learn With Coders Cafe
 * Date: 04 May 2024
 * Description: Arduino code for building a simple luxmeter using LDR module and an Arduino Nano.
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

const int LDR_PIN = A0;
const int MAX_LUX = 1000; // Maximum lux value

void setup() 
{
  
  // Initialize the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x64

  // Set up the LDR pin
  pinMode(LDR_PIN, INPUT);
  
}

void loop() 
{
  
  // Read the raw sensor value
  int sensorValue = analogRead(LDR_PIN);

  // Map the sensor value to lux range
  float lux = map(sensorValue, 0, 1023, MAX_LUX,0); // Adjust 1023 according to your LDR's range

  // Clear display
  display.clearDisplay();

  // Display "Lux" title
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 0);
  display.print("Lux:");

  // Draw lux meter outline
  display.drawRect(10, 20, 100, 10, SSD1306_WHITE); // Reduced width to 10 pixels

  // Calculate width of lux box based on lux value
  int luxWidth = map(lux, 0, MAX_LUX, 0, 100); // Adjusted to match rectangle width

  // Draw lux box
  display.fillRect(10, 20, luxWidth, 10, SSD1306_WHITE);

  // Display OLED
  display.display();
  delay(1000); // Delay for stability, adjust as needed
  
}
