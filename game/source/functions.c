/**********************************************************
 * Auxiliary functions for the game
 **********************************************************/

#include <nds.h>
#include <stdio.h>

#include "defines.h"
#include "backgrounds.h"
#include "keypad_screen.h"
#include "sprites.h"

int pIndex = 0; // used to get the next projectile index
int epIndex = 0; // used to get the next enemy projectile index

/*
 * Prints the pressed key on the top screen (polling).
*/
void pressedKeyPolling() {

	// polling and interruption iprints may collaps and fill 2 lines.For that cases
	// clear the 2nd line(12):
	iprintf("\x1b[11;00H                                ");

	switch (pressed_key_value()) {
		case A: 
			iprintf("\x1b[10;00H  Encuesta: <A>          [%x]  ", KEYS_DAT);
			break;
	        case SELECT: 
			iprintf("\x1b[10;00H  Encuesta: <SELECT>     [%x]  ", KEYS_DAT);
			break;
		case RIGHT:
			iprintf("\x1b[10;00H  Encuesta: <RIGHT>      [%x]  ", KEYS_DAT);
			break;
		case LEFT:
			iprintf("\x1b[10;00H  Encuesta: <LEFT>       [%x]  ", KEYS_DAT);
			break;
		case R: 
			iprintf("\x1b[10;00H  Encuesta: <R>          [%x]  ", KEYS_DAT);
			break;
		case L: 
			iprintf("\x1b[10;00H  Encuesta: <L>          [%x]  ", KEYS_DAT);
			break;
	}
}

/*
 * Prints the pressed key on the top screen (interruption).
*/
void pressedKeyInterrupting() {
	switch (pressed_key_value()) {
		case B:
			iprintf("\x1b[10;00H  Interrupcion: <B>      [%x]  ", KEYS_DAT);
			break;
		case START:
			iprintf("\x1b[10;00H  Interrupcion: <START>  [%x]  ", KEYS_DAT);
			break;
		case RIGHTB:
			iprintf("\x1b[10;00H  Interrupcion: <RIGHT+B>[%x]  ", KEYS_DAT);
			break;
		case LEFTB:
			iprintf("\x1b[10;00H  Interrupcion: <LEFT+B> [%x]  ", KEYS_DAT);
			break;
		case UP:
			iprintf("\x1b[10;00H  Interrupcion: <UP>     [%x]  ", KEYS_DAT);
			break;
		case DOWN:
			iprintf("\x1b[10;00H  Interrupcion: <DOWN>   [%x]  ", KEYS_DAT);
			break;
	}
}

