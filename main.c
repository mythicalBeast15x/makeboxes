#include <stdio.h>
void drawTable(int rows, int cols){
    int table[rows][cols];
    for(int row = 0; row < rows; row++ ){
        for(int col = 0; col < cols; col++){
            if(col == 0){
                if(row == 0){
                    //top-left
                    table[row][col] = 201;
                }else if(row == rows-1){
                    //top-right
                    table[row][col] = 187;
                }else{
                    //top-outline
                    table[row][col] = 205;
                }
            }else if(col == cols-1){
                if(row == 0){
                    //bottom-left
                    table[row][col] = 205;
                }else if(row == rows-1){
                    //bottom-right
                    table[row][col] = 188;
                }else{
                    //bottom-outline

                }
            }else if(row == 0 || row == rows-1){
                //vertical bar
                table[row][col] = 186;
            }else{
                table[row][col] = 32;
            }
        }
    }
    for(int x = 0; x < sizeof(table); x++){
        for(int y = 0; y < sizeof(table[x]); y++){
            char a = (char)table[x][y];
            printf("%c", a);
        }
        printf("\n");
    }

}
int main() {
    drawTable(4, 4);
    return 0;
}
