/*************************************************************************
	> File Name: lcs.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月21日 星期三 21时52分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXLEN 100

void LCSLength(int m,int n,char *x,char *y,int c[][MAXLEN],int b[][MAXLEN]){
    int i,j;
    for(i = 0; i <=m; i++) c[i][0]=0;
    for(i = 1; i <=n; i++) c[0][i]=0;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            //注意x序列和c数组下标的差异
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
}

void LCS(int i, int j, char *x,int b[][MAXLEN]){
    if(i==0||j==0)    {return;}
    if(b[i][j]==1){
        LCS(i-1,j-1,x,b);
        printf("%c ",x[i-1]);
    }else if(b[i][j]==2){
        LCS(i-1,j,x,b);
    }else{
        LCS(i,j-1,x,b);
    }
}

int main()
{
    char x[MAXLEN] = "bxlcong";
    char y[MAXLEN] = "abslxcbong";
    int c[MAXLEN][MAXLEN],b[MAXLEN][MAXLEN];
    int m,n;
    m = strlen(x);
    n = strlen(y);
    LCSLength(m,n,x,y,c,b);
    LCS(m,n,x,b);
    printf("\n");

    return 0;
}
