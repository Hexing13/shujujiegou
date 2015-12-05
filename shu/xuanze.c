/*************************************************************************
	> File Name: xuanze.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 20时57分56秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 8

void selectSort(int a[])
{
    int i,j,k,t;
    for(i = 0; i < SIZE-1; i++){
        k = i;
        for(j = i+1; j < SIZE-1; j++){
            if(a[j] < a[k])
                k = j;
        }
        if(k!=i){
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}

int main()
{
    int a[SIZE] = {6,4,2,9,8,1,3,10},i;
    selectSort(a);
    printf("选择排序后:");
    for(i = 0; i < SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
