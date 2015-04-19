/*************************************************************************
	> File Name: erchashu.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月22日 星期三 17时38分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//结点结构体
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}Bitnode, *Bitree;

//创建二叉树
void Createbitree(Bitree *root)
{
    char ch;
    
    ch = getchar();
    if(ch == '#') *root =  NULL;
    else{
        *root = (Bitnode *)malloc(sizeof(Bitnode));
        (*root)->data = ch;
        Createbitree(&((*root)->lchild));
        Createbitree(&((*root)->rchild));
    }
}

//输出从根结点到每个结点的路径
void Printpath(Bitree root, char path[], int len)
{
    int i;
    if(root){
        if(root->lchild == NULL && root->rchild == NULL){
            printf("%c: ", root->data);
            for(i = 0; i < len; i++)
                printf(" %c", path[i]);
            printf(" %c\n", root->data);
        }else{
            path[len] = root->data;
            Printpath(root->lchild, path, len+1);
            Printpath(root->rchild, path, len+1);
        }
    }
}

int main()
{
    Bitree root;
    char path[50];

    Createbitree(&root);
    Printpath(root,path, 0);

    return 0;
}
