/*************************************************************************
	> File Name: mataqipan.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月12日 星期日 12时58分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 9
#define COLS 9

//下不可走的纵横坐标
const int inmove[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int jnmove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

//初始化棋盘
int board[ROWS][COLS] = {0};

//输出棋盘元素
void Print_matrix(int matrix[][COLS], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%5d", matrix[i][j]);
        }
        printf("\n\n\n");
    }
}

//选择出路最小的位置
Position(int a[], int cols)
{
    int i, index = 0, min = a[0];
    for(i = 0; i < cols; i++){
        if(a[i] > 0){
            min = a[i];
            index = i;
            break;
        }
    }
    for(i = index+1; i < cols; i++){
        if(a[i] > 0 && min > a[i]){
            min = a[i];
            index = i;
        }
    }
    if(a[index] > 0){
        return index;
    }
    return -1;
}

//遍历棋盘
int Operate_matrix(int matrix[][COLS], int rows, int cols, int start_i, int start_j)
{
    int i, m, j;  //用于遍历的循环变量
    int npos, nnpos;  //npos代表满足条件的下个位置的个数,　nnpos代表满足条件的下下个位置的个数
    int min;  //min代表下步要走的位置的编号
    int nexti[8] = {0}; //nexti存储符合条件的下个位置横坐标
    int nextj[8] = {0}; //nextj存储符合条件的下个位置纵坐标
    int exit[8] = {0};  //exit存储下下个坐标的出路个数
    
    matrix[start_i][start_j] = 1;
    for(m = 1; m < ROWS*COLS; m++){
        npos = 0;
        for(i = 0; i < 8; i++){
            if(start_i + inmove[i] < 0 || start_i + inmove[i] >= rows || start_j + jnmove[i] < 0 || start_j + jnmove[i] >= cols ||
               matrix[start_i + inmove[i]][start_j + jnmove[i]] > 0)
                continue;
            nexti[npos] = start_i + inmove[i];
            nextj[npos] = start_j + jnmove[i];
            npos++;
        }
        if(npos == 0){
            printf("~~抱歉，不能完成该游戏!\n");
            return -1;   
        }
        if(npos == 1){
            start_i = nexti[0];
            start_j = nextj[0];
            matrix[start_i][start_j] = m+1;
        }
        if(npos > 1){
            for(i = 0; i < npos; i++){
                nnpos = 0;
                for(j = 0; j < 8; j++){
                    if(nexti[i] + inmove[j] >= 0 && nexti[i] + inmove[j] < rows && nextj[i] + jnmove[j] >= 0 && nextj[i] + jnmove[j] < cols &&
                       matrix[nexti[i] + inmove[j]][nextj[i] + jnmove[j]] == 0)
                        nnpos++;
                }
                exit[i] = nnpos;
            }
            if((min = Position(exit, npos)) >= 0){
                start_i = nexti[min];
                start_j = nextj[min];
                matrix[start_i][start_j] = m+1;
            }else{
                printf("抱歉，不能完成该游戏!\n");
                return 1;
            }
        }
    }
    Print_matrix(matrix, rows, cols);
}

void main()
{
    int row, col;

    while(1){
        printf("请输入初始位置<i, j>: ");
        scanf("%d,%d", &row, &col);
        if(row >= 0 && row < 8 && col >= 0 && col < 8)
            break;
    }

    Operate_matrix(board, ROWS, COLS, row, col);
}
