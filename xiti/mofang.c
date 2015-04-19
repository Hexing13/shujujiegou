/*************************************************************************
	> File Name: mofang.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月21日 星期二 21时18分01秒
 ************************************************************************/

#include<stdio.h>
void main()
{
    int a[15][15]={0},i,j,m,n,temp,M;
    printf("请输入一个3~15的奇数：\n");
    scanf("%d",&M);
    i=0;
    j=M/2;
    a[i][j]=1;
    for(temp=2;temp<=M*M;temp++)
    {
        m=i;
        n=j;
        i--;
        j++;
        if(i<0)
        i=M-1;
        if(j>M-1)
          j=0
          if(a[i][j]!=0)
           {
               i=m+1,j=n;
               a[i][j]=temp;
               continue;
           }
          a[i][j]=temp;
    }
          printf("%d×%d魔方阵：\n",M,M);
          for(i=0;i<M;i++)
           {
               for(j=0;j<M;j++)
               printf("%4d",a[i][j]);
               printf("\n");

           }
          }
    }
}
