#ifndef _DISPLAY_MENU_1602_H
#define _DISPLAY_MENU_1602_H
#include "Arduino.h"
#include <Wire.h>
// The I2C LCD library
#include <LiquidCrystal_I2C.h>
// The menu wrapper library
#include <LiquidMenu.h>
// The I2C LCD object
#include "Button.h"

#include "sprayMotor.h"
#include "led.h"
SprayMotor sprayObj;
Led ledObj;
//OK  D5
//LEFT  D6
//RIGHT D7
//BACK  D8

// Button objects instantiation
const bool pullup = false;
Button left(6, pullup);
Button right(7, pullup);
//Button up(8, pullup);
//Button down(9, pullup);
Button enter(5, pullup);

LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidLine welcome_line1(1, 0, "MANHOLE ");
LiquidLine welcome_line2(1, 1, "GAS DETECTION");
LiquidScreen welcome_screen(welcome_line1, welcome_line2);
LiquidLine gasLine1(1, 0, "METH", "ALCOHOL");
LiquidLine gasLine2(1, 1, " abc", "abc");
LiquidScreen GASSCREEN1(gasLine1, gasLine2);
LiquidLine gasLine3(1, 0, "CO", "H2S");
LiquidLine gasLine4(1, 1, " abc", "abc");
LiquidScreen GASSCREEN2(gasLine3, gasLine4);
LiquidLine clickLine(1,0, " Click OK to");
LiquidLine spray_line(1, 1, " SPRAY");
LiquidLine demo_line(1, 1, " DEMO");
LiquidScreen screen3(clickLine,spray);
LiquidScreen screen4(clickLine,demo);

LiquidMenu menu(lcd);

class displayMenu1602
{

public:
    void begin()
    {

        Serial.begin(9600);
        sprayObj.begin();
        ledObj.begin();

        // This is the I2C LCD object initialization.
        lcd.init();
        lcd.backlight();
        delay(500);
        lcd.noBacklight();
        delay(500);
        lcd.backlight();
        demo_line.attach_function(1,showDemo);
        spray_line.attach_function(1,SprayMotor);
        // Menu initialization.
        menu.init();
        // This is the method used to add a screen object to the menu.
        menu.add_screen(welcome_screen);
        menu.add_screen(GASSCREEN1);
        menu.add_screen(GASSCREEN2);
        menu.add_screen(screen3);
        menu.add_screen(screen4);
        menu.update();
    }
    void sprayMotor()
    {
        sprayObj.motor(50);
        ledObj.Blue(50);

    }
    void showDemo()
    {
        //turn led red
        ledObj.Red(1000);
        //send message with values
        
    }
    void runMenu()
    {
        // Check all the buttons
        if (right.check() == LOW)
        {
            Serial.println(F("RIGHT button pressed"));
            menu.next_screen();
        }
        if (left.check() == LOW)
        {
            Serial.println(F("LEFT button pressed"));
            menu.previous_screen();
        }
        if (enter.check() == LOW)
        {
            Serial.println(F("ENTER button pressed"));
            // Switches focus to the next line.
            menu.switch_focus();
            //get the spray system running
        }
    }
};

#endif //_DISPLAY_MENU_1602_H