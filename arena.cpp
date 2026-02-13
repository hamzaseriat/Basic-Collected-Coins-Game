#include <iostream>
#include <cstdlib>
#include "arena.h"

using namespace std;

char Rlboard[BOARDY][BOARDX];

void GameArenaCreate() {

    for (int i = 0; i < BOARDY; i++) {
        for (int j = 0; j < BOARDX; j++) {
            if (i == 0 || i == BOARDY - 1 || j == 0 || j == BOARDX - 1)
                Rlboard[i][j] = '#';
            else
                Rlboard[i][j] = ' ';
        }
    }
}

void CheckArena(int x) {

    int begin = x - 8;
    if (begin < 0) begin = 0;

    int end = begin + 30;
    if (end > BOARDX) end = BOARDX;

    for (int j = 0; j < BOARDY; j++) {
        for (int i = begin; i < end; i++)
            cout << Rlboard[j][i];
        cout << endl;
    }
}
