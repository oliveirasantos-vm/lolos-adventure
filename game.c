int game(int window, Font font){
    const char *back = "VOLTAR";
    Vector2 backPosition = {SCREEN_WIDTH/2.0f - MeasureTextEx(font, back, 20, 12).x/2, SCREEN_HEIGTH/2.0f - 10 + 150.0f};
    Rectangle backBox = {backPosition.x, backPosition.y, MeasureTextEx(font, back, 20, 12).x, 20};

    BeginDrawing();
    ClearBackground(BLACK);
    SetMouseCursor(1);
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
