#include QMK_KEYBOARD_H

#include <print.h>

enum ctrl_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout

    L_T_SPL,           //LED Toggle Splash Mode, background on or off
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_MUTE, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   KC_TRNS, KC_TRNS, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, L_T_SPL, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, L_T_MD,  L_T_ONF, KC_TRNS, KC_TRNS, MD_BOOT, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    */
};


/* python
print("".join([f"case '{c}':n=;break;{chr(10)
        if (ord(c)-ord('a')) % 3 == 2 else ''}"
        for c in "abcdefghijklmnopqrstuvwxyz"]))
        
        
a to z
52,69,67,54,37,55,56,57,42,58,59,60,71,70,43,44,35,38,53,39,41,68,36,66,40,65

print("\n".join([f"{{ .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .id{
        (int(n)-1)//32} = {1 << ((int(n) - 1) % 32)} }}," for n in
        ('52,69,67,54,37,55,56,57,42,58,59,60,71,70,43,' +
        '44,35,38,53,39,41,68,36,66,40,65').split(",")]))
        
print("".join([f"case KC_{c.upper()}:{chr(10)
        if (ord(c)-ord('a')) % 7 == 6 else ''}"
        for c in "abcdefghijklmnopqrstuvwxyz"]))
*/

/*

definitions of led_instruction is in /tmk_core/protocol/arm_atsam/led_matrix.h
definitions of value of KC_* is in /tmk_core/common/keycode.h

*/
// not including underglow layer
#define LED_NUMBERS (4 + 87 + 1)
typedef unsigned char _ub;
struct{
    bool WAVE_FRONT_ON;

} SPLASH_LED_CONFIG;
led_instruction_t led_instructions[LED_NUMBERS] = {
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,
            .id2 = 4278190080, .id3 = 1073741823}, // underglow
    { .flags = LED_FLAG_NULL }, // KC_ROLL_OVER => changed to KC_FN
    { .flags = LED_FLAG_NULL }, // KC_POST_FAIL
    { .flags = LED_FLAG_NULL }, // KC_UNDEFINED
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 524288 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 16 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 4 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 2097152 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 16 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 4194304 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 8388608 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 16777216 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 512 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 33554432 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 67108864 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 134217728 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 64 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 32 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 1024 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 2048 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 4 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 32 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 1048576 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 64 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 256 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 8 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 8 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 2 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id1 = 128 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 1 },
};

// I don't know what it does, it's just here
const uint16_t PROGMEM fn_actions[] = {

};
// (K)eycode (T)o (L)ed (I)d, KC_FN => 2, KC_A => 4, ...
_ub ktli(uint16_t keycode){
    /*
    print("".join(
            [f"case KC_{c.upper()}:return {ord(c)-ord('a'): >2};{
            chr(10) if (ord(c)-ord('a')) % 3 == 2 else ''}"
            for c in "abcdefghijklmnopqrstuvwxyz"]))
    
    */
    static _ub keycode_to_led_id[0x52 + 1] = {
        0, 0, 0, 0,
        52,69,67,54,37,55,56,57,42,58,59,60,71, // a - m
        70,43,44,35,38,53,39,41,68,36,66,40,65, // n - z
        18,19,20,21,22,23,24,25,26,27,          // 1 - 9, 0
        63, 1,30,34,80,28,29,45,46,47, 0,       // last 0 is KC_NONUS_HASH
        61,62,17,72,73,74,51,                   // 
         2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,    // KC_F1 - KC_F12
        14,15,16,31,32,33,48,49,50,             // the size keys above arrows
        87,85,86,76,                            // right, l, d, KC_UP = 0x52
        // remaining keycode are not presented on (default) ctrl
    };

    switch(keycode){ // ignore the keycode order
    case 20737:     return 82; // FN key
    case KC_POWER:  return 83; // KC_POWER  = 0x65

    case KC_LCTRL:  return 77; // KC_LCTRL  = 0xE0
    case KC_LSHIFT: return 64; // KC_LSHIFT = 0xE1
    case KC_LALT:   return 79; // KC_LALT   = 0xE2
    case KC_LGUI:   return 78; // KC_LGUI   = 0xE3
    case KC_RCTRL:  return 84;
    case KC_RSHIFT: return 75;
    case KC_RALT:   return 81;
    case KC_RGUI:   return 0; // not exists on ctrl
    }
    if(0x04 <= keycode && keycode <= (0x52 + 5)){
        return keycode_to_led_id[keycode];
    }
    return 0; // I'm afraid '-1' will break something
};
/*
shortest distance between two keys


*/
static _ub DISTANCE_MAP[LED_NUMBERS][LED_NUMBERS]; // max number of keys (not key codes)

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    print("matrix_init_user(): initialization");
    /*
    initialize key distances
    I am not sure if MO(1) < unsigned char max
    */
    unsigned short KEY_POSITION_MAP[5][15] = {
        { KC_NO,  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC, },
            { KC_NO,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,   KC_BSLS, },
                { KC_NO,  KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,   KC_QUOT,   KC_ENT,    KC_ENT, },
                    { KC_NO,  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,   KC_RSFT,  KC_RSFT,   KC_RSFT, },
                        { KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,   KC_RALT,   KC_NO,   20737,   KC_POWER,  KC_RCTL,  KC_RCTL, },
    };
    // it's not bfs
    _ub x = 0, y = 0;
    while(x < 15 && y < 5){
        _ub sl = ktli(KEY_POSITION_MAP[y][x]); // source led
        for(_ub i = 0; i < 15; ++i){
            for(_ub j = 0; j < 5; ++j){
                _ub tl = ktli(KEY_POSITION_MAP[j][i]); // target led
                if(sl == tl) continue;
                
                _ub dx = abs(i - x), dy = abs(j - y);

                _ub dis = dx + dy;
                if(i < x && j > y){
                    dis -= dx < dy ? dx : dy;
                }
                _ub _dis = DISTANCE_MAP[sl][tl];
                
                if(_dis && _dis <= dis)  continue;
                
                DISTANCE_MAP[sl][tl] = dis;
                DISTANCE_MAP[tl][sl] = dis;
            }
        }
        if(x < 14){
            ++x;
        } else{
            x = 0;
            ++y;
        }
    }
    /*
    finished initializing key distances

    now start doing led_instructions
    */
    
    // underglow
    led_instructions[0].flags =
            LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN;
    led_instructions[0].id2 = 4278190080;
    led_instructions[0].id3 = 1073741823;

    // suppose to iterate 87 times for a 87 keys keyboard
    uint16_t flag = LED_FLAG_MATCH_ID | (
            SPLASH_LED_CONFIG.WAVE_FRONT_ON ?
            LED_FLAG_USE_ROTATE_PATTERN :
            LED_FLAG_USE_RGB);
    for(int i = 4; i < LED_NUMBERS-1; ++i){
        led_instructions[i].flags = flag;
        
        uint32_t id = 1 << ((i-1) % 32);
        switch((i-1) / 32){
        case 0: led_instructions[i].id0 = id; break;
        case 1: led_instructions[i].id1 = id; break;
        case 2: led_instructions[i].id2 = id; break;
        case 3: led_instructions[i].id3 = id; break;
        }

        // one line alternative
        // (led_instructions[i].id0 + sizeof(uint32_t) * (i-1) / 32)
    }


};

