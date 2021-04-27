#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include "windows.c"
#include "game.c"

#define MAX_INPUT_CHARS 8
#define SCREEN_WIDTH 640
#define SCREEN_HEIGTH 480

typedef struct GRAVACAO {
    char id;
    char totalpts;
    char ultimafase;
    char vidas;
    char nomejogador[8];
} Gravacao, * pGravacao;

int main(){
    int window = 0;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Lolo's Adventure");
    Font pixantiqua = LoadFont("resources/fonts/pixantiqua.png");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        switch(window){
            case 0:
                window = menu(window, pixantiqua);
                break;
            case 1:
                window = credits(window, pixantiqua);
                break;
            case 2:
                window = loadGame(window, pixantiqua);
                break;
            case 3:
                window = player(window, pixantiqua);
                break;
            case 4:
                window = game(window, pixantiqua);
                break;
            default:
                CloseWindow();
                break;
        }
    }
    return 0;
}
