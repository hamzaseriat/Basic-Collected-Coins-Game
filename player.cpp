#include <windows.h>
#include "arena.h"
#include "player.h"

void MovePlayer(char mv, int &x, int &y, int &score,
                bool &gameend, bool &result) {

    int newX = x;
    int newY = y;

    if (mv == 'a') newX--;
    else if (mv == 'd') newX++;
    else if (mv == 'w') newY--;
    else if (mv == 's') newY++;

    if (newX < 0 || newX >= BOARDX ||
        newY < 0 || newY >= BOARDY)
        return;

    if (Rlboard[newY][newX] == '#')
        return;

    if (Rlboard[newY][newX] == '-' ||
        Rlboard[newY][newX] == '|') {
        gameend = true;
        result = false;
    }

    if (Rlboard[newY][newX] == 'E') {
        gameend = true;
        result = true;
    }

    if (Rlboard[newY][newX] == '$') {
        score++;
        Beep(800, 100);
    }

    Rlboard[y][x] = ' ';
    x = newX;
    y = newY;
    Rlboard[y][x] = '@';
}
