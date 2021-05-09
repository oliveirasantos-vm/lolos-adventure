#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

#include "windows.c"
#include "game.c"

#define MAX_INPUT_CHARS 10
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
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Lolo's Adventure");

    Font font = LoadFont("resources/fonts/pixantiqua.png");
    int window = 0;

    Texture2D images[50] = {LoadTexture("resources/floorpattern.png"),
                            LoadTexture("resources/objects/wallinternal.png"),
                            LoadTexture("resources/objects/door.png"),
                            LoadTexture("resources/objects/rock.png"),
                            LoadTexture("resources/objects/tree.png"),
                            LoadTexture("resources/objects/hearthblock.png"),
                            LoadTexture("resources/characters/snakey.png"),
                            LoadTexture("resources/objects/chest-close.png"),
                            LoadTexture("resources/characters/lolo.png"),
                            LoadTexture("resources/objects/wall.png"),
                            LoadTexture("resources/objects/wallside.png"),
                            LoadTexture("resources/objects/wallcorner1.png"),
                            LoadTexture("resources/objects/wallcorner2.png"),
                            LoadTexture("resources/objects/wallcorner3.png"),
                            LoadTexture("resources/objects/wallcorner4.png"),
                            LoadTexture("resources/objects/water.png"),
                            LoadTexture("resources/objects/shots.png"),
                            LoadTexture("resources/objects/pw.png"),
                            LoadTexture("resources/objects/square.png"),
                            LoadTexture("resources/objects/score.png"),
                            LoadTexture("resources/save.png"),
                            LoadTexture("resources/exit.png"),
                            LoadTexture("resources/objects/chest-open.png"),
                            LoadTexture("resources/objects/open-door.png"),
                            LoadTexture("resources/objects/lolo-on-chest.png"),
                            LoadTexture("resources/objects/lolo-on-open-chest.png"),
                            LoadTexture("resources/objects/chest-empty.png"),
                            LoadTexture("resources/objects/ladder.png"),
                            LoadTexture("resources/objects/emeraldframer.png"),
                            LoadTexture("resources/characters/gol.png"),
                            LoadTexture("resources/characters/skull.png"),
                            LoadTexture("resources/characters/rocky.png"),
                            LoadTexture("resources/characters/alma.png"),
                            LoadTexture("resources/characters/donmedusa.png"),
                            LoadTexture("resources/characters/medusa.png"),
                            LoadTexture("resources/objects/grass.png"),
                            LoadTexture("resources/characters/leeper.png"),
                            LoadTexture("resources/objects/ladder-side.png"),
                            LoadTexture("resources/objects/arrow-top.png"),
                            LoadTexture("resources/objects/lolo-on-grass.png"),
                            LoadTexture("resources/objects/lolo-on-ladder.png"),
                            LoadTexture("resources/objects/lolo-on-ladder-side.png"),
                            LoadTexture("resources/objects/explosive-rock.png"),
                            LoadTexture("resources/objects/hammer.png"),
                            LoadTexture("resources/objects/lolo-on-arrow-top.png")};

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        switch(window){
            case 0:
                window = menu(window, font);
                break;
            case 1:
                window = credits(window, font);
                break;
            case 2:
                window = loadGame(window, font);
                break;
            case 3:
                window = player(window, font);
                break;
            case 4:
                window = game(window, font, images);
                break;
            case 5:
                window = removeSave(window, font);
                break;
            case 6:
                window = gameover(window, font);
                break;
            default:
                CloseWindow();
                break;
        }
    }
    return 0;
}
