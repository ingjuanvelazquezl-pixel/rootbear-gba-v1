#include <gba_systemcalls.h>
#include <gba_video.h>

#include "game.h"

int main(void) {
    SetMode(MODE_3 | BG2_ENABLE);

    while (1) {
        VBlankIntrWait();
        gameUpdate();
        gameDraw();
    }
}
