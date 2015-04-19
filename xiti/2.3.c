/*************************************************************************
	> File Name: 2.3.c
	> Author:
	> Mail:
	> Created Time: 2014年10月15日 星期三 19时59分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10

int main()
{
    int a[Maxsize];
    int i, x, count = 0;

    printf("请输入数组: ");
    for(i = 0; i < Maxsize; i++){
        scanf("%d", &a[i]);
    }
    printf("请输入要删除的数：");
    scanf("%d", &x);
    for(i = 0; i < Maxsize; i++){
        if(a[i] == x){
            count++;
        }else{
            a[i-count] = a[i];
        }
    }
    for(i = 0; i < Maxsize-count; i++){
        printf("%4d", a[i]);
    }
    printf("\n");

    return 0;
}
