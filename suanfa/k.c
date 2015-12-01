/*************************************************************************
	> File Name: maxk.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 20时17分20秒
 ************************************************************************/

#include<stdio.h>

//整数的最大位数+1
#define M 11

//m[i][j]表示1~i十进制位分成j段所得的最大乘积 
long m[M][M]={{0,0}} ; 

//w[i][j]表示i~j十进制位所组成的十进制数 
long w[M][M]={{0,0}} ; 

void maxdp(int n,int k,int *a) 
{ 
     int i,j,d,h; 
     long temp,max; 

     for(i=1; i<= n; i++)       //分成一段 
         m[i][1] = w[1][i];         
 
     for(i=1 ; i<= n ; i++)     /* DP 过程*/ 
        for(j=2; j<= k ; j++) 
         { 
             max = 0; 
             for(d=1; d < i ; d++) 
             { 
                 if ( (temp = m[d][j-1]*w[d+1][i]) > max) 
                 { 
                     max = temp ; 
                 } 
             } 
             m[i][j] = max ;     
         } 
} 
 
int main(void) 
 { 
     int n,k,i,j; 
     int a[M]={0},la=0; 
     char c ; 
     printf("请输入n和k:");
     scanf("%d %d",&n,&k);        //input n, k 
     printf("请输入数字:");
     getchar();
     
     //读入整数
     while(( c=getchar() )!='\n')
     { 
         a[++la] = c-'0' ; 
     } 

     //构造w数组
     for(i=1 ; i<= n; i++) 
     { 
         w[i][i]= a[i] ; 
         for(j=i+1 ; j<= n; j++) 
             w[i][j] = w[i][j-1]*10 + a[j] ; 
     } 

     maxdp(n,k,a) ; 

     printf("最大k乘积为：%ld\n",m[n][k]) ; 
     return  0; 
 }  
