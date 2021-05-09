#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_CHARS 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGTH 480

void itoa(int n, char s[]);

void reverse(char s[]);

// W -> internal wall
// | -> Vertical wall
// - -> Horizontal wall
// 1, 2, 3, 4 -> Corner wall
// D -> Closed door
// d -> Open door
// L -> Lolo
// :, ; -> Lolo on chest
//~@, }, ] -> lolo on anything
// R -> Rock
// T -> Tree
// S -> Snakey (monster)
// Z -> Dragon (monster)
// B -> Skull (monster)
// F -> Rocky (monster)
// A -> Alma (monster)
// W -> Bixo (monster)
// J -> cheeper (monster)
// s, z, b, f, a, w, j -> shot (monster)
// V -> Grass
// K -> Chester
// k -> Open chester
// E -> Empty chester
// O -> Water
// H -> Hearth block
// #, % - > Ladder
// U - > Emerald Block


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
                         {'|','.','.','.','Z','.','R','R','R','.','.','.','|'},
                         {'|','.','H','.','.','.','R','R','R','.','H','.','|'},
                         {'|','.','.','.','.','.','.','T','T','.','.','.','|'},
                         {'|','O','O','O','O','#','O','O','O','O','#','O','|'},
                         {'|','O','O','O','O','#','O','O','O','O','#','O','|'},
                         {'|','K','.','T','T','.','.','.','.','.','.','O','|'},
                         {'|','.','.','T','T','.','.','.','T','T','.','O','|'},
                         {'|','.','.','.','.','.','R','R','T','T','.','O','|'},
                         {'|','Z','.','.','.','.','R','R','H','.','.','O','|'},
                         {'|','.','.','.','.','.','.','.','U','.','.','O','|'},
                         {'|','H','.','.','.','L','.','O','O','O','O','O','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','D','W','W','W','W','W','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','T','T','T','T','.','O','O','O','.','|'},
                         {'|','.','O','T','T','T','T','H','O','O','O','.','|'},
                         {'|','.','O','O','O','O','O','O','O','O','O','.','|'},
                         {'|','.','O','K','T','.','S','.','T','.','.','.','|'},
                         {'|','.','%','.','R','.','R','.','T','.','.','.','|'},
                         {'|','.','O','.','R','H','R','H','.','.','.','.','|'},
                         {'|','.','O','.','R','.','R','T','O','O','O','.','|'},
                         {'|','J','O','.','T','.','.','L','O','O','O','.','|'},
                         {'|','.','O','#','O','O','O','O','O','O','O','H','|'},
                         {'|','.','.','.','.','.','.','.','H','.','.','T','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','D','W','W','W','W','W','|'},
                         {'|','.','.','.','B','.','.','.','.','.','.','.','|'},
                         {'|','.','R','R','R','R','R','R','U','.','.','.','|'},
                         {'|','.','.','U','.','.','.','.','.','.','R','.','|'},
                         {'|','.','.','.','.','.','.','R','R','R','R','.','|'},
                         {'|','H','O','O','O','O','.','R','H','.','U','.','|'},
                         {'|','#','O','O','O','K','.','R','H','B','U','.','|'},
                         {'|','H','O','O','O','O','.','R','H','.','U','.','|'},
                         {'|','.','.','.','.','.','.','R','R','R','R','.','|'},
                         {'|','.','.','U','.','.','.','.','.','.','R','.','|'},
                         {'|','.','R','R','R','R','R','R','U','.','.','.','|'},
                         {'|','.','.','.','B','.','L','.','.','.','.','.','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','D','W','W','W','W','W','|'},
                         {'|','R','R','R','R','.','.','.','U','.','.','R','|'},
                         {'|','R','H','.','U','.','.','.','R','H','R','R','|'},
                         {'|','R','R','.','R','.','.','.','R','R','R','R','|'},
                         {'|','.','.','.','.','.','.','.','.','R','R','R','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','.','.','F','K','F','.','.','.','.','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','R','U','R','.','.','.','.','.','.','.','.','|'},
                         {'|','R','.','R','R','.','.','.','R','R','U','R','|'},
                         {'|','.','.','.','U','.','.','.','R','H','.','R','|'},
                         {'|','R','H','R','R','.','L','.','R','R','.','R','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','D','W','W','|'},
                         {'|','R','.','.','.','H','K','H','.','.','.','R','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','T','.','.','.','.','.','T','.','.','|'},
                         {'|','H','.','.','.','.','A','.','.','.','.','H','|'},
                         {'|','H','.','R','.','.','.','.','.','R','.','H','|'},
                         {'|','.','.','U','.','.','.','.','.','U','.','.','|'},
                         {'|','.','T','T','.','.','.','.','.','T','T','.','|'},
                         {'|','.','T','T','.','.','.','.','.','T','T','.','|'},
                         {'|','.','.','R','.','.','.','.','.','R','.','.','|'},
                         {'|','.','.','R','U','.','.','.','U','R','.','.','|'},
                         {'|','T','.','.','.','.','L','.','.','.','.','T','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','D','W','W','|'},
                         {'|','R','R','R','R','R','R','R','R','.','R','R','|'},
                         {'|','R','R','.','H','T','K','T','H','.','R','R','|'},
                         {'|','T','.','.','.','.','.','.','.','.','.','T','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','M','.','.','H','.','.','M','.','.','|'},
                         {'|','.','.','.','U','.','.','.','U','.','.','.','|'},
                         {'|','.','.','T','.','U','.','U','.','T','.','.','|'},
                         {'|','H','.','.','.','.','.','.','.','.','.','H','|'},
                         {'|','T','.','H','.','.','.','.','.','H','.','T','|'},
                         {'|','R','R','.','.','.','.','.','.','.','R','R','|'},
                         {'|','.','.','.','R','.','L','.','R','R','R','R','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','W','W','W','W','D','W','|'},
                         {'|','O','O','O','O','O','O','O','O','O','#','O','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','H','R','.','.','.','.','.','R','H','.','|'},
                         {'|','.','R','.','.','.','.','.','.','.','R','.','|'},
                         {'|','.','R','H','.','.','P','.','.','H','R','.','|'},
                         {'|','.','R','R','.','.','.','.','.','R','R','.','|'},
                         {'|','.','H','R','.','T','K','T','.','R','H','.','|'},
                         {'|','.','.','.','.','R','R','R','.','.','.','.','|'},
                         {'|','.','.','T','.','U','.','U','.','T','.','.','|'},
                         {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','.','.','.','.','.','L','.','.','.','.','.','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}},

                        {{'1','-','-','-','-','-','-','-','-','-','-','-','2'},
                         {'|','W','W','W','W','W','D','W','W','W','W','W','|'},
                         {'|','.','F','.','.','.','.','.','.','.','.','T','|'},
                         {'|','.','R','.','.','R','.','H','R','.','.','.','|'},
                         {'|','.','T','.','R','R','.','R','R','.','.','.','|'},
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
                         {'|','K','.','.','.','.','.','.','.','.','.','L','|'},
                         {'|','R','.','.','.','S','.','.','.','.','.','.','|'},
                         {'|','B','.','.','.','.','.','.','.','.','.','.','|'},
                         {'|','V','V','V','V','V','R','R','R','R','^','R','|'},
                         {'|','V','V','V','V','V','R','.','.','U','.','T','|'},
                         {'|','.','.','A','V','V','R','.','.','U','.','T','|'},
                         {'|','.','.','.','V','V','R','H','.','U','.','H','|'},
                         {'|','H','.','.','V','V','R','.','.','U','T','T','|'},
                         {'3','-','-','-','-','-','-','-','-','-','-','-','4'}}};

