#ifndef _keypad
#define _keypad
/**********************************************************
 * keypad_screen.h
 **********************************************************/

int is_the_screen_touched();
int getX();
int getY();

int pressed_key_value();

void keypad_handler();

#endif
