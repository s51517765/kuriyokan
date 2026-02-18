typedef enum
{
  CTRL = 0x100,
  CTRL_A = 0x161,
  CTRL_B,
  CTRL_C,
  CTRL_D,
  CTRL_E,
  CTRL_F,
  CTRL_G,
  CTRL_H,
  CTRL_I,
  CTRL_J,
  CTRL_K,
  CTRL_L,
  CTRL_M,
  CTRL_N,
  CTRL_O,
  CTRL_P,
  CTRL_Q,
  CTRL_R,
  CTRL_S,
  CTRL_T,
  CTRL_U,
  CTRL_V,
  CTRL_W,
  CTRL_X,
  CTRL_Y,
  CTRL_Z,

  CTRL_ALT_DELETE = 0x1FF,
} KEY_CTRL;

typedef enum
{
  SHIFT = 0x200,
  SHIFT_A = 0x261,
  SHIFT_B,
  SHIFT_C,
  SHIFT_D,
  SHIFT_E,
  SHIFT_F,
  SHIFT_G,
  SHIFT_H,
  SHIFT_I,
  SHIFT_J,
  SHIFT_K,
  SHIFT_L,
  SHIFT_M,
  SHIFT_N,
  SHIFT_O,
  SHIFT_P,
  SHIFT_Q,
  SHIFT_R,
  SHIFT_S,
  SHIFT_T,
  SHIFT_U,
  SHIFT_V,
  SHIFT_W,
  SHIFT_X,
  SHIFT_Y,
  SHIFT_Z,
} KEY_SHIFT;

typedef enum
{
  WIN = 0x400,
  WIN_A = 0x461,
  WIN_B,
  WIN_C,
  WIN_D,
  WIN_E,
  WIN_F,
  WIN_G,
  WIN_H,
  WIN_I,
  WIN_J,
  WIN_K,
  WIN_L,
  WIN_M,
  WIN_N,
  WIN_O,
  WIN_P,
  WIN_Q,
  WIN_R,
  WIN_S,
  WIN_T,
  WIN_U,
  WIN_V,
  WIN_W,
  WIN_X,
  WIN_Y,
  WIN_Z,
} KEY_WINDOWS;

typedef enum
{
  ALT = 0x800,
  ALT_A = 0x861,
  ALT_B,
  ALT_C,
  ALT_D,
  ALT_E,
  ALT_F,
  ALT_G,
  ALT_H,
  ALT_I,
  ALT_J,
  ALT_K,
  ALT_L,
  ALT_M,
  ALT_N,
  ALT_O,
  ALT_P,
  ALT_Q,
  ALT_R,
  ALT_S,
  ALT_T,
  ALT_U,
  ALT_V,
  ALT_W,
  ALT_X,
  ALT_Y,
  ALT_Z,
} KEY_ALT;

typedef enum
{
  STR_0 = 0x1000,
  STR_1,
} STR_CODE;

typedef enum
{
  WHEEL_SCROLL_UP = 0x2001,
  WHEEL_SCROLL_DOWN,
  WHEEL_SCROLL_UP_CTRL,
  WHEEL_SCROLL_DOWN_CTRL,
  WHEEL_SCROLL_UP_SHIFT,
  WHEEL_SCROLL_DOWN_SHIFT,
} WHEEL_SCROLL;

#define KEY_COPY CTRL_C
#define KEY_CUT CTRL_X
#define KEY_PASTE CTRL_V
#define KEY_SELECT_ALL CTRL_A
#define KEY_MAP_PAGE_TOGGLE 0xFF00
#define NONE 0

