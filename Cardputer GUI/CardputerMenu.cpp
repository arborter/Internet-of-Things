#include "M5Cardputer.h"
#include "M5Unified.h"

// SCREEN IS 240 px X 135 px

const int X = 0;
const int Y = 0;

int current_index_pstn = 0;
int start_index_pstn = 0;
int last_index_pstn = 1;

const char* menu[] = 
{
  "OPTION 1",
  "OPTION 2"
  };

void setup() {
  M5Cardputer.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(TFT_GREEN);
  M5.Lcd.setTextWrap(true, false);
}

void loop() {
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange()) {
        if (M5Cardputer.Keyboard.isPressed()) {
          change_option();
        }
    }
}
 
void change_option(){
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(2);

  int frame_x = 240;
  int frame_y = 0;

  M5.Lcd.setTextColor(TFT_GREEN);
  if (current_index_pstn != last_index_pstn) {
    // RECTANGLE AROUND MENU ITEMS
    M5.Lcd.drawRect(X, Y, frame_x, 16, PINK);
    M5.Lcd.print(menu[current_index_pstn]);
    M5.Lcd.print("\n");
  } else {
    M5.Lcd.drawRect(X, 16, frame_x, 16, PINK);
    M5.Lcd.print(menu[last_index_pstn]);
    M5.Lcd.print("\n");
  }
  current_index_pstn ++;
}