int initialPositions[10][2] = {{1,6},{5,12},{7,10},{6,12},{6,12},{6,12},{7,12},{6,12},{1,10},{11,5}};

int k = 3, frames = 0, lives = 5, guns = 0, points = 0, v = 0 ,h = 0, heartCounter, vert = 1, horz = 0;
clives[2], cguns[2], cpoints[2];

void openDoor(){
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 13; j++){
            if(map[k][i][j] == 'D'){
                map[k][i][j] = 'd';
            }
        }
    }
}

void nextMap(){
    k++;
    guns = 0;
    points+= 10;
    frames = 0;
    vert = 1;
    horz = 0;
}

void checkLoloMove(int k, int i, int j){
    switch(map[k][i][j]){
        case 'L': //normal
            map[k][i][j] = '.';
            break;
        case ':': //on closed chest
            map[k][i][j] = 'K';
            break;
        case ';': //on opened chest
            map[k][i][j] = 'E';
            break;
        case '}': //on ladder
            map[k][i][j] = '#';
            break;
        case ']': //on side ladder
            map[k][i][j] = '%';
            break;
        case '@': //on grass
            map[k][i][j] = 'V';
            break;
        case '~': //on up arrow
            map[k][i][j] = '^';
            break;
    }
}

void move(int vertical, int horizontal, int k){
    int stop = 1;
    if(frames%10 == 0){
        for(int i = 0; i < 14; i++){
            if(stop){
                for(int j = 0; j < 13; j++){
                    if((map[k][i][j] == 'L' || map[k][i][j] == ':' || map[k][i][j] == ';' || map[k][i][j] == '}' || map[k][i][j] == ']' || map[k][i][j] == '~' || map[k][i][j] == '@') && map[k][i+vertical][j+horizontal] != 'O' && map[k][i+vertical][j+horizontal] != 'D'  && map[k][i+vertical][j+horizontal] != 'W' && map[k][i+vertical][j+horizontal] != '|' && map[k][i+vertical][j+horizontal] != '-' && map[k][i+vertical][j+horizontal] != 'R' && map[k][i+vertical][j+horizontal] != 'T'){
                        switch(map[k][i+vertical][j+horizontal]){
                            case 'H':
                                guns += 2;
                                checkLoloMove(k, i, j);
                                map[k][i+vertical][j+horizontal] = 'L';
                                break;
                            case 'S': case 'Z': case 'B': case 'F': case 'A': case 'W': case 'J': case 'M': case 'P':
                                lives--;
                                checkLoloMove(k, i, j);
                                map[k][initialPositions[k][1]][initialPositions[k][0]] = 'L';
                                break;
                            case 's': case 'z': case 'b': case 'f': case 'a': case 'w': case 'j': case 'm': case 'p':
                                if(map[k][i+vertical*2][j+horizontal*2] != 'D' && map[k][i+vertical*2][j+horizontal*2] != 'W' && map[k][i+vertical*2][j+horizontal*2] != '|' && map[k][i+vertical*2][j+horizontal*2] != '-' && map[k][i+vertical*2][j+horizontal*2] != 'R' && map[k][i+vertical*2][j+horizontal*2] != 'T'){
                                    map[k][i+vertical*2][j+horizontal*2] = map[k][i+vertical][j+horizontal];
                                    checkLoloMove(k, i, j);
                                    map[k][i+vertical][j+horizontal] = 'L';
                                }
                                break;
                            case 'U':
                                if(map[k][i+vertical*2][j+horizontal*2] == '.' || map[k][i+vertical*2][j+horizontal*2] == 'G'){
                                    map[k][i+vertical*2][j+horizontal*2] = 'U';
                                    checkLoloMove(k, i, j);
                                    map[k][i+vertical][j+horizontal] = 'L';
                                }
                                break;
                            case 'K':
                                map[k][i][j] = '.';
                                map[k][i+vertical][j+horizontal] = ':';
                                break;
                            case 'k': case 'E':
                                map[k][i][j] = '.';
                                map[k][i+vertical][j+horizontal] = ';';
                                openDoor();
                                break;
                            case 'V':
                                if (map[k][i][j] == '@') map[k][i][j] = 'V';
                                else map[k][i][j] = '.';
                                map[k][i+vertical][j+horizontal] = '@';
                                break;
                            case '#':
                                if (map[k][i][j] == '}') map[k][i][j] = '#';
                                else map[k][i][j] = '.';
                                map[k][i+vertical][j+horizontal] = '}';
                                break;
                            case '%':
                                if (map[k][i][j] == ']') map[k][i][j] = '%';
                                else map[k][i][j] = '.';
                                map[k][i+vertical][j+horizontal] = ']';
                                break;
                            case '^':
                                if (map[k][i][j] == '~') map[k][i][j] = '^';
                                else map[k][i][j] = '.';
                                map[k][i+vertical][j+horizontal] = '~';
                                break;
                            case 'd':
                                checkLoloMove(k, i, j);
                                map[k][i+vertical][j+horizontal] = 'L';
                                nextMap();
                                break;
                            default:
                                checkLoloMove(k, i, j);
                                map[k][i+vertical][j+horizontal] = 'L';
                                break;
                        }
                        stop = 0;
                        break;
                    }
                }
            } else break;
        }
    }
}

