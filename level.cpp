#include <cstdlib>
#include "arena.h"
#include "levels.h"

void Level2_Coins() {

    for (int c = 0; c < 20; c++) {
        int y = rand() % (BOARDY - 2) + 1;
        int x;

        do {
            x = rand() % (BOARDX - 4) + 2;
        }
        while (Rlboard[y][x] != ' ');

        Rlboard[y][x] = '$';
    }
}

void Level3_Coins() {

    for (int c = 0; c < 20; c++) {
        int y = rand() % (BOARDY - 2) + 1;
        int x;

        do {
            x = rand() % (BOARDX - 4) + 2;
        }
        while (Rlboard[y][x] != ' ');

        Rlboard[y][x] = '$';
    }
}

void GateFunction() {

    for (int t = 0; t < 160; t++) {
        int y = rand() % (BOARDY - 2) + 1;
        int x = rand() % (BOARDX - 4) + 2;
        Rlboard[y][x] = '-';
    }

    for (int t = 0; t < 160; t++) {
        int y = rand() % (BOARDY - 2) + 1;
        int x = rand() % (BOARDX - 4) + 2;
        Rlboard[y][x] = '|';
    }

    Rlboard[11][45] = 'E';
}
