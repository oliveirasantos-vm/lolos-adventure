#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

typedef struct GRAVACAO {
    char id;
    char totalpts;
    char ultimafase;
    char vidas;
    char nomejogador[8];
} Gravacao, * pGravacao;

int main(){
    const int screenWidth = 640;
    const int screenHeight = 480;

    int window = 0;

    InitWindow(screenWidth, screenHeight, "Lolo's Adventure");

    Font pixantiqua = LoadFont("resources/fonts/pixantiqua.png");

    const char *titulo[2] = {"AVENTURAS DE","LOLO"};

    Vector2 titlePositions[2] = {{screenWidth/2.0f - MeasureTextEx(pixantiqua, titulo[0], 30, 12).x/2,
                                  screenHeight/2.0f - 10 - 180.0f},
                                 {screenWidth/2.0f - MeasureTextEx(pixantiqua, titulo[1], 100, 36).x/2,
                                  screenHeight/2.0f - 30 - 130.0f}};

    const char *opcoes[4]  = {"NOVO JOGO","CARREGAR JOGO","CREDITOS","SAIR"};

    Vector2 opcoesPositions[4] = {{screenWidth/2.0f - MeasureTextEx(pixantiqua, opcoes[0], 20, 12).x/2,
                                   screenHeight/2.0f - 10 + 60.0f},
                                  {screenWidth/2.0f - MeasureTextEx(pixantiqua, opcoes[1], 20, 12).x/2,
                                   screenHeight/2.0f - 10 + 90.0f},
                                  {screenWidth/2.0f - MeasureTextEx(pixantiqua, opcoes[2], 20, 12).x/2,
                                   screenHeight/2.0f - 10 + 120.0f},
                                  {screenWidth/2.0f - MeasureTextEx(pixantiqua, opcoes[3], 20, 12).x/2,
                                   screenHeight/2.0f - 10 + 150.0f}};

    Rectangle opcoesBox[4] = {{opcoesPositions[0].x, opcoesPositions[0].y, MeasureTextEx(pixantiqua, opcoes[0], 20, 12).x,20},
                              {opcoesPositions[1].x, opcoesPositions[1].y, MeasureTextEx(pixantiqua, opcoes[1], 20, 12).x,20},
                              {opcoesPositions[2].x, opcoesPositions[2].y, MeasureTextEx(pixantiqua, opcoes[2], 20, 12).x,20},
                              {opcoesPositions[3].x, opcoesPositions[3].y, MeasureTextEx(pixantiqua, opcoes[3], 20, 12).x,20}};

    const char *creditos = "MATHEUS BECK\n\nVITOR SANTOS\n\n";

    Vector2 creditosPositions = {screenWidth/2.0f - MeasureTextEx(pixantiqua, creditos, 25, 12).x/2, screenHeight/2.0f - 10 - 80.0f};

    const char *back = "VOLTAR";

    Vector2 backPosition = {screenWidth/2.0f - MeasureTextEx(pixantiqua, back, 20, 12).x/2, screenHeight/2.0f - 10 + 150.0f};

    Rectangle backBox = {backPosition.x, backPosition.y, MeasureTextEx(pixantiqua, back, 20, 12).x, 20};


    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        switch(window){
            case 0:
                ClearBackground(BLACK);
                SetMouseCursor(1);
                DrawTextEx(pixantiqua, titulo[0], titlePositions[0], 30, 12, WHITE);
                DrawTextEx(pixantiqua, titulo[1], titlePositions[1], 100, 36, WHITE);
                DrawTextEx(pixantiqua, opcoes[0], opcoesPositions[0], 20, 12, WHITE);
                DrawTextEx(pixantiqua, opcoes[1], opcoesPositions[1], 20, 12, WHITE);
                DrawTextEx(pixantiqua, opcoes[2], opcoesPositions[2], 20, 12, WHITE);
                DrawTextEx(pixantiqua, opcoes[3], opcoesPositions[3], 20, 12, WHITE);
                for(int i = 0; i < 4; i++){
                    if(CheckCollisionPointRec(GetMousePosition(),opcoesBox[i])){
                        DrawTextEx(pixantiqua, opcoes[i], opcoesPositions[i], 20, 12, GRAY);
                        SetMouseCursor(4);
                        if(IsMouseButtonPressed(0)){
                            switch(i){
                                case 0:
                                    break;
                                case 1:
                                    window = 2;
                                    break;
                                case 2:
                                    window = 1;
                                    break;
                                case 3:
                                    CloseWindow();
                                    break;
                            }
                        }
                    }
                }
                break;
            case 1:
                ClearBackground(BLACK);
                SetMouseCursor(1);
                DrawTextEx(pixantiqua, creditos, creditosPositions, 25, 12, WHITE);
                DrawTextEx(pixantiqua, back, backPosition, 20, 12, WHITE);
                if(CheckCollisionPointRec(GetMousePosition(), backBox)){
                    DrawTextEx(pixantiqua, back, backPosition, 20, 12, GRAY);
                    SetMouseCursor(4);
                    if(IsMouseButtonPressed(0)){
                        window = 0;
                    }
                }
                break;
            case 2:
                ClearBackground(BLACK);
                SetMouseCursor(1);
                DrawTextEx(pixantiqua, back, backPosition, 20, 12, WHITE);
                if(CheckCollisionPointRec(GetMousePosition(), backBox)){
                    DrawTextEx(pixantiqua, back, backPosition, 20, 12, GRAY);
                    SetMouseCursor(4);
                    if(IsMouseButtonPressed(0)){
                        window = 0;
                    }
                }
                break;
            default:
                CloseWindow();
                break;
        }
        EndDrawing();
    }
    return 0;
}