// Runs constantly in the background, in a loop.

uint32_t LAST_PRESSED_LED_TIMERS[LED_NUMBERS];
void matrix_scan_user(void) {
    // keyboard_leds()
    _ub wave_front[LED_NUMBERS];
    for(int i = 4; i < LED_NUMBERS; ++i){
        wave_front[i] = false;
        for(int j = 4; j < LED_NUMBERS; ++j){
            if(i == j) continue;
            uint32_t e = timer_elapsed32(LAST_PRESSED_LED_TIMERS[j]);
            _ub dis = DISTANCE_MAP[i][j];
            if(( dis != 0 ) && ( e / 200 == dis )){
                wave_front[i] = true;
                break;
            }
        }
    }
    // print("onlist: ");
    for(int i = 4; i < LED_NUMBERS; ++i){
        // uprintf("%d ", wave_front[i]);
        if(wave_front[i] ^ SPLASH_LED_CONFIG.WAVE_FRONT_ON){
            led_instructions[i].flags =
                    LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB;
        } else{
            led_instructions[i].flags =
                    LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN;
            // rgb default is zero
        }
    }
    // print("\n");
};


/*

make massdrop/ctrl:valen214


./.build/mdloader_windows.exe --first --download massdrop_ctrl_valen214.bin --restart


*/

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;

        case L_T_SPL:
            if (record->event.pressed) {
                SPLASH_LED_CONFIG.WAVE_FRONT_ON ^= 1;
                uint16_t flag = LED_FLAG_MATCH_ID | (
                        SPLASH_LED_CONFIG.WAVE_FRONT_ON ?
                        LED_FLAG_USE_ROTATE_PATTERN :
                        LED_FLAG_USE_RGB);
                for(int i = 4; i < LED_NUMBERS-1; ++i){
                    led_instructions[i].flags = flag;
                }
            }
            return false;
        // these are the keys not in range 0x04 - 0x52
        case KC_POWER:
        case KC_LCTRL:
        case KC_LSHIFT:
        case KC_LALT:
        case KC_LGUI:
        case KC_RCTRL:
        case KC_RSHIFT:
        case KC_RALT:
        case 20737: // FN key
            if (record->event.pressed) {
                uprintf("%d pressed\n", keycode);
                LAST_PRESSED_LED_TIMERS[ktli(keycode)] = timer_read32();
            }
            return true;
        default:
            /*
            for reference to key code value, see:
            /tmk_core/common/keycode.h(195): enum hid_keyboard_keypad_usage
            */
            if (record->event.pressed &&
                    keycode >= 0x04 && // 4: KC_A
                    keycode <= 0x52){ // 164: KC_RIGHT
                uprintf("%d pressed\n", keycode);
                LAST_PRESSED_LED_TIMERS[ktli(keycode)] = timer_read32();
            }
            return true; //Process all other keycodes normally
    }
}