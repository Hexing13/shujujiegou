/*************************************************************************
	> File Name: huffmantree.c
	> Author: Hexing
	> Mail: 1776898728@qq.com
	> Created Time: 2014年11月06日 星期四 21时37分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 2*N-1

typedef char  *Huffmancode[N+1];

typedef struct
{
    int weight;
    int parent, lchild, rchild;
}Htnode, Huffmantree[M+1];

//在已有数组中选取双亲为0且权值最小的两个数
void Select(Huffmantree ht, int n, int *min1, int *min2)
{   
    int i;
    ht[*min1].weight = ht[*min2].weight = 555;
    
    for(i = 1; i <= n; i++){
        if(ht[i].parent == 0 && ht[i].weight < ht[*min1].weight){
            *min2 = *min1;
            *min1 = i;
        }else if(ht[i].parent == 0 && ht[i].weight <  ht[*min2].weight){
            *min2 = i;
        }
    }
}

//创建哈夫曼树
void Crehuffmantree(Huffmantree ht, int w[], int n)
{
    int m, i, min1, min2;
    m = 2*n-1;
    
    //初始化前ｎ个元素为根结点
    for(i = 1; i <= n; i++){
        ht[i].weight = w[i];
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
    }

    //初始化后n-1个元素
    for(i = n+1; i <= m; i++){
        
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
    }

    //从第n+1个元素开始构造新元素
    for(i = n+1; i <= m; i++){
        min1 = min2 = 0;
        Select(ht, i-1, &min1, &min2);
        ht[i].weight = ht[min1].weight + ht[min2].weight;
        ht[i].lchild = min1;
        ht[i].rchild = min2;
        ht[min1].parent = i;
        ht[min2].parent = i;
    }
}


//输出哈夫曼树
void Printhuffman(Huffmantree ht, int n){
    int i;
    printf("weight\tparent\tlchild\tchild\n");
    for(i = 1; i <= 2*n-1; i++)
        printf("%d\t%d\t%d\t%d\n", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
}

//哈夫曼编码
void Crehuffmancode(Huffmantree ht, Huffmancode hc, int n)
{
    char *cd;
    int start, i, p, c;
    cd = (char *)malloc(n*sizeof(char));
    cd[n-1] = '\0';
    for(i = 1; i <= n; i++){
        start = n-1;
        c = i; 
        p = ht[i].parent;
        while(p != 0){
            --start;
            if(ht[p].lchild == c)
                 cd[start] = '0';
            else cd[start] = '1';
            c = p;
            p = ht[p].parent;
        }
        hc[i] = (char *)malloc(sizeof(char)*(n-start));
        strcpy(hc[i], &cd[start]);
    }
}

//输出哈夫曼编码
void Printhuffmancod(Huffmancode hc, int n)
{
    int i;
    for(i = 1; i <= n; i++){
        printf("%s\n", hc[i]);
    }
}
int main()
{
    Huffmantree ht;
    Huffmancode hc;
    int w[M+1], n, i;

    printf("请输入叶子结点的个数：");
    scanf("%d", &n);
    printf("请输入叶子结点的权值：");
    for(i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    Crehuffmantree(ht, w, n);
    printf("构建后的哈夫曼树为：\n");
    Printhuffman(ht, n);
    
    printf("哈夫曼编码：\n");
    Crehuffmancode(ht, hc, n);
    Printhuffmancod(hc, n);

    return 0;
}
