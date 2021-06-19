#ifndef _defines
#define _defines
/**********************************************************
 * defines.h
 **********************************************************/

#include <nds.h>
#include <stdio.h>

/* 
 * Aquí se definen los registros del gestor de interrupciones
 **/
#define IME		(*(vuint16*)0x04000208) //Interrupt Master Enable - Habilita o deshabilita todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable - Activa o desactiva las interrupciones una a una
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag - Guarda las peticiones de interrupcion

/* 
 * Aquí se definen algunas funciones para el tratamiento de las interrupciones
 **/
#define enable_ints() 	IME=1 //Habilita todas las interrupciones
#define disable_ints() 	IME=0 //Inhibe todas las interrupciones

/* 
 * Aquí se definen los registros del teclado
 **/
#define KEYS_DAT	(*(vuint16*)0x4000130) //Registro de datos del teclado
#define KEYS_CNT	(*(vuint16*)0x4000132) //Registro de control del teclado

/* 
 * Aquí se definen los registros del temporizador
 **/
#define TIMER0_CNT  (*(vuint16*)0x04000102) //Registro de control del temporizador
    /* 
     * El temporizador se activa poniendo un 1 en el bit 7.
     * El temporizador interrumpirá al desbordarse el contador, si hay un 1 en el bit 6.
     * Los dos bits de menos peso indican lo siguiente:
     *		00 frecuencia 33554432 hz 
     *		01 frecuencia 33554432/64 hz
     *		10 frecuencia 33554432/256 hz
     *		11 frecuencia 33554432/1024 hz
     **/
#define TIMER0_DAT  (*(vuint16*)0x04000100) //Registro de datos del temporizador
    /* 
     * Se utiliza para indicar a partir de qué valor tiene que empezar a contar
     **/
#define FREC0 512 // Frecuencia del temporizador 0
extern int ticks; // ticks for segundo
extern int segs; // segundero
extern int anim12s; // animacion 12 fps

/* 
 * Asignar un identificador a cada tecla
 **/
#define A		0
#define B		1
#define SELECT	2
#define START	3
#define RIGHT	4
#define RIGHTB	41 // Combinacion RIGHT+B
#define LEFT	5
#define LEFTB	51 // Combinacion LEFT+B
#define UP		6
#define DOWN	7
#define R		8
#define L		9


/* 
 * Asignar un identificador a cada estado
 **/
#define BEGIN	 0
#define MENU	 1
#define GAME	 2
#define PAUSE	 3
#define GAMEOVER 4
#define SCORE	 5


/* 
 * Variables globales
 **/

extern int state;

/*
 * Estructura de datos para los sprites
 **/
typedef struct t_sprite {
	int x;
	int y;
	int hp; // health points
	int characterN; // number of the character type
	int spriteN; // number of sprite animation
	int cont;	// collision animation counter
} t_sprite;

typedef struct t_projectile {
	int x;
	int y;
	int active; // wheter the projectile is spawn or not
	int sprite; // projectile or collision sprite
} t_projectile;

t_sprite laserCannon;

int ALIENS_SIZE;
t_sprite aliens[30];
extern int speed;
extern int deadCount;

int PROJECTILES_SIZE;
t_projectile projectiles[10];

int EPROJECTILES_SIZE; // Enemy projectiles
t_projectile eprojectiles[10];
extern int eShootDelay;

int menuState;
int menuN;

int pauseState;

#define MAXTIME 20
extern int countdown;
extern int score;

extern int gameOverSegs;
extern int scoreSegs;

extern int firstRow;
extern int curRow;
extern int lastRow;

extern int dx;
extern int descend;

extern int endReason;

extern int x, y;

// The area where the aliens 
#define UPPERBOUND 1
#define LOWERBOUND 4

#endif
