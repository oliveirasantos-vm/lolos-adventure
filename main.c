#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

#define MAX_FONTS   8

int main(){
    const int WindowWidth = 640;
    const int WindowHeight = 480;

    InitWindow(WindowWidth, WindowHeight, "Lolo's Adventure");

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    return 0;
}
