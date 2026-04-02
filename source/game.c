#include <gba_video.h>

#define SCREEN_WIDTH 240
#define RGB15(r,g,b) ((r) | (g)<<5 | (b)<<10)
#define VIDEO_BUFFER ((u16*)0x6000000)

int fill = 0;

void gameUpdate() {
    fill++;
    if(fill > 100) fill = 0;
}

void drawRect(int x, int y, int w, int h, u16 color) {
    for(int r=0;r<h;r++){
        for(int c=0;c<w;c++){
            VIDEO_BUFFER[(y+r)*SCREEN_WIDTH + (x+c)] = color;
        }
    }
}

void gameDraw() {
    drawRect(0,0,240,160, RGB15(0,0,0)); // fondo

    drawRect(100,30,40,100, RGB15(31,31,31)); // vaso

    int h = fill;
    drawRect(105,130-h,30,h, RGB15(31,20,0)); // root beer
}
