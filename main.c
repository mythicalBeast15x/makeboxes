#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define topLeft 201
#define topRight 187
#define bottomLeft 200
#define bottomRight 188
#define whitespace 32
#define horizontal 205
#define vertical 186
#define leftConnector 204
#define rightConnector 185
#define maxHorizontal 63
#define maxVertical 28
void promptParams(int* x, int* y, int* rows, int* cols){
    printf("Enter Starting X Point: ");
    scanf("%d", x);
    system("cls");
    printf("Enter Starting Y Point: ");
    scanf("%d", y);
    system("cls");
    printf("Enter Number of Rows: ");
    scanf("%d", rows);
    system("cls");
    printf("Enter Number of Columns: ");
    scanf("%d", cols);
    system("cls");
}
void gotoxy(short x, short y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void printRow(int length, short x, short y, int leftChar, int rightChar, int filler, bool hasFiller){
    //buffer
    /*
    for(int b = 0; b < bufferNum; b++){
        printf("%c", whitespace);
    }*/
    //first row
    gotoxy(x, y);
    printf("%c", leftChar);
    if(hasFiller){
        for(int c = 0; c < length; c++){
            gotoxy(x+c+1, y);
            printf("%c", filler);
        }
    }

    gotoxy(x+length, y);
    printf("%c", rightChar);
    printf("\n");
}
bool makeBox(int x, int y, int rows, int cols){
    bool canMake = false;
    if(x >= 0 && y >= 0 && x+cols < maxHorizontal-2 && (y+((2*rows)-1)) <= maxVertical-2){
        for(int b = 0; b < y; b++){
            printf("\n");
        }
        //top row
        printRow(cols, x, y, topLeft, topRight, horizontal, true);
        //rows
        for(int r = 0; r < rows-1; r++){
            printRow(cols, x, y+(r+1), vertical, vertical, whitespace, false);
            printRow(cols, x, y+(r+1), leftConnector, rightConnector, horizontal, true);
        }
        //lastrow
        printRow(cols, x, y+rows, vertical, vertical, whitespace, true);
        printRow(cols, x, y+rows,bottomLeft, bottomRight, horizontal, true);
        canMake = true;
    }
    return canMake;
}
int main() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    int x, y, rows, cols;
    promptParams(&x,&y,&rows, &cols);
    MoveWindow(console, r.left, r.top, 480, 500, TRUE);
    if(!makeBox(x,y,rows,cols)){
        printf("Invalid Box");
    }


    getchar();
    getchar();
    return 0;
}
