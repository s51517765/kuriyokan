// 認識しないとき、RSTをGNDに2回
// 書き込めないとき、書き込み始めたらRSTをGNDに1回

#include <Keyboard.h>
#include "setting.h"

#define BUILTIN_LED 30

const uint8_t OUTPUT_PORT[] = {2, 3, 4}; // 2,3,4
const uint8_t INPUT_PORT[] = {8, 7, 6};  // 5,6,7,8
const uint8_t CN = pow(2, (sizeof(INPUT_PORT) / sizeof(uint8_t)) - 1);

const uint16_t key_codes[] = {SW1, SW2, SW3, SW4, SW5, SW6, SW7, SW8, SW0};
// 文字列定義 必要に応じてサイズは拡大可能
const uint8_t str_codes[2][8] = {{0x6b, 0x75, 0x72, 0x69, KEY_RETURN, NONE, NONE, NONE}, {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE}};

void debug_print(uint16_t code)
{
    if (DEBUG_ENABLE)
    {
        Serial.print("0x");
        Serial.println(code, HEX);
    }
}

void setup()
{
    for (uint8_t i = 0; i < sizeof(OUTPUT_PORT); i++)
    {
        pinMode(OUTPUT_PORT[i], OUTPUT);
        digitalWrite(OUTPUT_PORT[i], HIGH);
    }
    for (uint8_t i = 0; i < sizeof(INPUT_PORT); i++)
    {
        pinMode(INPUT_PORT[i], INPUT_PULLUP);
    }
    Keyboard.releaseAll();
    if (DEBUG_ENABLE)
    {
        Serial.begin(115200);
    }
    else
    {
        pinMode(BUILTIN_LED, INPUT);
    }
}

uint16_t key_scan()
{
    uint16_t key_pressed = 0;
    for (uint8_t col = 0; col < sizeof(OUTPUT_PORT); col++)
    {
        digitalWrite(OUTPUT_PORT[col], LOW);
        uint16_t row_data = 0;
        for (uint8_t row = 0; row < sizeof(INPUT_PORT); row++)
        {
            row_data |= (digitalRead(INPUT_PORT[row]) ? 0 : CN >> row);
        }
        key_pressed |= (row_data << (sizeof(INPUT_PORT) * col));
        digitalWrite(OUTPUT_PORT[col], HIGH);
    }
    return key_pressed;
}

void loop()
{
    static uint8_t last_key_pressed = 0;
    uint16_t key_pressed = key_scan();
    uint16_t change = key_pressed ^ last_key_pressed;
    if (change)
    {
        uint16_t mask = 1;
        uint16_t code;

        for (uint8_t i = 0; i < sizeof(key_codes); i++)
        {
            if (change & mask)
            {
                code = key_codes[i];

                if (key_pressed & mask)
                {
                    if ((code & STR_0) != 0)
                    {
                        // 文字列
                        for (uint8_t i = 0; i < sizeof(str_codes[0]) / sizeof(str_codes[0][0]); i++)
                        {
                            Keyboard.press(str_codes[code & 0x0F][i]);
                            debug_print(str_codes[code & 0x0F][i]);
                            delay(10);
                        }
                    }
                    else if (code == CTRL_ALT_DELETE)
                    {
                        Keyboard.press(KEY_LEFT_CTRL);
                        Keyboard.press(KEY_LEFT_ALT);
                        Keyboard.press(KEY_DELETE);
                    }
                    else if (code & 0x100)
                    {
                        Keyboard.press(KEY_LEFT_CTRL);
                    }
                    else if (code & 0x200)
                    {
                        Keyboard.press(KEY_LEFT_SHIFT);
                    }
                    else if (code & 0x400)
                    {
                        Keyboard.press(KEY_LEFT_GUI); // WINDOWS
                    }
                    else if (code & 0x800)
                    {
                        Keyboard.press(KEY_LEFT_ALT);
                    }
                    Keyboard.press(code & 0xFF);

                    delay(10);
                    debug_print(code);
                    Keyboard.releaseAll();
                }
            }
            mask = mask << 1;
        }
        last_key_pressed = key_pressed;
    }
    delay(DELAY_MS);
}
