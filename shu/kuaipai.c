/*************************************************************************
	> File Name: kuaipai.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 20时33分18秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 8

int division(int a[], int left, int right)
{
    int i,j,temp = a[left];
    while(left < right){
        while(left < right && a[right] > temp) right--;
        a[left] = a[right];
        while(left < right && a[left] < temp) left++;
        a[right] = a[left];
    }
    a[left] = temp;

    return left;
}

void quickSort(int a[], int left, int right)
{
    int base;
    if(left < right){
        base = division(a,left,right);
        quickSort(a,left,base-1);
        quickSort(a,base+1,right);
    }
}

int main()
{
    int a[SIZE] = {3,1,5,6,9,2,10,7},i;
    quickSort(a,0,SIZE-1);
    printf("快排后:");
    for(i = 0; i < SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
