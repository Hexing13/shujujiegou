/*************************************************************************
	> File Name: charu.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月04日 星期五 21时43分26秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 6

void InsertSort(int a[])
{
    int i,j,temp;
    for(i = 1;i < SIZE; i++ ){
        if(a[i] < a[i-1]){
            temp = a[i];
            for(j = i-1;temp < a[j] && j >= 0; j--)
                a[j+1] = a[j];
            a[j+1] = temp;
        }
    }
}

int main()
{
    int a[SIZE] = {1,4,6,3,9,5},i;
    InsertSort(a);
    printf("插入排序后的顺序：");
    for(i = 0;i < SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
