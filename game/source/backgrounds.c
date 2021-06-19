/********************************************************** 
 * backgrounds.c
 *
 * Este codigo se ha implementado basandose en el ejemplo 
 * "Simple sprite demo" de dovoto y otro de Jaeden Amero
 **********************************************************/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
 * Anadir aquí los includes para cada fondo [gfx]
 **/

//#include "back01.h"
//#include "back02.h"
#include "backstars00.h"
#include "backstars01.h"
#include "backstars02.h"
#include "backstars03.h"
#include "backstars04.h"
#include "backstars05.h"
#include "backstars06.h"
#include "backstars07.h"
#include "backstars08.h"
#include "backstars09.h"
#include "backstars10.h"
#include "backstars11.h"
#include "backstars12.h"
#include "backstars13.h"
#include "backstars14.h"
#include "backstars15.h"
#include "backstars16.h"
#include "backstars17.h"
#include "backstars18.h"
#include "backstars19.h"
#include "backstars20.h"
#include "backstars21.h"

#include "b00.h"
#include "b01.h"
#include "b02.h"
#include "b03.h"
#include "b04.h"
#include "b05.h"
#include "b06.h"
#include "b07.h"
#include "b08.h"
#include "b09.h"
#include "b10.h"
//#include "b11.h"

#include "play1.h"
#include "play2.h"
#include "options1.h"
#include "options2.h"
#include "exit1.h"
#include "exit2.h"

#include "pause1.h"
#include "pause2.h"

/* 
 * Seleccionar un canal DMA para copiar a memoria las imágenes
 **/
static const int DMA_CHANNEL = 3;


/* 
 * Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones
 **/

/*
void display_back01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}
*/

/*
void display_back02() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}
*/

void display_backstars00() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars00Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars01Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars02() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars02Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars03() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars03Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars04() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars04Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars05() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars05Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars06() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars06Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars07() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars07Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars08() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars08Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars09() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars09Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars10() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars10Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars11() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars11Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars12() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars12Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars13() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars13Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars14() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars14Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars15() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars15Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars16() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars16Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars17() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars17Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars18() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars18Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars19() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars19Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars20() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars20Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_backstars21() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     backstars21Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b00() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b00Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b01Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b02() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b02Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b03() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b03Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b04() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b04Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b05() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b05Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b06() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b06Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b07() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b07Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b08() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b08Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b09() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b09Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_b10() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b10Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

/*
void display_b11() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     b11Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}
*/
/*
*Logo animation
**/

void display_play1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     play1Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_play2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     play2Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_options1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     options1Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_options2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     options2Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_exit1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     exit1Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_exit2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     exit2Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_pause1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     pause1Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_pause2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     pause2Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     backstars00BitmapLen);          // Longitud (en bytes) generada automáticamente 
}


/* 
 * Definir el sistema de video
 **/
void init_video() {
    /* 
     * Mapear la memoria VRAM para mostrar graficos en las dos pantallas
     **/
    vramSetMainBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_E_LCD);
    vramSetBankE(VRAM_E_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    /* 
     * Establecer el modo de video de la pantalla principal
     **/
    videoSetMode(MODE_5_2D | // Establecer el modo grafico 5
                 DISPLAY_BG2_ACTIVE | // Activar el fondo 2
                 DISPLAY_BG3_ACTIVE); // Activar el fondo 3

    /* 
     * Establecer el modo de video de la pantalla secundaria
     **/
        videoSetModeSub(MODE_5_2D | // Establecer el modo grafico 5
                    DISPLAY_BG3_ACTIVE); // Activar el fondo 3
} // init_video()



/* 
 * Procedimiento para configurar el sistema de fondos
 **/
void init_background() {
    /* 
     * Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits
     **/
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) |   // La dirección inicial de memoria
                 BG_PRIORITY(3);    // Baja prioridad

    /* 
     * Establecer la matriz de transformación afin del fondo 3 de la pantalla principal
     * a la matriz de identidad
     **/
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

    /* 
     * Definir la situación del fondo 3 de la pantalla principal. 
     * Esto deberá cambiar según la posición en la que se quiera poner el gráfico
     **/
    REG_BG3X = 0;
    REG_BG3Y = 0;

    /* 
     * Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits
     **/
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) |   // La dirección inicial de memoria
                 BG_PRIORITY(2);    // Baja prioridad

    /* 
     * Establecer la matriz de transformación afin del fondo 2 de la pantalla principal 
     * a la matriz de identidad
     **/
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

    /* 
     * Definir la situación del fondo 2 de la pantalla principal. 
     * Esto deberá cambiar según la posición en la que se quiera poner el gráfico
     **/
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;

    /* 
     * Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits
     **/
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) |   // La dirección inicial de memoria
                     BG_PRIORITY(3);    // Baja prioridad

    /* 
     * Establecer la matriz de transformación afin del fondo 3 de la pantalla secundaria
     * a la matriz de identidad
     **/
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

    /* 
     * Definir la situación del fondo 3 de la pantalla secundaria
     * Esto deberá cambiar según la posición en la que se quiera poner el gráfico
     **/
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;

} // init_background()

