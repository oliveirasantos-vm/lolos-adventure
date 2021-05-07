#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

#define MAX_INPUT_CHARS 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGTH 480

void itoa(int n, char s[]);

void reverse(char s[]);


char map[10][14][13] = {{{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
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
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','D','W','W','|'},
                         {'|','.','.','.','S','.','R','R','R','.','.','.','|'},
                         {'|','.','H','.','.','.','R','R','R','.','H','.','|'},
                         {'|','.','.','.','.','.','.','T','T','.','.','.','|'},
                         {'|','O','O','O','O','E','O','O','O','O','E','O','|'},
                         {'|','O','O','O','O','E','O','O','O','O','E','O','|'},
                         {'|','K','.','T','T','.','.','.','.','.','.','O','|'},
                         {'|','.','.','T','T','.','.','.','T','T','.','O','|'},
                         {'|','.','.','.','.','.','R','R','T','T','.','O','|'},
                         {'|','S','.','.','.','.','R','R','H','.','.','O','|'},
                         {'|','.','.','.','.','.','.','.','K','.','.','.','|'},
                         {'|','H','.','.','.','L','.','O','O','O','O','O','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','D','W','W','W','W','W','|'},
                         {'|','.','.','.','B','.','.','.','.','.','.','.','|'},
                         {'|','.','R','R','R','R','R','R','C','.','.','.','|'},
                         {'|','.','.','C','.','.','.','.','.','.','R','.','|'},
                         {'|','.','.','.','.','.','.','R','R','R','R','.','|'},
                         {'|','H','O','O','O','O','.','R','H','.','C','.','|'},
                         {'|','E','O','O','O','K','.','R','H','B','C','.','|'},
                         {'|','H','O','O','O','O','.','R','H','.','C','.','|'},
                         {'|','.','.','.','.','.','.','R','R','R','R','.','|'},
                         {'|','.','.','.','C','.','.','.','.','.','R','.','|'},
                         {'|','.','R','R','R','R','R','R','C','.','.','.','|'},
                         {'|','.','.','.','B','.','L','.','.','.','.','.','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','W','W','W','|'},
                         {'|','R','R','R','R','.','.','.','C','.','.','R','|'},
                         {'|','R','H','.','C','.','.','.','R','H','R','R','|'},
                         {'|','R','R','.','R','.','.','.','R','R','R','R','|'},
                         {'|','.','.','.','.','.','.','.','.','R','R','R','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','.','.','.','K','.','.','.','.','.','|'},
                         {'|','.','.','.','.','F','.','F','.','.','.','.','|'},
                         {'|','R','C','R','.','.','.','.','.','.','.','.','|'},
                         {'|','R','.','R','R','.','.','.','R','R','C','R','|'},
                         {'|','.','.','.','C','.','E','.','R','H','.','R','|'},
                         {'|','R','H','R','R','.','L','.','R','R','.','R','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','D','W','W','|'},
                         {'|','R','.','.','.','H','K','H','.','.','.','R','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','T','.','.','.','.','.','T','.','.','|'},
                         {'|','H','.','.','.','.','A','.','.','.','.','H','|'},
                         {'|','H','.','R','.','.','.','.','.','R','.','H','|'},
                         {'|','.','.','C','.','.','.','.','.','C','.','.','|'},
                         {'|','.','T','T','.','.','.','.','.','T','T','.','|'},
                         {'|','.','T','T','.','.','.','.','.','T','T','.','|'},
                         {'|','.','.','R','.','.','.','.','.','R','.','.','|'},
                         {'|','.','.','R','C','.','.','.','C','R','.','.','|'},
                         {'|','T','.','.','.','.','L','.','.','.','.','T','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','D','W','W','|'},
                         {'|','R','R','R','R','R','R','R','R','.','R','R','|'},
                         {'|','R','R','.','H','T','K','T','H','.','R','R','|'},
                         {'|','T','.','.','.','.','.','.','.','.','.','T','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','P','.','.','H','.','.','P','.','.','|'},
                         {'|','.','.','.','C','.','.','.','C','.','.','.','|'},
                         {'|','.','.','T','.','C','.','C','.','T','.','.','|'},
                         {'|','H','.','.','.','.','.','.','.','.','.','H','|'},
                         {'|','T','H','.','.','.','.','.','.','.','H','T','|'},
                         {'|','R','R','.','.','.','.','.','.','.','R','R','|'},
                         {'|','.','.','.','R','.','.','L','R','R','R','R','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','W','D','W','|'},
                         {'|','O','O','O','O','O','O','O','O','O','E','O','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','H','R','.','.','.','.','.','R','H','.','|'},
                         {'|','.','R','.','.','.','.','.','.','R','.','.','|'},
                         {'|','.','R','H','.','.','.','M','.','H','R','.','|'},
                         {'|','.','R','R','.','.','.','.','.','R','R','.','|'},
                         {'|','.','H','R','.','T','.','T','.','R','R','.','|'},
                         {'|','.','.','.','.','R','R','R','.','.','.','.','|'},
                         {'|','.','.','T','.','C','K','C','.','T','.','.','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','.','.','.','L','.','.','.','.','.','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','D','W','W','W','W','W','|'},
                         {'|','.','F','.','.','.','.','.','.','.','.','T','|'},
                         {'|','.','R','.','.','R','.','H','R','.','.','.','|'},
                         {'|','.','T','.','R','R','R','R','R','.','.','.','|'},
                         {'|','.','H','.','.','R','H','R','R','H','.','H','|'},
                         {'|','.','T','.','.','R','R','R','T','T','.','T','|'},
                         {'|','.','.','.','.','K','R','H','T','.','.','.','|'},
                         {'|','.','.','T','.','.','.','S','R','T','.','T','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','H','|'},
                         {'|','L','.','.','.','.','.','.','.','.','.','R','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','.','T','H','T','R','H','R','T','.','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','W','W','W','|'},
                         {'|','R','R','R','T','A','T','R','R','.','.','.','|'},
                         {'|','B','.','H','T','B','T','H','.','.','.','.','|'},
                         {'|','R','.','.','.','.','.','.','.','T','.','.','|'},
                         {'|','K','.','E','.','.','.','.','.','.','.','L','|'},
                         {'|','R','.','.','.','S','.','.','.','.','.','.','|'},
                         {'|','B','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','V','V','V','V','V','R','R','R','R','X','R','|'},
                         {'|','V','V','V','V','V','R','.','.','C','.','T','|'},
                         {'|','.','.','A','V','V','R','.','.','C','.','T','|'},
                         {'|','.','.','.','V','V','R','H','.','C','.','H','|'},
                         {'|','.','.','.','V','V','R','.','.','C','T','T','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}}};

int initialPositions[10][2] = {{1,6},{5,12},{6,12},{6,12},{6,12},{7,12},{6,12},{1,10},{11,5}};

int k = 0, frames = 0, lives = 5, guns = 0, points = 0;
char clives[2], cguns[2], cpoints[2];

void move(int vertical, int horizontal, int k){
    int stop = 1;
    if(frames%10 == 0){
        for(int i = 0; i < 14; i++){
            if(stop){
                for(int j = 0; j < 13; j++){
                    if(map[k][i][j] == 'L'  && map[k][i+vertical][j+horizontal] != 'W' && map[k][i+vertical][j+horizontal] != '|' && map[k][i+vertical][j+horizontal] != '-' && map[k][i+vertical][j+horizontal] != 'R' && map[k][i+vertical][j+horizontal] != 'T'){
                        if(map[k][i+vertical][j+horizontal] == 'H'){
                            guns += 2;
                        }
                        if(map[k][i+vertical][j+horizontal] == 'S'){
                            lives --;
                            map[k][i][j] = '.';
                            map[k][initialPositions[k][1]][initialPositions[k][0]] = 'L';
                            break;
                            stop = 0;
                        }
                        map[k][i][j] = '.';
                        map[k][i+vertical][j+horizontal] = 'L';
                        stop = 0;

                        break;
                    }
                }
            }else break;
        }
    }
}

int game(int window, Font font, Texture2D *images){
    frames++;
    int keyPressed = 0;

    itoa(lives, clives);
    itoa(guns, cguns);
    itoa(points, cpoints);

    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);

        if(!lives)
            window = 6;

        if(IsKeyDown(KEY_W)){
            keyPressed++;
            if(keyPressed == 1)
                move(-1, 0, k);
        }

        if(IsKeyDown(KEY_S)){
            keyPressed++;
            if(keyPressed == 1)
                move(1, 0, k);
        }

        if(IsKeyDown(KEY_D)){
            keyPressed++;
            if(keyPressed == 1)
                move(0, 1, k);
        }

        if(IsKeyDown(KEY_A)){
            keyPressed++;
            if(keyPressed == 1)
                move(0, -1, k);
        }

        DrawTextureEx(images[21], (Vector2){530,16}, 0, 0.13, RAYWHITE);
        if(CheckCollisionPointRec(GetMousePosition(), (Rectangle){530,16,32,32})){
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 0;
            }
        }

        DrawTextureEx(images[20], (Vector2){530,64}, 0, 0.13, RAYWHITE);
        if(CheckCollisionPointRec(GetMousePosition(), (Rectangle){530,64,32,32})){
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                //save();
            }
        }


        DrawTextureEx(images[8], (Vector2){530,112}, 0, 0.13, RAYWHITE);
        DrawTextEx(font, clives, (Vector2){538,144}, 28, 4, WHITE);


        DrawTextureEx(images[16], (Vector2){530,192}, 0, 0.13, RAYWHITE);
        DrawTextEx(font, cguns, (Vector2){538,224}, 28, 4, WHITE);

        DrawTextureEx(images[19], (Vector2){530,240}, 0, 0.13, RAYWHITE);
        DrawTextEx(font, cpoints, (Vector2){538,272}, 28, 4, WHITE);

        DrawTextureEx(images[17], (Vector2){530,320}, 0, 0.13, RAYWHITE);

        for(int i = 0; i < 3; i++)
            DrawTextureEx(images[18], (Vector2){530,352+i*32}, 0, 0.13, RAYWHITE);


        //chão
        DrawTextureRec(images[0], (Rectangle){112, 16, 416, 448}, (Vector2){112,16}, RAYWHITE);

        //mapa
        for(int i = 0; i < 14; i++){
            for(int j = 0; j < 13; j++){
                switch(map[k][i][j]){
                    case 'W':
                        DrawTextureEx(images[1], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'D':
                        DrawTextureEx(images[2], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'R':
                        DrawTextureEx(images[3], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'T':
                        DrawTextureEx(images[4], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'H':
                        DrawTextureEx(images[5], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'S':
                        DrawTextureEx(images[6], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'K':
                        DrawTextureEx(images[7], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'L':
                        DrawTextureEx(images[8], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '-':
                        DrawTextureEx(images[9], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '|':
                        DrawTextureEx(images[10], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '1':
                        DrawTextureEx(images[11], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '2':
                        DrawTextureEx(images[12], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '3':
                        DrawTextureEx(images[13], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '4':
                        DrawTextureEx(images[14], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'O':
                        DrawTextureEx(images[15], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                }
            }
        }


        //}
    EndDrawing();
    return window;
}

void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}

void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

int gameover(int window, Font font){
    lives = 5;
    const char *menu = "RETORNAR AO MENU";
    Vector2 menuPosition = {SCREEN_WIDTH/2 - MeasureTextEx(font, menu, 20, 5).x/2, SCREEN_HEIGTH/2 - 10 + 150};
    Rectangle menuBox = {menuPosition.x, menuPosition.y, MeasureTextEx(font, menu, 20, 5).x, 20};

    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);

        DrawTextEx(font,
                   "GAME\nOVER",
                   (Vector2){SCREEN_WIDTH/2 -  MeasureTextEx(font, "GAME\nOVER", 80, 12).x/2,
                             SCREEN_HEIGTH/2  -  MeasureTextEx(font, "GAME\nOVER", 80, 12).y/2 - 50},
                   80,
                   12,
                   WHITE);

        DrawTextEx(font, menu, menuPosition, 20, 5, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), menuBox)){
            DrawTextEx(font, menu, menuPosition, 20, 5, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 0;
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
