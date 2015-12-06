/*************************************************************************
	> File Name: guibing.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 10时11分59秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 8
void merge(int a[],int left,int right,int middle)
{
    int i = left,j = middle+1,k = 0,b[right-left+1];
    while(i <= middle && j <= right){
        if(a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= middle) b[k++] = a[i++];
    while(j <= right) b[k++] = a[j++];
    //注意a和b数组下标的问题
    for(i = left,k = 0; i <= right;i++,k++)
        a[i] = b[k];
}

void mergeSort(int a[],int left,int right)
{
    int middle;
    if(left < right){
        //分
        middle = (left+right)/2;
        mergeSort(a,left,middle);
        mergeSort(a,left+1,right);        
        //合
        merge(a,left,right,middle);
    }
}

int main()
{
    int a[SIZE] = {1,9,7,10,2,3,8,5},i;
    mergeSort(a,0,SIZE-1);
    printf("归并排序:");
    for(i = 0; i < SIZE; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
