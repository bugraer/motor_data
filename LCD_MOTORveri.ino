//https://www.robolinkmarket.com/096-inch-i2c-oled-ekran-128x64-beyaz-white?gclid=CjwKCAjw_-D3BRBIEiwAjVMy7Pv27eCLp2rc9fNr70s3dMJZFVJIkkiB6cA0GAK3cx5WfqbV-UXGcRoC2iAQAvD_BwE
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
char bufferX [20];
char bufferY [20];
char bufferZ [20];
double akim;
double hiz;
void setup() {
}

void loop() {
  akim=analogRead(A0);
  hiz=analogRead(A1);

  
  sprintf(bufferX, "      "Hiz"d/d");
  sprintf(bufferY, "      "Akim "A");
 
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
  delay(10);
  
}

void draw(void)
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 20, bufferX);
  u8g.drawStr( 0, 40, bufferY);
}
