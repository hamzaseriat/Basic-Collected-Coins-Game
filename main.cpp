#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

#define BOARDY 12
#define BOARDX 200

char Rlboard[BOARDY][BOARDX];
int MoveTheCamera(int x, char mv);
void MovePlayer(char mv, int &x, int &y, int &score);
void GameArenaCreate() {


    for (int i = 0; i < BOARDY; i++) {
        for (int j = 0; j < BOARDX; j++) {
            if (i == 0 || i == BOARDY - 1 || j == 0 || j == BOARDX - 1)
                Rlboard[i][j] = '#';
            else
                Rlboard[i][j] = ' ';
        }
    }


    for (int t = 0; t < 100; t++) {
        int possibley = (rand() % 10) + 1;
        int possiblex;

        do {
            possiblex = rand() % (BOARDX - 4) + 2;
        } while (possiblex < 8 || possiblex > BOARDX - 5);

        for (int k = 0; k < 3; k++) {
            Rlboard[possibley][possiblex + k] = '-';
        }
    }

    for(int c = 0;c < 20 ; c++){
       int coinsy = rand() % (BOARDY - 2) + 1;
        int coinsx;
        do{
            coinsx = rand() % (BOARDX - 4) + 2;
        }while (coinsx < 12 || coinsx > BOARDX - 8 || Rlboard[coinsy][coinsx] != ' ');

Rlboard[coinsy][coinsx] = '$';
    }



}

void checkthearena(int x) {

    int beginnx = x - 8;
    if (beginnx < 0)
        beginnx = 0;

    int endx = beginnx + 30;
    if (endx > BOARDX)
        endx = BOARDX;

    for (int j = 0; j < BOARDY; j++) {
        for (int i = beginnx; i < endx; i++) {
            cout << Rlboard[j][i];
        }
        cout << endl;
    }
}

int MoveTheCamera(int x, char mv) {

    if (mv == 'a' && x > 0)
        return x - 1;
    else if (mv == 'd' && x < BOARDX - 1)
        return x + 1;

    return x;
}
void MovePlayer(char mv, int &x, int &y, int &score,bool &gameend,bool &result) {

    int newX = x;
    int newY = y;

    if (mv == 'a') newX--;
    else if (mv == 'd') newX++;
    else if (mv == 'w') newY--;
    else if (mv == 's') newY++;


    if (newX < 0 || newX >= BOARDX || newY < 0 || newY >= BOARDY)
        return;


    if (Rlboard[newY][newX] == '#')
        return;
    if(Rlboard[newY][newX] == '-' || Rlboard[newY][newX] == '|' ){
        gameend = true;
        result = false;
    }
    if(Rlboard[newY][newX] == 'E'){
    gameend = true;
    result = true;
    }

    if (Rlboard[newY][newX] == '$') {
        score++;
        Beep(800, 100);
    }


    // eski konumu temizle
    Rlboard[y][x] = ' ';

    // yeni konuma geç
    x = newX;
    y = newY;
    Rlboard[y][x] = '@';
}
void Level2_Coins(){

    for(int c = 0;c < 20 ; c++){
       int coinsy = rand() % (BOARDY - 2) + 1;
        int coinsx;
        do{
            coinsx = rand() % (BOARDX - 4) + 2;
        }while (coinsx < 12 || coinsx > BOARDX - 8 || Rlboard[coinsy][coinsx] != ' ');

Rlboard[coinsy][coinsx] = '$';
    }


}
void Level3_Coins(){
for(int c = 0;c<20;c++){
    int level3cy = rand() % (BOARDY - 2 ) + 1;
    int level3cx;
    do{
        level3cx = rand() % (BOARDX - 4) + 2;
    }while(level3cx < 12 || level3cx >  BOARDX - 8 || Rlboard[level3cy][level3cx] != ' ');
    Rlboard[level3cy][level3cx] = '$';
}


}

void gatefunction(){
    for (int t = 0; t < 160; t++) {
        int blocky = (rand() % 10) + 1;
        int blockx;

        do {
            blockx = rand() % (BOARDX - 4) + 2;
        } while ( blockx < 8 || blockx > BOARDX - 5);

Rlboard[blocky][blockx] = '-';
    }
    for (int t = 0; t < 160; t++) {
        int blockupy = (rand() % 10) + 1;
        int blockupx;

        do {
            blockupx = rand() % (BOARDX - 4) + 2;
        } while ( blockupx < 8 || blockupx > BOARDX - 5);

Rlboard[blockupy][blockupx] = '|';
}
Rlboard[11][45] = 'E';

}


int main() {

    int playerx = 5;
    int playery = 9;   // duvar değil
    int score = 0;bool gameresult = false;
    bool gamend = false; // It works when player doesnt move the colons
    bool level2gate = false;bool level3gate = false;bool gatepart = false;
    time_t gateStartTime;
    bool gateTimerStarted = false;
    const int GATE_TIME_LIMIT = 180; // 3 dakika

    srand(time(NULL));

    GameArenaCreate();

    Rlboard[playery][playerx] = '@';

    static int currentx = 8;
    char movement;

    while (true) {

        checkthearena(currentx);
        if (gateTimerStarted) {
    int elapsed = time(NULL) - gateStartTime;
    int remaining = GATE_TIME_LIMIT - elapsed;

    if (remaining <= 0) {
        gamend = true;
        gameresult = false; // süre bitti → kayıp
        for(int k=0;k<12;k++){
            for(int t= 0;t<200;t++){
                Rlboard[k][t] = 'X';
            }
        }
        break;
    }

    cout << "Time Left: "
         << remaining / 60 << "m "
         << remaining % 60 << "s" << endl;
}

      cout << "Score: " << score << endl;
      if(score >= 60)
cout << "Find The Escape Gate"<<endl;
        movement = getch();
        MovePlayer(movement, playerx, playery, score,gamend,gameresult);

    if (!level2gate && score >= 20) {
    Level2_Coins();
    level2gate = true;
}
if(!level3gate && score >= 40){
    Level3_Coins();
    level3gate = true;
}
if(!gatepart && score >= 60){
        gatefunction();
        gatepart = true;
        gateStartTime = time(NULL);   // ⏱️ zaman burada başlar
        gateTimerStarted = true;

}

if(gamend == true){
    break;
}

        currentx = MoveTheCamera(currentx, movement);
        system("cls");
    }

    if(gameresult == true){
        cout << "Congrulations you won!!";
    }
    else{
        cout  << "Game Over Try again :((";
    }







    return 0;
}


