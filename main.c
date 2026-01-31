#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"

#include "../oled/i2c_helper.h"
#include "ssd1306.h"

char Rows[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
int n = sizeof(Rows) / sizeof(Rows[0]);

int main(void) {
    I2C3Config();
    DisplayInit();
    while(true){
        DisplayClear();
        DisplayInvert();
        //GridTest();
        LineWidthTest();
        DisplayUpdate();
    }
}

/*
    \brief Tests functionality of DrawChar and DrawPixel by drawing a grid of horizontal and vertical lines with grid number

    \param none
    \return none
*/

void GridTest(){
    for(int i = 0; i < 8; i++){
        SetCursor(5, i);
        DrawChar(Rows[i]);
        DrawHorizontalLine(i * 8, 0, 127);
    }
    for(int i = 0; i < 130; i = i + 10){
        if( i != 0){
            SetCursor(i + 2, 0);
            DrawChar(Rows[i / 10]);
        }
        DrawVerticalLine(i, 1, 64);
    }
}

/*
    \brief Tests functionality of changing line widths
    \param none
    \return none
*/

void LineWidthTest(){
    SetLineWidth(8);
    DrawVerticalLine(67, 0, 63);
    DrawHorizontalLine(4, 0, 120);
    SetLineWidth(4);
    DrawVerticalLine(23, 0, 63);
    DrawHorizontalLine(40, 20, 127);
}
