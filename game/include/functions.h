#ifndef _functions
#define _functions
/********************************************************** 
 * functions.h
 **********************************************************/

extern void pressedKeyPolling();
extern void pressedKeyInterrupting();

extern int  randomNum(int min, int max);

// Animations
extern void menu_animation();
extern void backstars(int i);
extern void background(int i);
extern void alien_animation(int layer, int x, int y, int characterN, int spriteN);
extern void projectile_animation(int layer, int x, int y, int sprite);
extern void laser_cannon_break_animation();

// Game setup
extern void spawnLaserCannon();
extern void printCountdown();
extern void printScore();
extern void setUpGame();

// Laser cannon move
extern void moveLaserCannon(int n);

// Projectile shooting
extern void shoot();
extern void enemyShoot(int i);
extern void enemyShootDelay();
extern int  collision(int i);
extern int  enemyCollision(int i);

// Pause
extern void pausa();
extern void resume();

// Game over
extern int alienReachEarth();

// Top screen prints
extern void addPoints();
extern void printEndReason(int reason);
extern void printStatistics();
extern void clearStatistics();

// Remove sprites
extern void removeAlien(int i);
extern void removeAllAliens();
extern void removeProjectile(int i);
extern void removeEnemyProjectile(int i);
extern void loseHeart();
extern void removeHearts();

#endif
