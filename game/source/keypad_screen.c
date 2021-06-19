/**********************************************************
 * keypad_screen.c
 **********************************************************/

/* 
 * Añadir los includes que sean necesarios
 **/
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "backgrounds.h"
#include "functions.h"

/* 
 * Esta función consulta si se ha tocado la pantalla táctil
 **/
int is_the_screen_touched() {
	touchPosition screen_pos;
	touchRead(&screen_pos);
  	return !(screen_pos.px==0 && screen_pos.py==0);
} // is_the_screen_touched()

int getX() {
	touchPosition screen_pos;
	touchRead(&screen_pos);
	return screen_pos.px;
}

int getY() {
	touchPosition screen_pos;
	touchRead(&screen_pos);
	return screen_pos.py;
}


/* 
 * Esta función tiene que devolver el valor de la tecla pulsada
 **/
int pressed_key_value() {
    /* 
 	 * Devuelve el valor asociado a la tecla pulsada:
 	 * A=0;    -B=1;  SELECT=2; -START=3; RIGHT=4; 
 	 * -LEFT=5; UP=6; DOWN=7;   R=8;     L=9
 	 * -1 en otros casos
 	 **/
	int val;
	switch (KEYS_DAT) {
		case 0x03FE: val=A;
			break;
		case 0x03FD: val=B;
			break;
		case 0x03FB: val=SELECT;
			break;
		case 0x03F7: val=START;
			break;
		case 0x03EF: val=RIGHT;
			break;
		case 0x03ED: val=RIGHTB;
			break;
		case 0x03DF: val=LEFT;
			break;
		case 0x03DD: val=LEFTB;
			break;
		case 0x03BF: val=UP;
			break;
		case 0x037F: val=DOWN;
			break;
		case 0x02FF: val=R;
			break;
		case 0x01FF: val=L;
			break;
		default: val=-1;
			break;
	}
	return val;

} // pressed_key_value()

/* 
 * Rutina de atención a la interrupción del teclado
**/
void keypad_handler() {
	pressedKeyInterrupting();

	switch (state) {
		case BEGIN:
			break;
		case MENU:
			// Menu controls
			if (pressed_key_value() == UP) if (menuState > 0) {
				menuState--;
				menu_animation();
			}
			if (pressed_key_value() == DOWN) if (menuState < 2) {
				menuState++;
				menu_animation();
			}

			// Game start
			if (pressed_key_value() == START && menuState == 0) {
				setUpGame();
				state = GAME;
			}		
			break;
		case GAME:
			// Shoot
			if (pressed_key_value() == B ||
			    pressed_key_value() == LEFTB ||
			    pressed_key_value() == RIGHTB) shoot();

			// Pause by hitting <START>
			if (pressed_key_value() == START) pausa();

			break;	
		case PAUSE:
			// Resume		
			if (pressed_key_value() == DOWN) if (pauseState == 0) {
				display_pause2();
				pauseState = 1;
			}
			if (pressed_key_value() == UP) if (pauseState == 1) {
				display_pause1();
				pauseState = 0;
			}
			if (pressed_key_value() == B) {
				if (pauseState == 0) {
					resume();
				} else state = MENU;
			}
			break;
		case GAMEOVER:
			break;
		case SCORE:
			break;
	}
} // keypad_handler()


