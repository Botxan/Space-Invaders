/**********************************************************
 * timers.c
 **********************************************************/

/* 
 * Añadir los includes que sean necesarios
 **/
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "functions.h"

// Variables for moveAliens()
int firstRow; // the first line where the aliens spawn
int lastRow; // the last line where the aliens spawn
int curRow; // the row that will be moved
int dx; // -1: left, 1: right
int descend; // flag that informs when the aliens have to descend
int speed;
int deadCount;

// Timers for background and "SPACE INVADER" title animations
int anim12s;
int animb;
int ticks_animation;
int ticks_collision_anim;

int eShootDelay = 0;

void increaseSpeed() {
	if (deadCount == ALIENS_SIZE/8 ||
		deadCount == ALIENS_SIZE/4 ||
		deadCount == ALIENS_SIZE/2 ||
		deadCount == ALIENS_SIZE-2 ||
		deadCount == ALIENS_SIZE-1 ){
		speed = speed << 1;
	}
}

/**
 * Rutina de atención para mover los alienígenas
 */
void moveAliens() {
	int i;
	
	if (descend && curRow == lastRow) { // Move Y
		for (i = 0; i < ALIENS_SIZE; i++) {
			if (aliens[i].hp > 0) {
				remove_crab_alien(i, aliens[i].x, aliens[i].y);
				aliens[i].y += 20;
				alien_animation(i, aliens[i].x, aliens[i].y, aliens[i].characterN, aliens[i].spriteN);
			}
		}

		firstRow++;
		lastRow++;
		curRow = lastRow;
		dx *= -1;
		descend = 0;

	} else { // Move X
		for (i = 0; i < ALIENS_SIZE; i++) {
			// Move alien if it is on the current row
			if (aliens[i].y == curRow*20 && aliens[i].hp > 0) {	
				remove_crab_alien(i, aliens[i].x, aliens[i].y);
				aliens[i].x += 5*dx;	
				alien_animation(i, aliens[i].x, aliens[i].y, aliens[i].characterN, aliens[i].spriteN);

				// activate descend flag when an alien hits the border
				if (aliens[i].x == 240 || aliens[i].x == 0) descend = 1;
			}
		}
		if (curRow == firstRow)curRow = lastRow;
		else curRow--; 
	}
}

/**
 * Rutina de atención para mover los proyectiles
 */
void moveProjectiles() {
	int i;
		
	for (i = 0; i < PROJECTILES_SIZE; i++) {
		// Move only active projectiles
		if (projectiles[i].active) {
			remove_projectile(i, projectiles[i].x, projectiles[i].y);
			projectiles[i].y--;
			projectile_animation(i, projectiles[i].x, projectiles[i].y, projectiles[i].sprite);
			int collider = collision(i);
			if (collider != -1) {
				removeProjectile(i);
				aliens[collider].hp--;
				if (aliens[collider].hp == 0) {
					deadCount++;
					aliens[collider].cont = 0; // initialize alien death animation
					addPoints(0);
					increaseSpeed();
				}
			}
		}
		
		if (projectiles[i].y == -16) projectiles[i].active = 0;
	}
}

void moveEnemyProjectiles() {
	int i;
	for (i = 0; i < EPROJECTILES_SIZE; i++) {
		// Move only active projectiles
		if (eprojectiles[i].active) {
			remove_enemy_projectile(i, eprojectiles[i].x, eprojectiles[i].y);
			eprojectiles[i].y++;
			display_enemy_projectile_1(i, eprojectiles[i].x, eprojectiles[i].y);
			int collider = enemyCollision(i);
			if (collider == 1) {
				removeEnemyProjectile(i);
				loseHeart();
			}
		}
		
		if (eprojectiles[i].y == 207) eprojectiles[i].active = 0;
	}
}

void animate_collisions() {
	int i;
	for (i = 0; i < ALIENS_SIZE; i++) {
		
		if (aliens[i].hp == 0 && aliens[i].cont >= 0) {
			if(aliens[i].cont == 0) {	
				remove_crab_alien(i, aliens[i].x, aliens[i].y);
				display_alien_collision(i, aliens[i].x, aliens[i].y);
			}
			
			aliens[i].cont++;
			if (aliens[i].cont == FREC0/3) {
				removeAlien(i);
			}
		}
	}
}

/* 
 * Rutina de atención a la interrupción del temporizador
 **/
void timer_handler() {
	ticks++;
	if (ticks == FREC0) {
		segs++;
		ticks = 0;
	}

	// animation counter for background and "SPACE INVADER" title animation
	ticks_animation++;
	if ((FREC0/12) == ticks_animation) {
		anim12s++;
		animb++;
		if (animb == 11) animb = 0;
		ticks_animation = 0;
	}

	switch (state) {
		case BEGIN:
			break;
		case MENU:
			if (ticks % (FREC0/2) == 0) menu_animation();
			break;
		case GAME:
			if (ticks == 0) {	
				if (countdown > 0) countdown--;
				printCountdown();
			}
			if (ticks % 2 == 0) {
				printScore();
				moveProjectiles();
			}
			if (ticks % 4 == 0) moveEnemyProjectiles();
			if (ticks % (FREC0/10) == 0) background(animb);
			if (ticks % (FREC0/2) == 0) enemyShootDelay();
			if (ticks % (FREC0/speed) == 0) moveAliens();
			animate_collisions();
			break;
		case PAUSE:
			break;
		case GAMEOVER:
			animate_collisions();
			if (ticks == 0) gameOverSegs++;
			if (ticks % 2 == 0) moveProjectiles();
			if (ticks % 3 == 0) moveEnemyProjectiles();
			if (deadCount != ALIENS_SIZE) 
				if (ticks % (FREC0/2) == 0) {	
					laser_cannon_break_animation();
				}
			break;
		case SCORE:
			if (ticks == 0) scoreSegs++;
			break;
	}
}// timer_handler()