void shot(int vertical, int horizontal, int k){
    int stop = 1;
    for(int i = 0; i < 14; i++){
        if(stop){
            for(int j = 0; j < 13; j++){
                if(map[k][i][j] == 'L' &&
                   (map[k][i+vertical][j+horizontal] == 'S' || map[k][i+vertical][j+horizontal] == 's' ||
                    map[k][i+vertical][j+horizontal] == 'Z' || map[k][i+vertical][j+horizontal] == 'z' ||
                    map[k][i+vertical][j+horizontal] == 'B' || map[k][i+vertical][j+horizontal] == 'b' ||
                    map[k][i+vertical][j+horizontal] == 'F' || map[k][i+vertical][j+horizontal] == 'f' ||
                    map[k][i+vertical][j+horizontal] == 'A' || map[k][i+vertical][j+horizontal] == 'a' ||
                    map[k][i+vertical][j+horizontal] == 'W' || map[k][i+vertical][j+horizontal] == 'w' ||
                    map[k][i+vertical][j+horizontal] == 'J' || map[k][i+vertical][j+horizontal] == 'j' ||
                    map[k][i+vertical][j+horizontal] == 'M' || map[k][i+vertical][j+horizontal] == 'm' ||
                    map[k][i+vertical][j+horizontal] == 'P' || map[k][i+vertical][j+horizontal] == 'p')){
                    if(islower(map[k][i+vertical][j+horizontal])){
                        map[k][i+vertical][j+horizontal] = '.';
                        guns--;
                    } else if(isupper(map[k][i+vertical][j+horizontal])){
                        map[k][i+vertical][j+horizontal] = tolower(map[k][i+vertical][j+horizontal]);
                        guns--;
                    }
                    stop = 0;
                    break;
                }
            }
        } else break;
    }

}

