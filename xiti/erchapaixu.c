/*************************************************************************
	> File Name: erchapaixu.c
	> Author: 
	> Mail: 
	> Created Time: 2014年12月01日 星期一 20时54分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef int keytype;
typedef struct node
{
    keytype key;
    struct node *lchild, *rchild;
}BSTnode, *BSTree;

//二叉排序树的插入
void Insert_BSTree(BSTree *bst, keytype k)
{
    BSTree s;
    if(*bst == NULL){
        s = (BSTree)malloc(sizeof(BSTnode));
        s->key = k;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
    }
    else if(k < (*bst)->key) Insert_BSTree(&((*bst)->lchild), k);
    else if(k > (*bst)->key) Insert_BSTree(&((*bst)->rchild), k);
}

//二叉树的建立
void CreateBST(BSTree *bst)
{
    keytype key;
    *bst = NULL;
    scanf("%d", &key);
    while(key != -1){
        Insert_BSTree(bst, key);
        scanf("%d", &key);
    }
}

//中序遍利二叉排序树
void Midorder(BSTree bst)
{
    if(bst){
        Midorder(bst->lchild);
        printf("%d ", bst->key);
        Midorder(bst->rchild);
    }
}

//二叉排序树的查找
void Search_BSTree(BSTree bst, keytype k)
{
    BSTree q = bst;
    while(q){
        if(q->key == k){
            printf("已找到:");
            printf("%d\n",q->key );            
        }
        if(k < q->key) q = q->lchild;
        else           q = q->rchild;
    }
}

//二叉排序树的删除
BSTree Delete_BSTree(BSTree bst, keytype k)
{
    BSTree p, f, s, q;
    p = bst;
    f = NULL;

    //查找要删除的点
    while(p){
        if(p->key == k)  break;
        f = p;
        if(p->key > k)   p = p->lchild;
        else             p = p->rchild;
    }

    //没有该点，返回原树
    if(p == NULL)   return bst;
    
    //要删除的点没有左子树
    if(p->lchild == NULL){
        //根结点
        if(f == NULL) bst = p->rchild;

        //左子树的左孩子为空
        else if(f->lchild == p)  f->lchild = p->rchild;

        //右子树的左孩子为空
        else                     f->rchild = p->rchild;
        free(p);
    }else{    //要删除的点没有右子树或者有左右子树找其前趋即左子树的最右端
        q = p;
          s = p->lchild;
          while(s->rchild){
              q = s;
              s = s->rchild;
          }
          if(q == p)  q->lchild = s->lchild;
          else        q->rchild = s->lchild;
          p->key = s->key;
          free(s);
    }
    return bst;
}
int main()
{
    BSTree bst;
    bst = (BSTree)malloc(sizeof(BSTnode));
    printf("创建二叉排序树：\n");
    CreateBST(&bst);
    printf("中序遍利二叉排序树：");
    Midorder(bst);
    printf("\n");
    printf("二叉排序树的查找：");
    Search_BSTree(bst, 7);
    printf("二叉排序树的删除：");
    bst = Delete_BSTree(bst, 7);
    printf("中序遍利二叉排序树：");
    Midorder(bst);
    printf("\n");


    return 0;
}
