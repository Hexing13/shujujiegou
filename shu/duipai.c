/*************************************************************************
	> File Name: duipai.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 09时42分37秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 8
void heapAdjust(int a[], int parent,int length)
{
    int temp = a[parent];//多余的一个辅助空间保存待调整结点
    int child = parent*2+1;

    while(child < length){
        //获得左右孩子的最大值
        if(child+1 < length && a[child] < a[child+1])
            child++;
        //创建大顶堆,如果符合,则直接退出
        if(temp > a[child])
            break;
        //复制,循环
        a[parent] = a[child];
        parent = child;
        child = child*2+1;
    }
    a[parent] = temp;
}
void creatHeap(int a[])
{
    int i;
    //非根结点从下到上一次创建大顶堆
    for(i = SIZE/2; i >= 0 ; i--)
        heapAdjust(a,i,SIZE-1);
}

void heapSort(int a[])
{
    int i = 0,temp;
    //创建大顶堆
    creatHeap(a);
    //取顶,交换,调整
    for(i = SIZE-1; i > 0; i--){
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapAdjust(a,0,i);
    }
}

int main()
{
    int a[SIZE] = {1,5,9,3,6,8,2,10},i;
    heapSort(a);
    printf("堆排后:");
    for(i = 0; i < SIZE-1; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
