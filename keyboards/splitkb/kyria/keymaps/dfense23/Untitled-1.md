Sorry for the long post...
I have built a Kyria, works great, with one problem:
Only the OLED on the right keyboard half is working, the other stays black.
And it only works if the right is the master. If I plug in the left side, both stay black.

I tried the following, all with the above result:

1. switched the OLEDs from left to right: Both OLEDs are working, no hardware defect
2. Flashed the standard firmware
3. Built my own firmware, checking the code (as far as I can, I can write code, but c is not my strong suit). Basically copied the oled code from keyboards/splitkb/kyria/keymaps/rev3/rev3.c. (took out the code checking for master/slave)
4. followed the advice from the splitkb website https://docs.splitkb.com/hc/en-us/articles/360012737139-The-OLED-display-doesn-t-work
    a. Always flashed both halves
    b. Resoldered the socket, respectively added more solder
    c. measured the resistors  (I have SMD, so i measured across the holes for the wire resistors, all good)
5. Googled up and down....
6. In the meantime I have added a cirque trackpad. Same issue, only works on right half
7. As I am getting desperate, I measured the voltage between the Pins:
            left side           right side
    GND-VCC     4.9             4.9
    GND-SCL     4.5             3.7
    GND-SDA     3.7             3.7

GND-SCL on the problem side seems off...
Any help or hints would be appreciated.

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    ifndef RGBLIGHT_LIMIT_VAL
#    	define RGBLIGHT_LIMIT_VAL 150
#    endif
#endif
