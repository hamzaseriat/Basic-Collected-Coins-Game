#include "arena.h"
#include "camera.h"

int MoveTheCamera(int x, char mv) {

    if (mv == 'a' && x > 0) return x - 1;
    if (mv == 'd' && x < BOARDX - 1) return x + 1;

    return x;
}
