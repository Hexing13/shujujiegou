/*************************************************************************
	> File Name: editDistance.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 13时26分50秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXLEN 100

char x[MAXLEN];
char y[MAXLEN];

int min(int a,int b,int c)
{
    int d = a < b?a:b;
    return d < c?d:c;
}

void editDistance(int m,int n,int d[][MAXLEN])
{
    int i,j;

    for(i = 0; i <= m; i++) d[i][0]=i;
    for(j = 1; j <= n; j++) d[0][j]=j;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n;j++){
            int cost = (x[i-1]==y[j-1]?0:1);
            int delete = d[i-1][j]+1;
            int insert = d[i][j-1]+1;
            int substitution = d[i-1][j-1]+cost;
            d[i][j] = min(delete,insert,substitution);
        }
    }
    printf("%d\n",d[m][n]);
}
int main()
{
    int edit[MAXLEN][MAXLEN];
    printf("请分别输入要编辑的两个字符串:");
    scanf("%s%s",x,y);
    editDistance(strlen(x),strlen(y),edit);   
    return 0;
}