void checkMonster(){
    int stop = 1;
    if(frames % 300 == 0){
        for(int i = 0; i < 14; i++){
            if(stop){
                for(int j = 0; j < 13; j++){
                    if(map[k][i][j] == 's' || map[k][i][j] == 'z' || map[k][i][j] == 'b' || map[k][i][j] == 'f' || map[k][i][j] == 'a' || map[k][i][j] == 'm' || map[k][i][j] == 'p'){
                        map[k][i][j] = toupper(map[k][i][j]);
                        stop = 0;
                        break;
                    }
                }
            } else break;
        }
    }
}

void openChest(){
    int stop = 1;
    for(int i = 0; i < 14; i++){
        if(stop){
            for(int j = 0; j < 13; j++){
                if(map[k][i][j] == 'K'){
                    map[k][i][j] = 'k';
                    stop = 0;
                    break;
                }
            }
        } else break;
    }
}

void howManyHearts(){
    heartCounter = 0;
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 13; j++){
            if(map[k][i][j] == 'H'){
                heartCounter++;
            }
        }
    }
}

void gol(){
    int frames3x = frames * 3;
    if(192 + frames3x == 480) frames = 0;
    Vector2 fireBall[2] = {{192 + frames3x, 352}, {256, 128 + frames3x}};
    Vector2 loloRadius;
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 13; j++){
            if(map[k][i][j] == 'L'){
                loloRadius = (Vector2) {112+j*32+16,16+i*32+16};
            }
        }
    }
    if(map[k][10][1] == 'Z'){
        DrawCircleV(fireBall[0], 16, RED);
        if(CheckCollisionCircles(fireBall[0], 5, loloRadius, 5)){
        //lives--;
            for(int i = 0; i < 14; i++){
                for(int j = 0; j < 13; j++){
                    if(map[k][i][j] == 'L'){
                        checkLoloMove(k, i, j);
                        map[k][initialPositions[k][1]][initialPositions[k][0]] = 'L';
                        break;
                    }
                }
            }
        }
    }
    if(map[k][2][4] == 'Z'){
        DrawCircleV(fireBall[1], 16, RED);
        if(CheckCollisionCircles(fireBall[1], 5, loloRadius, 5)){
            lives--;
            for(int i = 0; i < 14; i++){
                for(int j = 0; j < 13; j++){
                    if(map[k][i][j] == 'L'){
                        checkLoloMove(k, i, j);
                        map[k][initialPositions[k][1]][initialPositions[k][0]] = 'L';
                        break;
                    }
                }
            }
        }
    }
}

