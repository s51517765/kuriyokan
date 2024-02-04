#include "key_def.h"

// Key Map
// https://www.edu.i.hosei.ac.jp/~sigesada/kyouzai/mojicodehenkan.html
/*
 *  Key map
 * SW3 SW2 SW1
 * SW6 SW5 SW4
 *   SW8 SW7
 */
#define SW1 CTRL_C
#define SW2 CTRL_A
#define SW3 ALT_D
#define SW4 CTRL_X
#define SW5 CTRL_V
#define SW6 CTRL_Z
#define SW7 WIN_D
#define SW8 CTRL_ALT_DELETE
#define SW0 // This Keyboard has 8 keys. Not assigned.

// Setting
#define DEBUG_ENABLE 0 // debug_print and BUILTIN_LED 0 or 1
#define DELAY_MS 100
