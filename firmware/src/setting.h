#include "key_def.h"

// Key Map
// https://www.edu.i.hosei.ac.jp/~sigesada/kyouzai/mojicodehenkan.html
/*
 *  Key map
 * SW3 SW2 SW1
 * SW6 SW5 SW4
 *   SW8 SW7
 */

// KEY MAP 1st PAGE
#define SW01 CTRL_V
#define SW02 CTRL_F
#define SW03 CTRL_A
#define SW04 CTRL_C
#define SW05 CTRL_X
#define SW06 CTRL_Z
#define SW07 KEY_MAP_PAGE_TOGGLE
#define SW08 WIN_D
#define SW00 // This Keyboard has 8 keys. Not assigned.
// KEY MAP 2nd PAGE
#define SW11 NONE
#define SW12 WHEEL_SCROLL_DOWN_SHIFT
#define SW13 NONE
#define SW14 WHEEL_SCROLL_UP_CTRL
#define SW15 WHEEL_SCROLL_UP_SHIFT
#define SW16 WHEEL_SCROLL_DOWN_CTRL
#define SW17 KEY_MAP_PAGE_TOGGLE
#define SW18 WIN_D
#define SW10 // This Keyboard has 8 keys. Not assigned.

// Setting
#define DEBUG_ENABLE 0 // debug_print and BUILTIN_LED 0 or 1
#define DELAY_MS 100