void leeper(){
    int stop = 1;
    if(frames%10==0){
        for(int i = 0; i < 14; i++){
            if(stop){
                for(int j = 0; j < 13; j++){
                    if(map[k][i][j] == 'J'){
                        int aux;
                        if(map[k][i+vert][j+horz] == 'L'){
                            lives--;
                            checkLoloMove(k, i, j);
                            map[k][i+vert][j+horz] = '.';
                            map[k][initialPositions[k][1]][initialPositions[k][0]] = 'L';
                        }
                        if(map[k][i+vert][j+horz] == '.'){
                            vert = vert;
                            horz = horz;
                        } else if(map[k][i+horz][j+vert] == '.'){
                            aux = vert;
                            vert = horz;
                            horz = aux;
                        } else if(map[k][i-vert][j-horz] == '.'){
                            vert = -vert;
                            horz = -horz;
                        } else if(map[k][i-horz][j-vert] == '.'){
                            aux = -vert;
                            vert = -horz;
                            horz = aux;
                        }
                        map[k][i][j] = '.';
                        map[k][i+vert][j+horz] = 'J';
                        stop = 0;
                        break;
                    }
                }
            } else break;
        }
    }
}

int lado = -1;

void skull(){
    int stop = 1;
    if(frames%5==0){
        for(int i = 0; i < 14; i++){
            if(stop){
                for(int j = 0; j < 13; j++){
                    if(map[k][i][j] == 'B'){
                        int aux;
                        if(map[k][i+vert][j+horz] == 'L'){
                            lives--;
                            checkLoloMove(k, i, j);
                            map[k][i+vert][j+horz] = '.';
                            map[k][initialPositions[k][1]][initialPositions[k][0]] = 'L';
                        }

                        if(map[k][i][j+lado] == '|' || map[k][i][j+lado] == 'H' || map[k][i][j+lado] == 'U'){
                            if(lado == fabs(lado)) lado = -1;
                            else lado = 1;
                        }

                        map[k][i][j] = '.';
                        map[k][i][j+lado] = 'B';
                    }
                }
            }
        }
    }
}
void monstersMoves(int map){
    switch(map){
        case 0:
            break;
        case 1:
            gol();
        case 2:
            leeper();
        case 3:
            skull();
    }
}


