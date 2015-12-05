/*************************************************************************
	> File Name: maopao.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 20时04分52秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 6

void bubbleSort(int a[])
{
    int i,j,temp,flag = 1;
    for(i = 0; i < SIZE-1 && flag; i++){
        flag = 0;
        for(j = 0; j < SIZE - i -1; j++){
            if(a[j] > a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
    }
}

int main()
{
    int a[SIZE] = {6,2,9,4,8,1},i;
    bubbleSort(a);
    printf("冒泡排序后：");
    for(i = 0; i < SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
