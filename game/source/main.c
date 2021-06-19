/********************************************************** 
 * main.c
 *
 * Este codigo se ha implementado basandose en el ejemplo 
 * "Simple sprite demo" de dovoto y otro de Jaeden Amero
 **********************************************************/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	    // srand, rand,...
#include <unistd.h>
#include <time.h>       // time 

#include "backgrounds.h"
#include "controllers.h"
#include "defines.h"
#include "keypad_screen.h"
#include "sprites.h"
#include "timers.h"
#include "functions.h"

/* 
 * Variables globales
 **/
int ticks;
int segs;

int x, y;

int state = BEGIN;
int menuState = 0;
int menuN = 0;

int countdown;
int score;

int gameOverSegs;
int scoreSegs;

int ALIENS_SIZE = 30;
int PROJECTILES_SIZE = 10;
int EPROJECTILES_SIZE = 10;

int endReason;


/* 
 * main()
 **/
int main() {

    interrupts_setting();

    /* 
 	 * Poner en marcha el motor grafico 2D.
 	 **/
    powerOn(POWER_ALL_2D); // <nds.h>

    /* 
     * Establecer la pantalla inferior como principal, inicializar 
     * el sistema grafico y configurar el sistema de fondos. 
     **/
    lcdMainOnBottom(); // <nds.h>
    init_video();
    init_background();

    /* 
 	 * Inicializar memoria de sprites y guardar en ella los sprites.
 	 **/
    init_sprite_memory();
    alloc_sprites_in_memory();

    /* 
 	 * Establecer las paletas para los sprites.
 	 **/
    set_main_palette();
    set_secondary_palette();

    /* Inicializa la consola (superior) de texto. 
     * Nota.- Para borrar la pantalla existe la funcion consoleClear() 
     **/
    consoleDemoInit(); // <nds.h>

    /* 
     * Para inicializar el generador de numeros aleatorios en funcion de una semilla,
	 * en este caso time(NULL). srand() solo se suele activar una vez por ejecucion y
	 * no devuelve ningun valor. 
	 * La funcion para generar valores aleatorios en el resto del programa es rand() 
	 **/
    srand(time(NULL));	

    /* 
     * Mostrar fondos en pantalla.
     **/
    //display_back01();

    /* 
     * Incluimos la siguiente cabecera para que cada grupo la modifique con
     * su numero de grupo "xxx" en "ECxxx". 
     **/
//  iprintf("\x1b[00;00H.123456789.123456789.123456789.1");
    iprintf("\x1b[01;00H  +--------------------------+  ");
    iprintf("\x1b[02;00H  : KE-EC 20/21      EC304   :  ");
    iprintf("\x1b[03;00H  +--------------------------+  ");

    iprintf("\x1b[04;00H  +--------------------------+  ");
    iprintf("\x1b[05;00H  :Irastorza, Carrasco, Oihan:  ");
    iprintf("\x1b[06;00H  :  Pizarro, Liberal Eneko  :  ");
    iprintf("\x1b[07;00H  :  Valdiviezo, Rios Fran   :  ");
    iprintf("\x1b[08;00H  +--------------------------+  ");
    iprintf("\x1b[10;00H       < Press any key >        ");

    while(1) {
		//iprintf("\x1b[14;00H    Current last line: %d        ", lastRow*20);
		//iprintf("\x1b[14;00H    Touched![%d, %d]        ", getX(), getY());
		x = getX();
		y = getY();
		if (ticks % 2 == 0) pressedKeyPolling();
		switch (state) {
			case BEGIN:
				if (pressed_key_value() == SELECT || is_the_screen_touched()) {			
					state = MENU;
					display_play1();
				} else {
					backstars(anim12s);
					if(anim12s == 21) anim12s = 0;
				}
				break;
			case MENU:
				// Play button
				if ((x > 11 && x < 110) && (y > 60 && y < 87)) {
					display_play1();
					menuState = 0;
					setUpGame();
					state = GAME;
				}

				// Options button
				if ((x > 11 && x < 141) && (y > 93 && y < 117)) {
					display_options1();
					menuState = 1;
				}

				// Quit Game button
				if ((x > 11 && x < 169) && (y > 123 && y < 147)) {
					display_exit1();
					menuState = 2;
				}

				break;
			case GAME:
				// Pause by clicking pause button
				if (is_the_screen_touched()) if (x >= 240 && y <= 16) pausa();

				// Move laser cannon
				if (ticks % 8 == 0) {
					if (pressed_key_value() == LEFT || pressed_key_value() == LEFTB) moveLaserCannon(LEFT);
					if (pressed_key_value() == RIGHT || pressed_key_value() == RIGHTB) moveLaserCannon(RIGHT);
				}

				// Finish game
				if (deadCount == ALIENS_SIZE || countdown == 0 ||
					laserCannon.hp == 0 || pressed_key_value() == A || alienReachEarth()) {
					printScore();
					removeAllAliens();
					remove_pausa_sprite(240, 0);
					removeHearts();

					// Save the end reason for the termination					
					if (countdown == 0) endReason = 1;
					else if (pressed_key_value() == A) endReason = 2;
					else if (laserCannon.hp == 1) endReason = 3;
					else endReason = 4;

					state = GAMEOVER;
				}	
				break;
			case PAUSE:
				// Resume button
				if ((x >= 101 && x <= 141) && (y >= 105 && y <= 116)) {
					display_pause1();
					pauseState = 0;
					resume();
				}
				// Quit button
				if ((x >= 101 && x <= 141) && (y >= 119 && y <= 130)) {
					display_pause2(2);
					pauseState = 1;
					state = MENU;
				}
				break;
			case GAMEOVER:
				if (deadCount == ALIENS_SIZE) { // Win
					if (ticks < FREC0/2) iprintf("\x1b[14;00H          < VICTORY! >          ");
					else iprintf("\x1b[14;00H                                ");				
				} else { // Lose
					if (ticks < FREC0/2) {
						iprintf("\x1b[14;00H         < GAME OVER >          ");
						if (ticks == 0) printEndReason(endReason);
					}
					else iprintf("\x1b[14;00H                                ");						
				}

				// Print statistics after 5 secs
				if (gameOverSegs == 5) {
					printStatistics();
					state = SCORE;
				}
				break;
			case SCORE:
				// Afte 5 secs, blink a message to notify to the user
				if (scoreSegs > 5) {
					if (ticks < FREC0/2) iprintf("\x1b[23;00H <START>:Restart | <SELECT>:Menu");
					else iprintf("\x1b[23;00H                                ");
				}	

				// Back to menu if any key is pressed
				if (pressed_key_value() == SELECT || pressed_key_value() == START) {
					clearStatistics();
					remove_laser_cannon(laserCannon.x, laserCannon.y);
					if (pressed_key_value() == START) {
						setUpGame();
						state = GAME;
					}
					if (pressed_key_value() == SELECT) {
							display_play1();
							state = MENU;
					}
				}
				break;
		}
    } // while

} // main()
