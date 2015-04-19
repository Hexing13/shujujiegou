/*************************************************************************
	> File Name: zuidacida.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月15日 星期三 19时31分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define Maxsize 6

int main()
{
    int a[Maxsize];
    int i;
    int first = -32768, second = -32768;
    
    printf("请输入数组:");
    for(i = 0; i < 6; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < 6; i++){
        printf("%4d", a[i]);
    }
    printf("\n");

    for(i = 0; i < Maxsize; i++){
        if(a[i] > first){
            second = first;
            first = a[i];
        }else if(a[i] > second){
            second = a[i];
        }
    }
    printf("%d %d\n", first, second);
    return 0;

}
