#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

#define MAX_INPUT_CHARS 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGTH 480

char map[14][13] = {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                    {'|','W','W','W','W','W','W','D','W','W','W','W','|'},
                    {'|','R','R','R','R','R','R','.','R','R','T','T','|'},
                    {'|','R','T','T','R','H','.','.','R','R','T','T','|'},
                    {'|','.','T','T','R','R','R','.','R','R','R','T','|'},
                    {'|','.','.','T','T','R','R','.','R','R','R','T','|'},
                    {'|','L','.','.','.','R','R','.','R','R','T','H','|'},
                    {'|','.','.','.','.','.','.','S','.','R','.','.','|'},
                    {'|','.','T','T','.','.','.','.','.','.','.','.','|'},
                    {'|','T','T','T','T','.','.','.','T','T','.','.','|'},
                    {'|','T','T','T','T','.','.','.','T','T','T','.','|'},
                    {'|','R','T','T','R','K','.','.','.','T','T','.','|'},
                    {'|','R','R','R','R','R','R','.','.','.','.','.','|'},
                    {'3','-','-','-','-','-','-','-','-','-','-','-','4'}};

#define floorPattern LoadTexture("resources/floorpattern.png");



int game(int window, Font font){

    SetTextureFilter(floorPattern, TEXTURE_FILTER_TRILINEAR);

    const Rectangle floorRec = {112, 16, 416, 448};

const Texture2D door = LoadTexture("resources/objects/door.png");
const Texture2D wall = LoadTexture("resources/objects/wall.png");
const Texture2D wallside = LoadTexture("resources/objects/wallside.png");
const Texture2D wallcorner1 = LoadTexture("resources/objects/wallcorner1.png");
const Texture2D wallcorner2 = LoadTexture("resources/objects/wallcorner2.png");
const Texture2D wallcorner3 = LoadTexture("resources/objects/wallcorner3.png");
const Texture2D wallcorner4 = LoadTexture("resources/objects/wallcorner4.png");
const Texture2D wallinternal = LoadTexture("resources/objects/wallinternal.png");

const Texture2D rock = LoadTexture("resources/objects/rock.png");
const Texture2D chestclose = LoadTexture("resources/objects/chest-close.png");
const Texture2D chestopen = LoadTexture("resources/objects/chest-open.png");
const Texture2D tree = LoadTexture("resources/objects/tree.png");
const Texture2D hearthblock = LoadTexture("resources/objects/hearthblock.png");
const Texture2D emeraldframer = LoadTexture("resources/objects/emeraldframer.png");

const Texture2D snakey = LoadTexture("resources/characters/snakey.png");
const Texture2D lolo = LoadTexture("resources/characters/lolo.png");

    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);
        DrawTextureRec(floorPattern, floorRec, (Vector2){112,16}, RAYWHITE);
        for(int i = 0; i < 14; i++){
            for(int j = 0; j < 13; j++){
                if(map[i][j] == 'W')
                    DrawTextureEx(wallinternal, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == 'D')
                    DrawTextureEx(door, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == 'R')
                    //DrawTexture(Texture2D texture, int posX, int posY, Color tint);
                    DrawTextureEx(rock, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                    //DrawRectangleRounded((Rectangle){144+j*32,48+i*32,32,32}, 0.4, 0, ORANGE);
                else if(map[i][j] == 'T')
                    DrawTextureEx(tree, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == 'H')
                    DrawTextureEx(hearthblock, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == 'S')
                    DrawTextureEx(snakey, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == 'K')
                    DrawTextureEx(chestclose, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == 'L')
                    DrawTextureEx(lolo, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == '-')
                    DrawTextureEx(wall, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == '|')
                    DrawTextureEx(wallside, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == '1')
                    DrawTextureEx(wallcorner1, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == '2')
                    DrawTextureEx(wallcorner2, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == '3')
                    DrawTextureEx(wallcorner3, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                else if(map[i][j] == '4')
                    DrawTextureEx(wallcorner4, (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
            }
        }

    EndDrawing();

    return window;
}

/*
typedef struct GRAVACAO {
    char id;
    char totalpts;
    char ultimafase;
    char vidas;
    char nomejogador[8];
} Gravacao, * pGravacao;
*/
