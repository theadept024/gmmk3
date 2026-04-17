#pragma once

/*
 * Template keyboard-level config for GMMK 3 P65 ANSI.
 *
 * IMPORTANT: replace matrix pins / electrical settings with real values
 * from your PCB before attempting to flash production firmware.
 */

#define VENDOR_ID       0x320F
#define PRODUCT_ID      0x5055
#define DEVICE_VER      0x0001
#define MANUFACTURER    Glorious
#define PRODUCT         GMMK_3_P65_ANSI

#define MATRIX_ROWS 5
#define MATRIX_COLS 14
#define DIODE_DIRECTION COL2ROW

/* Example placeholders — replace with your actual MCU pin mapping.
// #define MATRIX_ROW_PINS { D0, D1, D2, D3, D5 }
// #define MATRIX_COL_PINS { B0, B1, B2, B3, B4, B5, B6, B7, C6, C7, F0, F1, F4, F5 }
*/
