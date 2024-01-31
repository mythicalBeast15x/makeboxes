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
void printRow(int length, int bufferNum, int leftChar, int rightChar, int filler){
    //buffer
    for(int b = 0; b < bufferNum; b++){
        printf("%c", whitespace);
    }
    //first row
    printf("%c", leftChar);
    for(int c = 0; c < length; c++){
        printf("%c", filler);
    }
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
        printRow(cols, x, topLeft, topRight, horizontal);
        //rows
        for(int r = 0; r < rows-1; r++){
            printRow(cols, x, vertical, vertical, whitespace);
            printRow(cols, x, leftConnector, rightConnector, horizontal);
        }
        printRow(cols, x, vertical, vertical, whitespace);
        printRow(cols, x, bottomLeft, bottomRight, horizontal);
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
    MoveWindow(console, r.left, r.top, 500, 500, TRUE);
    if(!makeBox(0,0,13,maxHorizontal-3)){
        printf("Invalid Box");
    }


    getchar();
    getchar();
    return 0;
}
