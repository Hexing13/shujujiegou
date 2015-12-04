/*************************************************************************
	> File Name: shuxu.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 19时53分35秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 6

int search(int a[],int k)
{
    int i = SIZE;
    while(a[i]!=k)
        i--;
    return i;
}

int main()
{
    int a[] = {6,1,4,67,43,21};
    int i;
    i = search(a,6);
    if(i==0){
        printf("抱歉，不存在!\n");
    }else{
        printf("在数组中的位置:%d\n",i);
    }

    return 0;
}
