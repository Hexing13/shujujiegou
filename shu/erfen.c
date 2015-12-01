/*************************************************************************
	> File Name: erfen.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 20时05分17秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 8

int binsearch(int a[],int k)
{
    int low = 0,high = SIZE-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(a[mid]==k) return mid;
        else if(a[mid]>k) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main()
{
    int a[SIZE]={1,2,3,5,6,8,9,10};
    int i;
    i = binsearch(a,13);
    if(i==-1){
        printf("没有找到!\n");
    }else{
        printf("所在的位置:%d\n",i);
    }

    return 0;
}
