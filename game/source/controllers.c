/**********************************************************
 * controllers.c
 **********************************************************/

/* 
 * Añadir los includes que sean necesarios
 **/
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "keypad_screen.h"
#include "timers.h"


/* 
 * Habilitar las interrupciones. En el Controlador de Interrupciones
 **/
void enable_interrupts() { 
  /* 
   * Primero se inhiben todas las interrupciones
   **/
  IME = 0;


  /* 
   * Escribir un 1 en el bit correspondiente
   **/
  // Activador: IRQ_KEYS & IRQ_TIMER0
  // Activar timer1: bit 4
  // Activar timer2: bit 5
  // Activar timer3: bit 6

  IE = IE | 0x1008;

  /* 
   * Se vuelven a habilitar todas las interrupciones
   **/
  IME = 1;


} // enable_interrupts()


/* 
 * Programar los registros de control. Aquí es donde se configuran los 
 * registros de control de los periféricos.
 **/
void configure_control_registers() {

  /*
   * Registro de Control del Teclado
   **/
    KEYS_CNT = 0x40CA;

  /* 
   * Registro de Control de los Temporizadores
   *   TIMER0_CNT 
   *     El temporizador se activa poniendo un 1 en el bit 7.
   *     El temporizador interrumpirá al desbordarse el contador, 
   *        si hay un 1 en el bit 6.
   *     Los dos bits de menos peso indican lo siguiente:
   *        00 frecuencia 33554432 hz 
   *        01 frecuencia 33554432/64 hz
   *        10 frecuencia 33554432/256 hz
   *        11 frecuencia 33554432/1024 hz
   */

    TIMER0_CNT = TIMER0_CNT | 0x00C0;
  /*
   *   TIMER0_DAT 
   *     Se utiliza para indicar a partir de que valor tiene que empezar 
   *        a contar (latch)
   **/
    TIMER0_DAT = 0;
} // configure_control_registers()



/* 
 * Este procedimiento inicializa el vector de interrupciones para que 
 * el gestor de interrupciones sepa que rutina de atencion tiene que 
 * ejecutar cuando le llega una peticion de interrupcion.
 **/
void define_interrupt_vector_table() { 

  /* 
   * Rutina de Atencion al Teclado
   **/
   irqSet(IRQ_KEYS, keypad_handler);

  /* 
   * Rutinas de Atencion a los Temporizadores
   **/
   irqSet(IRQ_TIMER0, timer_handler);

} // DefinirVectorInterrupciones()


/* 
 * Inhibe las interrupciones. En el Controlador de Interrupciones
 **/
void disable_interrupts() {

  /* 
   * Primero se inhiben todas las interrupciones
   **/


  /* 
   * Escribir un 0 en el bit correspondiente
   **/



  /* 
   * Se vuelven a habilitar todas las interrupciones
   **/

  

} // disable_interrupts()



void interrupts_setting() {

  enable_interrupts();
  configure_control_registers();
  define_interrupt_vector_table();
 
}  // interrupts_setting()
