/*************************************************************************
	> File Name: maxAndmin.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月21日 星期三 20时55分59秒
 ************************************************************************/

#include<stdio.h>
#define N 10
int max = -3267;
int min = 3267;

void maxandmin(int a[N],int left,int right){
    int mid;
    if((left+1)>=right){
        //求最大值
        if(a[left]>a[right]&&a[left]>max){
            max = a[left];
        }
        if(a[right]>a[left]&&a[right]>max){
            max = a[right];
        }
        //求最小值
        if(a[left]<a[right]&&a[left]<min){
            min = a[left];
        }
        if(a[right]<a[left]&&a[right]<min){
            min = a[right];
        }
    }else{
        mid = (left+right)/2;
        maxandmin(a,left,mid);
        maxandmin(a,mid+1,right);
    }
}

int main(void)
{
    int i,n,a[N] = {1,4,56,78,32,56,89,9,-23,-99};
    maxandmin(a,0,N-1);
    printf("最大值:%d\n最小值:%d\n",max,min);
    return 0;
}

