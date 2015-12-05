/*************************************************************************
	> File Name: xier.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 19时45分30秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 10

void shellInsert(int a[])
{
    int i,j,temp,gap;
    for(gap = SIZE/2; gap > 0; gap /= 2){//步长
        for(i = gap; i < SIZE;i++){//直接插入排序
            if(a[i] < a[i-gap]){
                temp = a[i];
                for(j = i-gap; j >= 0 && temp < a[j]; j -= gap)
                    a[j+gap] = a[j];
                a[j+gap] = temp;
            }
        }
    }
}
int main()
{
    int a[SIZE] = {1,5,3,9,6,8,10,2,4,8},i;
    shellInsert(a);
    printf("希尔排序后的结果：");
    for(; i < SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");
    
    return 0;
}
