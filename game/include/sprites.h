#ifndef _sprites
#define _sprites
/********************************************************** 
 * sprites.h 
 **********************************************************/

extern u16* gfx_laser_cannon;
extern u16* gfx_crab_alien;

extern void init_sprite_memory();

extern void set_main_palette();
extern void set_secondary_palette();

extern void alloc_sprites_in_memory();

// Laser Cannon
extern void display_laser_cannon(int x, int y);
extern void remove_laser_cannon(int x, int y);
extern void display_broken_laser_cannon_1(int x, int y);
extern void display_broken_laser_cannon_2(int x, int y);

// Alien
extern void display_crab_alien(int index, int x, int y);
extern void display_glu_glu_1(int index, int x, int y);
extern void display_glu_glu_2(int index, int x, int y);
extern void display_bi_bi_1(int index, int x, int y);
extern void display_bi_bi_2(int index, int x, int y);
extern void display_blu_blu_1(int index, int x, int y);
extern void display_blu_blu_2(int index, int x, int y);
extern void display_reddy_1(int index, int x, int y);
extern void display_reddy_2(int index, int x, int y);
extern void display_bli_bli_1(int index, int x, int y);
extern void display_bli_bli_2(int index, int x, int y);
extern void display_crabby_1(int index, int x, int y);
extern void display_crabby_2(int index, int x, int y);
extern void display_projectile(int index, int x, int y);
extern void display_alien_collision(int index, int x, int y);
extern void remove_crab_alien(int index, int x, int y);

// Projectile
extern void display_projectile(int index, int x, int y);
extern void display_projectile_reverse(int index, int x, int y);
extern void remove_projectile(int index, int x, int y);

// Enemy Projectile
extern void display_enemy_projectile_1(int index, int x, int y);
extern void remove_enemy_projectile(int index, int x, int y);

// Heart
extern void display_heart(int index, int x, int y);
extern void remove_heart(int index, int x, int y);

// Pause
extern void display_pausa_sprite(int x, int y);
extern void remove_pausa_sprite(int x, int t);

#endif
