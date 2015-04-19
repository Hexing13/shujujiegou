/*************************************************************************
	> File Name: kmp.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月17日 星期五 09时15分50秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define Maxsize 50

typedef struct
{
    char ch[Maxsize];
    int len;
}String;

int Index_kmp(String s, String t, int next[])
{
    int i = 0, j = 0;

    while(i < s.len && j < t.len){
        if(j == -1 || s.ch[i] == t.ch[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == t.len)
            return i-t.len;
    else{
            printf("抱歉，无法匹配！\n");   
            return -1;
    } 
}

void Get_next(String t, int next[])
{
    int j = 0, k = -1;
    
    next[0] = -1;
    while(j < t.len-1){
        if(k == -1 || t.ch[j] == t.ch[k]){
            j++;
            k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
    for(j = 0; j < t.len; j++){
        printf("%3d\n",next[j]);
    }
}

int main()
{
    String s, t;
    int next[Maxsize];

    printf("请输入主串s:");
    scanf("%s", s.ch);
    s.len = strlen(s.ch);
    printf("请输入模式串:");
    scanf("%s", t.ch);
    t.len = strlen(t.ch);
    Get_next(t, next);
    printf("%d\n", Index_kmp(s, t, next));

    return 0;
}
