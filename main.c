#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"

#include "../oled/i2c_helper.h"
#include "ssd1306.h"

char Rows[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
int n = sizeof(Rows) / sizeof(Rows[0]);

int main(void) {
    I2C3Config();
    DisplayInit();
    while(true){
        DisplayClear();
        for(int i = 0; i < 8; i++){
            SetCursor(5, i);
            DrawChar(Rows[i]);
            DrawHorizontalLine(i * 8, 0, 127);
        }
        for(int i = 0; i < 130; i = i + 10){
            SetCursor(i - 5, 1);
            char ColChar = '0' + i / 10;
            DrawChar(ColChar);
            DrawVerticalLine(i, 1, 64);
        }
        //DrawHorizontalLine(1, 0, 127);
        DisplayUpdate();
    }
}

//Problem seems to be in y, LCDHEIGHT limit
