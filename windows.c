#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>


#define MAX_INPUT_CHARS 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGTH 480

int menu(int window, Font font){
    const char *titulo[2] = {"AVENTURAS DE","LOLO"};
    Vector2 titlePositions[2] = {{SCREEN_WIDTH/2.0f - MeasureTextEx(font, titulo[0], 30, 12).x/2,
                                  SCREEN_HEIGTH/2.0f - 10 - 180.0f},
                                 {SCREEN_WIDTH/2.0f - MeasureTextEx(font, titulo[1], 100, 36).x/2,
                                  SCREEN_HEIGTH/2.0f - 30 - 130.0f}};

    const char *opcoes[4]  = {"NOVO JOGO","CARREGAR JOGO","CREDITOS","SAIR"};
    Vector2 opcoesPositions[4] = {{SCREEN_WIDTH/2.0f - MeasureTextEx(font, opcoes[0], 20, 12).x/2,
                                   SCREEN_HEIGTH/2.0f - 10 + 60.0f},
                                  {SCREEN_WIDTH/2.0f - MeasureTextEx(font, opcoes[1], 20, 12).x/2,
                                   SCREEN_HEIGTH/2.0f - 10 + 90.0f},
                                  {SCREEN_WIDTH/2.0f - MeasureTextEx(font, opcoes[2], 20, 12).x/2,
                                   SCREEN_HEIGTH/2.0f - 10 + 120.0f},
                                  {SCREEN_WIDTH/2.0f - MeasureTextEx(font, opcoes[3], 20, 12).x/2,
                                   SCREEN_HEIGTH/2.0f - 10 + 150.0f}};

    Rectangle opcoesBox[4] = {{opcoesPositions[0].x, opcoesPositions[0].y, MeasureTextEx(font, opcoes[0], 20, 12).x,20},
                              {opcoesPositions[1].x, opcoesPositions[1].y, MeasureTextEx(font, opcoes[1], 20, 12).x,20},
                              {opcoesPositions[2].x, opcoesPositions[2].y, MeasureTextEx(font, opcoes[2], 20, 12).x,20},
                              {opcoesPositions[3].x, opcoesPositions[3].y, MeasureTextEx(font, opcoes[3], 20, 12).x,20}};

    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);
        DrawTextEx(font, titulo[0], titlePositions[0], 30, 12, WHITE);
        DrawTextEx(font, titulo[1], titlePositions[1], 100, 36, WHITE);
        DrawTextEx(font, opcoes[0], opcoesPositions[0], 20, 12, WHITE);
        DrawTextEx(font, opcoes[1], opcoesPositions[1], 20, 12, WHITE);
        DrawTextEx(font, opcoes[2], opcoesPositions[2], 20, 12, WHITE);
        DrawTextEx(font, opcoes[3], opcoesPositions[3], 20, 12, WHITE);
        for(int i = 0; i < 4; i++){
            if(CheckCollisionPointRec(GetMousePosition(),opcoesBox[i])){
                DrawTextEx(font, opcoes[i], opcoesPositions[i], 20, 12, GRAY);
                SetMouseCursor(4);
                if(IsMouseButtonPressed(0)){
                    switch(i){
                        case 0:
                            window = 3;
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
    EndDrawing();
    return window;
}



int credits(int window, Font font){
    const char *creditos = "MATHEUS BECK\n\nVITOR SANTOS\n\n";
    Vector2 creditosPositions = {SCREEN_WIDTH/2.0f - MeasureTextEx(font, creditos, 25, 12).x/2, SCREEN_HEIGTH/2.0f - 10 - 80.0f};
    const char *back = "VOLTAR";
    Vector2 backPosition = {SCREEN_WIDTH/2.0f - MeasureTextEx(font, back, 20, 12).x/2, SCREEN_HEIGTH/2.0f - 10 + 150.0f};
    Rectangle backBox = {backPosition.x, backPosition.y, MeasureTextEx(font, back, 20, 12).x, 20};
    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);
        DrawTextEx(font, creditos, creditosPositions, 25, 12, WHITE);
        DrawTextEx(font, back, backPosition, 20, 12, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), backBox)){
            DrawTextEx(font, back, backPosition, 20, 12, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 0;
            }
        }
    EndDrawing();

    return window;
}



int loadGame(int window, Font font){
    const char *back = "VOLTAR";
    Vector2 backPosition = {70, 380};
    Rectangle backBox = {backPosition.x, backPosition.y, MeasureTextEx(font, back, 20, 12).x, 20};

    const char *remove = "REMOVER";
    Vector2 removePosition = {410, 380};
    Rectangle removeBox = {removePosition.x, removePosition.y, MeasureTextEx(font, remove, 20, 12).x, 20};

    Rectangle newGameBox = {70, 50, 500, 50};

    Rectangle loadBox = {70, 120, 500, 80};
    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);
        DrawRectangleRoundedLines(newGameBox, 0.2, 0, 3, WHITE);
        DrawTextEx(font, "NEW GAME", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "NEW GAME", 20, 12).x/2, 65}, 20, 12, WHITE);


        if(CheckCollisionPointRec(GetMousePosition(), newGameBox)){
            DrawRectangleRoundedLines(newGameBox, 0.2, 0, 3, GRAY);
            DrawTextEx(font, "NEW GAME", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "NEW GAME", 20, 12).x/2, 65}, 20, 12, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 3;
            }
        }

        DrawRectangleRoundedLines(loadBox, 0.2, 0, 3, WHITE);
        DrawTextEx(font, "PLAYER", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "PLAYER", 20, 12).x/2, 130}, 20, 12, WHITE);
        DrawTextEx(font, "PONTOS:0", (Vector2){80, 170}, 14, 12, WHITE);
        DrawTextEx(font, "FASE:0", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "FASE:0", 14, 12).x/2, 170}, 14, 12, WHITE);
        DrawTextEx(font, "VIDAS:0", (Vector2){500 - MeasureTextEx(font, "VIDAS:0", 14, 12).x/2, 170}, 14, 12, WHITE);


        if(CheckCollisionPointRec(GetMousePosition(), loadBox)){
            DrawRectangleRoundedLines(loadBox, 0.2, 0, 3, GRAY);
            DrawTextEx(font, "PLAYER", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "PLAYER", 20, 12).x/2, 130}, 20, 12, GRAY);
            DrawTextEx(font, "PONTOS:0", (Vector2){80, 170}, 14, 12, GRAY);
            DrawTextEx(font, "FASE:0", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "FASE:0", 14, 12).x/2, 170}, 14, 12, GRAY);
            DrawTextEx(font, "VIDAS:0", (Vector2){500 - MeasureTextEx(font, "VIDAS:0", 14, 12).x/2, 170}, 14, 12, GRAY);
            SetMouseCursor(4);
        }

        DrawTextEx(font, back, backPosition, 20, 12, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), backBox)){
            DrawTextEx(font, back, backPosition, 20, 12, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 0;
            }
        }

        DrawTextEx(font, remove, removePosition, 20, 12, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), removeBox)){
            DrawTextEx(font, remove, removePosition, 20, 12, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 5;
            }
        }
    EndDrawing();
    return window;
}



