#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h> 
#endif

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

#define Uceva_logo_width 120
#define Uceva_logo_height 37
static unsigned char Uceva_logo_bits[] = {
   0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0xfc, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xf8,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfe, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x7e, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0xe0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0xc0,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x08, 0xe0,
   0x03, 0x00, 0x3c, 0xf0, 0xc0, 0x7f, 0xf8, 0x7f, 0x3c, 0xe0, 0xf1, 0x03,
   0x3c, 0x18, 0xf0, 0xe1, 0x1f, 0x3c, 0xf0, 0xe0, 0xff, 0xf9, 0x7f, 0x7c,
   0xe0, 0xf1, 0x03, 0x7c, 0x18, 0xf8, 0xf1, 0x1f, 0x3c, 0xf0, 0xf0, 0xf1,
   0xf9, 0x7f, 0x78, 0xe0, 0xf0, 0x07, 0x78, 0x70, 0xfc, 0xf0, 0x0f, 0x3c,
   0xf0, 0xf0, 0x60, 0x78, 0x00, 0x78, 0xf0, 0x70, 0x07, 0xf0, 0xe1, 0x7f,
   0xf8, 0x07, 0x3c, 0xf0, 0x78, 0x00, 0x78, 0x00, 0x78, 0xf0, 0x38, 0x07,
   0xf0, 0xc1, 0x3f, 0xf8, 0x03, 0x3c, 0xf0, 0x78, 0x00, 0xf8, 0x00, 0xf0,
   0xf0, 0x38, 0x0f, 0xe0, 0x03, 0x0f, 0xfc, 0x03, 0x3c, 0xf0, 0x78, 0x00,
   0xf8, 0x7f, 0xf0, 0x70, 0x3c, 0x0e, 0xe0, 0x07, 0x00, 0xfe, 0x01, 0x3c,
   0xf0, 0x78, 0x00, 0xf8, 0x7f, 0xe0, 0x78, 0x1c, 0x1e, 0xc0, 0x0f, 0x00,
   0xff, 0x00, 0x3c, 0xf0, 0x78, 0x00, 0x78, 0x00, 0xe0, 0x39, 0x1e, 0x1c,
   0x80, 0x1f, 0xc0, 0xff, 0x00, 0x3c, 0xf0, 0x78, 0x40, 0x78, 0x00, 0xc0,
   0x39, 0x3e, 0x3e, 0x00, 0xff, 0xff, 0x7f, 0x00, 0x78, 0xf0, 0xf0, 0xe0,
   0x79, 0x00, 0xc0, 0x1f, 0xfe, 0x3f, 0x00, 0xff, 0xff, 0x3f, 0x00, 0xf8,
   0xf8, 0xf0, 0xf1, 0x79, 0x00, 0xc0, 0x1f, 0x1e, 0x3c, 0x00, 0xfe, 0xff,
   0x1f, 0x00, 0xf0, 0x7f, 0xe0, 0xff, 0xf8, 0xff, 0xc0, 0x1f, 0x0f, 0x7c,
   0x00, 0xfe, 0xff, 0x0f, 0x00, 0xe0, 0x3f, 0xc0, 0x7f, 0xf8, 0xff, 0x80,
   0x9f, 0x0f, 0x78, 0x00, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00 };


void setup(void){
  u8g2.begin();
}

void loop(void){
  u8g2.clearBuffer();
  /*
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "Hellooo World!");
  
  */
  u8g2.drawXBM(0,10,Uceva_logo_width,Uceva_logo_height,Uceva_logo_bits);
  u8g2.sendBuffer();
  delay(1000);
}