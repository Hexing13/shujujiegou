/*************************************************************************
	> File Name: fenjie.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月11日 星期五 10时37分12秒
 ************************************************************************/

#include<stdio.h>
#define SIZE 100

int main()
{
    int i = 0,j,result = 1;
    int num;//待分解的数
    int k = 2;//将其从2开始分解
    int m[SIZE];//存储分解的数

    printf("请输入待分解的数:");
    scanf("%d",&num);

    //分解并存入数组
    while(num>=k){
        m[i++] = k;
        num -= k;
        k++;
    }
    
    //如果最后没有分解完
    if(num){
        //如果剩余的一个数等于前一个数,其加2,前面的加1
        if(num==m[i-1]){
            m[i-1]++;
            num--;
        }
        for(j= 0; j < num;j++ )
            m[i-1-j]++;
    }

    //计算乘积
    for(j = 0;j < i;j++)
        result*=m[j];

    printf("最优乘积为:%d\n",result);

    return 0;
}