int game(int window, Font font, Texture2D *images){
    frames++;

    checkMonster();
    howManyHearts();



    if(!heartCounter) openChest();


    int keyPressed = 0;



    BeginDrawing();
        ClearBackground(BLACK);
        SetMouseCursor(1);

        if(!lives) window = 6;

        sprintf(clives, "%d", lives);
        sprintf(cguns, "%d", guns);
        sprintf(cpoints, "%d", points);



        if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
            keyPressed++;
            v = -1;
            h = 0;
            if(keyPressed == 1) move(v, h, k);
        }

        if(IsKeyDown(KEY_S) | IsKeyDown(KEY_DOWN)){
            keyPressed++;
            v = 1;
            h = 0;
            if(keyPressed == 1) move(v, h, k);
        }

        if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
            keyPressed++;
            v = 0;
            h = 1;
            if(keyPressed == 1) move(v, h, k);
        }

        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
            keyPressed++;
            v = 0;
            h = -1;
            if(keyPressed == 1) move(v, h, k);
        }

        if(IsKeyPressed(KEY_SPACE))
            if(guns) shot(v, h, k);

        DrawTextureEx(images[21], (Vector2){530,16}, 0, 0.13, RAYWHITE);
        if(CheckCollisionPointRec(GetMousePosition(), (Rectangle){530,16,32,32})){
            SetMouseCursor(4);
            if(IsMouseButtonPressed(0))
                window = 0;
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

        DrawTextureRec(images[0], (Rectangle){112, 16, 416, 448}, (Vector2){112,16}, RAYWHITE);

        for(int i = 0; i < 14; i++){
            for(int j = 0; j < 13; j++){
                switch(map[k][i][j]){
                    case 'W'://internal wall
                        DrawTextureEx(images[1], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'D'://door
                        DrawTextureEx(images[2], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'R'://rock
                        DrawTextureEx(images[3], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'T'://tree
                        DrawTextureEx(images[4], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'H'://hearth
                        DrawTextureEx(images[5], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'S'://snakey
                        DrawTextureEx(images[6], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'K'://chest
                        DrawTextureEx(images[7], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'k'://chest-open
                        DrawTextureEx(images[22], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'L'://lolo
                        DrawTextureEx(images[8], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case ':'://lolo-on-chest
                        DrawTextureEx(images[24], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case ';'://lolo-on-chest
                        DrawTextureEx(images[25], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '-'://wall
                        DrawTextureEx(images[9], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '|'://wall
                        DrawTextureEx(images[10], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '1'://wall-corner
                        DrawTextureEx(images[11], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '2'://wall-corner
                        DrawTextureEx(images[12], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '3'://wall-corner
                        DrawTextureEx(images[13], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '4'://wall-corner
                        DrawTextureEx(images[14], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'O'://water
                        DrawTextureEx(images[15], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'd'://open-door
                        DrawTextureEx(images[23], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'E'://emptychest
                        DrawTextureEx(images[26], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '#'://letter
                        DrawTextureEx(images[27], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'U'://emeraldframe
                        DrawTextureEx(images[28], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 's': case 'z': case 'b': case 'f': case 'a': case 'm': case 'j': case 'p'://shot
                        DrawCircle((112+j*32)+16, (16+i*32)+16, 16, WHITE);
                        break;
                    case 'Z'://gol
                        DrawTextureEx(images[29], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'B'://skull
                        DrawTextureEx(images[30], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'F'://rocky
                        DrawTextureEx(images[31], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'A'://alma
                        DrawTextureEx(images[32], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'P'://donmedusa
                        DrawTextureEx(images[33], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'M'://medusa
                        DrawTextureEx(images[34], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'J'://leeper
                        DrawTextureEx(images[36], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'V'://grass
                        DrawTextureEx(images[35], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '%'://ladder-side
                        DrawTextureEx(images[37], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '^'://arrow-top
                        DrawTextureEx(images[38], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '@'://lolo-on-grass
                        DrawTextureEx(images[39], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '}'://lolo-on-ladder
                        DrawTextureEx(images[40], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case ']'://lolo-on-ladder-side
                        DrawTextureEx(images[41], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case 'Y'://explosive-rock
                        DrawTextureEx(images[42], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                    case '~'://lolo-on-arrow-top
                        DrawTextureEx(images[44], (Vector2){112+j*32,16+i*32}, 0, 0.13, RAYWHITE);
                        break;
                }
            }
        }

        monstersMoves(k);
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