int removeSave(int window, Font font){
    const char *cancel = "CANCELAR";
    Vector2 cancelPosition = {SCREEN_WIDTH/2.0f - MeasureTextEx(font, cancel, 20, 12).x/2, SCREEN_HEIGTH/2.0f - 10 + 150.0f};
    Rectangle cancelBox = {cancelPosition.x, cancelPosition.y, MeasureTextEx(font, cancel, 20, 12).x, 20};

    Rectangle loadBox = {70, 50, 500, 80};
    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);

        DrawRectangleRoundedLines(loadBox, 0.2, 0, 3, WHITE);
        DrawTextEx(font, "PLAYER", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "PLAYER", 20, 12).x/2, 60}, 20, 12, WHITE);
        DrawTextEx(font, "PONTOS:0", (Vector2){80, 100}, 14, 12, WHITE);
        DrawTextEx(font, "FASE:0", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "FASE:0", 14, 12).x/2, 100}, 14, 12, WHITE);
        DrawTextEx(font, "VIDAS:0", (Vector2){500 - MeasureTextEx(font, "VIDAS:0", 14, 12).x/2, 100}, 14, 12, WHITE);


        if(CheckCollisionPointRec(GetMousePosition(), loadBox)){
            DrawRectangleRoundedLines(loadBox, 0.2, 0, 3, RED);
            DrawTextEx(font, "PLAYER", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "PLAYER", 20, 12).x/2, 60}, 20, 12, RED);
            DrawTextEx(font, "PONTOS:0", (Vector2){80, 100}, 14, 12, RED);
            DrawTextEx(font, "FASE:0", (Vector2){SCREEN_WIDTH/2.0f - MeasureTextEx(font, "FASE:0", 14, 12).x/2,100} , 14, 12, RED);
            DrawTextEx(font, "VIDAS:0", (Vector2){500 - MeasureTextEx(font, "VIDAS:0", 14, 12).x/2, 100}, 14, 12, RED);
            SetMouseCursor(4);
        }

        DrawTextEx(font, cancel, cancelPosition, 20, 12, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), cancelBox)){
            DrawTextEx(font, cancel, cancelPosition, 20, 12, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 2;
            }
        }
    EndDrawing();
    return window;
}



Rectangle textBox = { SCREEN_WIDTH/2 - 150, 180, 300, 50};
char name[MAX_INPUT_CHARS + 1] = "\0";
int letterCount = 0, framesCounter = 0;
bool mouseOnText = false;

int player(int window, Font font){
    const char *play = "JOGAR";
    Vector2 playPosition = {SCREEN_WIDTH/2.0f - MeasureTextEx(font, play, 20, 12).x/2, SCREEN_HEIGTH/2.0f - 10 + 150.0f};
    Rectangle playBox = {playPosition.x, playPosition.y, MeasureTextEx(font, play, 20, 12).x, 20};

    const char *labelUser = "PLAYER:";
    Vector2 labelUserPosition = {SCREEN_WIDTH/2.0f - MeasureTextEx(font, labelUser, 25, 12).x/2, SCREEN_HEIGTH/2.0f - 10 - 100.0f};



    int key = GetCharPressed();

    if(CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
    else mouseOnText = false;

    while (key > 0)
    {
        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)){
            name[letterCount] = (char)key;
            letterCount++;
        }

        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        letterCount--;
        if (letterCount < 0) letterCount = 0;
        name[letterCount] = '\0';
    }

    framesCounter++;


    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);

        DrawTextEx(font, labelUser, labelUserPosition, 25, 12, WHITE);

        DrawRectangleRec(textBox, LIGHTGRAY);
        if (mouseOnText) DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, WHITE);
        else DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, BLACK);
        DrawTextEx(font, name, (Vector2){textBox.x + 10, textBox.y + 10}, 30, 12, BLACK);
        if (letterCount < MAX_INPUT_CHARS){
            if (((framesCounter/20)%2) == 0) DrawTextEx(font, "_", (Vector2){textBox.x + 16 + MeasureTextEx(font, name, 30, 12).x, textBox.y + 5}, 40, 12, BLACK);
        }

        DrawTextEx(font, play, playPosition, 20, 12, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), playBox)){
            DrawTextEx(font, play, playPosition, 20, 12, GRAY);
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0)){
                window = 4;
            }
        }

    EndDrawing();
    return window;
}