/*
 * Generates randomNum between the values passed by parameter.
*/
int randomNum(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

/*
 * Menu animation
*/
void menu_animation() {
	switch(menuState) {
		case 0:
			menuN ? display_play2() : display_play1();
			break;
		case 1:
			menuN ? display_options2() : display_options1();
			break;
		case 2:
			menuN ? display_exit1() : display_exit2();
			break;
	}
	menuN = menuN ? 0 : 1;
}

/*
 * Logo animation.
*/
void backstars(int i){
	switch (i) {
		case 0: display_backstars00(); break;
		case 1: display_backstars01(); break;
		case 2: display_backstars02(); break;
		case 3: display_backstars03(); break;
		case 4: display_backstars04(); break;
		case 5: display_backstars05(); break;
		case 6: display_backstars06(); break;
		case 7: display_backstars07(); break;
		case 8: display_backstars08(); break;
		case 9: display_backstars09(); break;
		case 10: display_backstars10(); break;
		case 11: display_backstars11(); break;
		case 12: display_backstars12(); break;
		case 13: display_backstars13(); break;
		case 14: display_backstars14(); break;
		case 15: display_backstars15(); break;
		case 16: display_backstars16(); break;
		case 17: display_backstars17(); break;
		case 18: display_backstars18(); break;
		case 19: display_backstars19(); break;
		case 20: display_backstars20(); break;
		case 21: display_backstars21(); break;
	}
}

/*
 * Animation for game background.
*/
void background(int i) {
	switch(i) {
		case 0:
			display_b00();
			break;
		case 1:
			display_b01();
			break;
		case 2:
			display_b02();
			break;
		case 3:
			display_b03();
			break;
		case 4:
			display_b04();
			break;
		case 5:
			display_b05();
			break;
		case 6:
			display_b06();
			break;
		case 7:
			display_b07();
			break;
		case 8:
			display_b08();
			break;
		case 9:
			display_b09();
			break;
		case 10:
			display_b10();
			break;
		case 11:
			display_b10();
			//display_b11();
			break;
	}
}

/*
 * Alien moving animation.
*/
void alien_animation(int layer, int x, int y, int characterN, int spriteN){
	switch (characterN){
		case 0:
			if (spriteN == 0) {
				display_glu_glu_1(layer, x, y);
				aliens[layer].spriteN = 1;
			} else {
				display_glu_glu_2(layer, x, y);
				aliens[layer].spriteN = 0;
			}
			break;
		case 1:
			if (spriteN == 0) {
				display_bi_bi_1(layer, x, y);
				aliens[layer].spriteN = 1;
			} else {
				display_bi_bi_2(layer, x, y);
				aliens[layer].spriteN = 0;
			}
			break;
		case 2:
			if (spriteN == 0) {
				display_blu_blu_1(layer, x, y);
				aliens[layer].spriteN = 1;
			} else {
				display_blu_blu_2(layer, x, y);
				aliens[layer].spriteN = 0;
			}
			break;
		case 3:
			if (spriteN == 0) {
				display_reddy_1(layer, x, y);
				aliens[layer].spriteN = 1;
			} else {
				display_reddy_2(layer, x, y);
				aliens[layer].spriteN = 0;
			}
			break;
		case 4:
			if (spriteN == 0) {
				display_bli_bli_1(layer, x, y);
				aliens[layer].spriteN = 1;
			} else {
				display_bli_bli_2(layer, x, y);
				aliens[layer].spriteN = 0;
			}
			break;
		case 5:
			if (spriteN == 0) {
				display_crabby_1(layer, x, y);
				aliens[layer].spriteN = 1;
			} else {
				display_crabby_2(layer, x, y);
				aliens[layer].spriteN = 0;
			}
			break;
	}
}

/* 
 * Projectile moving animation.
*/
void projectile_animation(int layer, int x, int y, int sprite) {
	switch (sprite) {
		case 0:
			display_projectile_reverse(layer, x, y);
			projectiles[layer].sprite = 1;	
			break;
		case 1:
			display_projectile(layer, x, y);
			projectiles[layer].sprite = 0;	
			break;
	}
}

/*
 * Laser cannon break animation.
*/
void laser_cannon_break_animation() {
	remove_laser_cannon(laserCannon.x, laserCannon.y);
	switch(laserCannon.spriteN) {
		case 0: // normal
			display_broken_laser_cannon_1(laserCannon.x, laserCannon.y);
			laserCannon.spriteN = 1;
			break;
		case 1: // broken 1
			display_broken_laser_cannon_2(laserCannon.x, laserCannon.y);
			laserCannon.spriteN = 2;
			break;
		case 2: // broken 2
			display_broken_laser_cannon_1(laserCannon.x, laserCannon.y);
			laserCannon.spriteN = 1;
			break;
	}
}

/*
 * Spawns the laser cannon.
*/
void spawnLaserCannon() {
	laserCannon.x = 120;
	laserCannon.y = 160;
	laserCannon.hp = 3;
	laserCannon.characterN = 0;
	laserCannon.spriteN = 0;
	laserCannon.cont = -1;
	display_laser_cannon(laserCannon.x, laserCannon.y);
}

/*
 * Prints the remaning time.
*/
void printCountdown() {
	iprintf("\x1b[22;00H   TIME: %02d                     ", countdown);
	iprintf("\x1b[23;00H                                ");
}

/*
 * Prints the current score.
*/
void printScore() {
	iprintf("\x1b[20;00H  SCORE: %03d                    ", score);
	iprintf("\x1b[21;00H                                ");
}

/*
 * Returns an alien sprite based on spawn line.
 */ 
int chooseAlien(i) {
	int sprite = 0;

	switch (aliens[i].y) {
		case UPPERBOUND*20: sprite = 1; // line 1
			break;
		case (UPPERBOUND+1)*20: sprite = 5; // line 2
			break;
		case (UPPERBOUND+2)*20: sprite = 3;; // line 3
			break;
		case (UPPERBOUND+3)*20: sprite = 4; // line 4
			break;
	}

	return sprite;
}

/*
 * Spawns the aliens and initializes projectile arrays.
*/
void generateNPC(int n) {
    int xy[n][2];
    int i, j;
    
    // Generate random coords
    i = 0;
    while (i < n) {
        xy[i][0] = (randomNum(2, 10) * 20); // x[0, 16, 32..256]
        xy[i][1] = (randomNum(1, 4) * 20); // y[0, 16, 32..112]
		j = 0;
        while (i > 0 && j < i) { 
        	// rand coords if repeated
			if (xy[i][0] == xy[j][0] && xy[i][1] == xy[j][1]) {
				xy[i][0] = (randomNum(3, 9) * 20); // x
	            xy[i][1] = (randomNum(1, 4) * 20); // y
				j = 0;
			} else j++;
        }   
        i++;   
    }

    // Initialize aliens list
    for (i = 0; i < n; i++) {
        aliens[i].x = xy[i][0];
		aliens[i].y = xy[i][1];
		aliens[i].hp = 1;
		aliens[i].characterN = chooseAlien(i);
		aliens[i].spriteN = 0;
		aliens[i].cont = -1;
		alien_animation(i, aliens[i].x, aliens[i].y, aliens[i].characterN, aliens[i].spriteN);
    }
}

void displayHearts() {
	display_heart(0, 0, 0);
	display_heart(1, 16, 0);
	display_heart(2, 32, 0);
}


/*
 * Setups the game.
*/
void setUpGame() {
	spawnLaserCannon();

	generateNPC(ALIENS_SIZE);
	deadCount = 0;

	countdown = MAXTIME;
	printCountdown();

	score = 0;
	printScore();

	speed = 5;
	gameOverSegs = 0;
	scoreSegs = 0;

	firstRow = UPPERBOUND;
	curRow = 4;
	lastRow = LOWERBOUND;

	dx = 1;
	descend = 0;

	displayHearts();
	
	// pause button
	display_pausa_sprite(240, 0);

	int i;
	// Initialize projectiles list
    for (i = 0; i < PROJECTILES_SIZE; i++) {
        projectiles[i].x = 0;
		projectiles[i].y = 0;
		projectiles[i].active = 0;
		projectiles[i].sprite = 0;
    }

	// Initialize enemy projectiles list
    for (i = 0; i < EPROJECTILES_SIZE; i++) {
        eprojectiles[i].x = 0;
		eprojectiles[i].y = 0;
		eprojectiles[i].active = 0;
		eprojectiles[i].sprite = 0;
    }
}

/*
 * Moves the laser cannon.
*/
void moveLaserCannon(int dir) {	
	remove_laser_cannon(laserCannon.x, laserCannon.y);
	if (laserCannon.x == 0 && dir == LEFT) laserCannon.x = 0;
	else if (laserCannon.x == 241 && dir == RIGHT) laserCannon.x = 241;
	else dir == RIGHT ? laserCannon.x++ : laserCannon.x--;
	display_laser_cannon(laserCannon.x, laserCannon.y);
}

/*
 * Activates a laser cannon projectile.
*/
void shoot() {
	projectiles[pIndex].active = 1;
	projectiles[pIndex].x = laserCannon.x;
	projectiles[pIndex].y = laserCannon.y;
	pIndex++;
	if (pIndex == PROJECTILES_SIZE-1) pIndex = 0;
}

/*
 * Shows every active projectile.
*/
void showProjectiles() {
	int i;
	for (i = 0; i < PROJECTILES_SIZE; i++)
		if (projectiles[i].active)
			display_projectile(i, projectiles[i].x, projectiles[i].y);	
}

/*
 * Hides every projectile.
*/
void hideProjectiles() {
	int i;
	for (i = 0; i < PROJECTILES_SIZE; i++)
		remove_projectile(i, projectiles[i].x, projectiles[i].y);	
}

/*
 * Activates an enemy projectile.
*/
void enemyShoot(i) {
	eprojectiles[epIndex].active = 1;
	eprojectiles[epIndex].x = aliens[i].x;
	eprojectiles[epIndex].y = aliens[i].y;
	epIndex++;
	if (epIndex == EPROJECTILES_SIZE-1) epIndex = 0;
}

/*
 * * Shows every enemy active projectile.
*/
void showEnemyProjectiles() {
	int i;
	for (i = 0; i < EPROJECTILES_SIZE; i++)
		if (eprojectiles[i].active)
			display_enemy_projectile_1(i, eprojectiles[i].x, eprojectiles[i].y);
}

/*
 * Hides every enemy projectile.
*/
void hideEnemyProjectiles() {
	int i;
	for (i = 0; i < EPROJECTILES_SIZE; i++)
		remove_enemy_projectile(i, eprojectiles[i].x, eprojectiles[i].y);	
}

/*
 * Handles the delay between enemy shots.
*/
void enemyShootDelay() {
	if (eShootDelay == 2) {
		int i = getRandomAlien();
		enemyShoot(i);
		eShootDelay = 0;
	} else eShootDelay++;
}

/*
 * Returns the index of the layer of a random alive alien.
*/ 
int getRandomAlien() {
	int alive = 0;
	int rand;
	while (!alive) {
		rand = randomNum(0, ALIENS_SIZE-1);
		if (aliens[rand].hp > 0) alive = 1;
	}
	return rand;
}

/*
 * Returns 1 if the projectile passed by parameter has collided with any alien.
 * Otherwise returns 0.
*/
int collision(int i) {
	int j;
	for (j = 0; j < ALIENS_SIZE; j++) {
		if (aliens[j].hp > 0) {
			if (aliens[j].x    < projectiles[i].x+10 &&
				aliens[j].x+10 > projectiles[i].x    &&
				aliens[j].y    < projectiles[i].y+10 &&
				aliens[j].y+10 > projectiles[i].y)
				return j;
		}
	}
	return -1;
}

/**
  * Returns 1 if an enemy shoot has collided with the laser cannon.
  * Otherwise returns 0.
*/
int enemyCollision(int i) {
	if (laserCannon.hp > 0) {
		if (laserCannon.x    < eprojectiles[i].x+10 &&
			laserCannon.x+10 > eprojectiles[i].x    &&
			laserCannon.y    < eprojectiles[i].y+10 &&
			laserCannon.y+10 > eprojectiles[i].y)
			return 1;
	}
	return -1;
}

/*
 * Displays every alien alive.
*/
void showAliens() {
	int i;
	for (i = 0; i < ALIENS_SIZE; i++) 
		if (aliens[i].hp > 0) 
			alien_animation(i, aliens[i].x, aliens[i].y, aliens[i].characterN, aliens[i].spriteN);
}

/*
 * Pauses the game.
*/
void pausa() {	
	hideAliens();
	hideProjectiles();
	hideEnemyProjectiles();
	remove_laser_cannon(laserCannon.x, laserCannon.y);
	pauseState = 0;
	display_pause1();
	remove_pausa_sprite(240, 0);
	removeHearts();
	state = PAUSE;
}

/*
 * Hides every alien.
*/
void hideAliens() {
	int i;
	for (i = 0; i < ALIENS_SIZE; i++) 
		remove_crab_alien(i, aliens[i].x, aliens[i].y);
	
}

/*
 * Resumes the paused game.
*/
void resume() {
	showAliens();
	showProjectiles();
	showEnemyProjectiles();
	display_laser_cannon(laserCannon.x, laserCannon.y);
	display_pausa_sprite(240, 0);
	displayHearts();
	state = GAME;
}

/**
 * Checks if any alien has reached Earth.
*/
int alienReachEarth() {
	int i;
	for (i = 0; i < ALIENS_SIZE; i++) {
		if (aliens[i].y > 140) {
			return 1;
		}
	}
	return 0;
}

/**
 * Add points to the score depending on monster type.
 */
void addPoints(int monsterType) {
	switch (monsterType) {
		case 0: // normal alien
			score+=10;
			break;
		case 1: // ovni
			score+=100;
			break;
		case 2: // final boss
			score+=500;
			break;
	}
}

/*
 * Prints the reason why the game is over.
*/
void printEndReason(reason) {
	switch (reason) {
		case 1: // Time's up
			iprintf("\x1b[16;00H           Time's up          ");
			break;
		case 2: // Key A was pressed
			iprintf("\x1b[16;00H        <A> was pressed        ");
			break;
		case 3: // Laser cannon has been destroyed
			iprintf("\x1b[16;00H     The laser cannon has      ");
			iprintf("\x1b[17;00H        been destroyed         ");
			break;
		case 4: // Aliens reach Earth
			iprintf("\x1b[16;00H        The aliens have        ");
			iprintf("\x1b[17;00H        conquered Earth        ");
			break;
	}
}

/**
 * Prints end game statistics.
*/
void printStatistics() {
	iprintf("\x1b[12;00H +----------------------------+");
	iprintf("\x1b[13;00H :          Statistics        :");
	iprintf("\x1b[14;00H +----------------------------+ ");	
	iprintf("\x1b[15;00H :                 |          :");	
	iprintf("\x1b[16;00H : Defeated aliens | %02d       :", deadCount);
	iprintf("\x1b[17;00H :                 |          :");
	iprintf("\x1b[18;00H : Survived time   | %02d       :", MAXTIME-countdown);
	iprintf("\x1b[19;00H :                 |          :");
	iprintf("\x1b[20;00H : Total score     | %03d      :", score);
	iprintf("\x1b[21;00H :                 |          :");
	iprintf("\x1b[22;00H +----------------------------+");		
}

/**
 * Clears end statistics.
*/
void clearStatistics() {
	iprintf("\x1b[12;00H                               ");
	iprintf("\x1b[13;00H                               ");
	iprintf("\x1b[14;00H                               ");
	iprintf("\x1b[15;00H                               ");
	iprintf("\x1b[16;00H                               ");
	iprintf("\x1b[17;00H                               ");
	iprintf("\x1b[18;00H                               ");
	iprintf("\x1b[19;00H                               ");
	iprintf("\x1b[20;00H                               ");
	iprintf("\x1b[21;00H                               ");
	iprintf("\x1b[22;00H                               ");
	iprintf("\x1b[23;00H                               ");
}

/*
 * Removes the alien on the laser passed by parameter.
*/
void removeAlien(int i) {
	remove_crab_alien(i, aliens[i].x, aliens[i].y);
	aliens[i].x = 0;
	aliens[i].y = 0;
	aliens[i].hp = 0;
	aliens[i].characterN = 0;
	aliens[i].cont = -1;
}

/*
 * Removes every alien.
*/
void removeAllAliens() {
	int i = 0;
	for (i = 0; i < ALIENS_SIZE; i++) removeAlien(i);
}

/*
 * Remove the projectile on the layer passed by parameter.
*/
void removeProjectile(int i) {
	remove_projectile(i, projectiles[i].x, projectiles[i].y);
	projectiles[i].x = 0;
	projectiles[i].y = 0;
	projectiles[i].active = 0;
	projectiles[i].sprite = 0;
}

void removeEnemyProjectile(int i) {
	remove_enemy_projectile(i, eprojectiles[i].x, eprojectiles[i].y);
	eprojectiles[i].x = 0;
	eprojectiles[i].y = 0;
	eprojectiles[i].active = 0;
	eprojectiles[i].sprite = 0;
}

/*
 * One life is subtracted from the laser cannon.
*/
void loseHeart() {
	remove_heart(laserCannon.hp-1, (laserCannon.hp-1)*16, 0);
	laserCannon.hp--;
}

/*
 * Hides the heart sprites 
*/
void removeHearts() {
	remove_heart(0, 0, 0);
	remove_heart(1, 16, 0);
	remove_heart(2, 32, 0);
}
