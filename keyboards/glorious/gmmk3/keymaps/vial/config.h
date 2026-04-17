#pragma once

/* Vial requires a unique UID for each keyboard definition.
 * Replace this with your own random 8-byte sequence before distributing.
 */
#define VIAL_KEYBOARD_UID {0x93, 0x61, 0x8A, 0x70, 0x2C, 0x18, 0x4E, 0xB1}

/* Unlock combo for Vial (row,col pairs). Adjust based on your matrix. */
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

/* Baseline tuning for GMMK 3 65% ANSI */
#define DEBOUNCE 5
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 160
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
#define RGB_MATRIX_DEFAULT_SPD 96
#define RGB_DISABLE_WHEN_USB_SUSPENDED
