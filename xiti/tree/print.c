/*====================================================
  File name :     print1.c
  Create date   : 2013-11-14 16:44
  Modified date : 2013-11-14 16:44
  Author :        Geng Jinkai//Junco
  Email:          249869652@qq.com          
  Explain:                             
  ====================================================
  Please keep this mark,thanks!                        */

#include <stdio.h>
#include <stdlib.h>

#include "bitree.h"
#include "stack.h"

int PostTreeDepth( BiTree *root )
{
    int hl, hr, h;
    if( root == NULL )  return 0;
    hl = PostTreeDepth( root->Lchild );
    hr = PostTreeDepth( root->Rchild );
    return ( ( hl>hr ? hl:hr )+1 );
}

/*
 * 空格的具体个数依赖于结点所处的层数，计算时分数据行，第一行连接符
 * 和第二行连接符;
 * 倒数第一层和倒数第二层之间只有第一行连接符。具体关系如下：
 *
 * 数据行：        
 * ( 2^n-2个' ' ) data ( 2^n+1个' ' )      n为树高
 *
 * 第一行连接符：
 * (2^(n-1)个' ')(2^(n-1)-3个'_')/ \ (2^(n-1)-3个'_')(2^(n-1)+3个' ')
 *
 * 第二行连接符：
 * (2^(n-1)-1个' ')/(2^n-3个' ')\(2^(n-1)+2个' ')
 *
 * 计算第一行连接符时，n=2将导致2^(n-1)-3 = -1，因此前面的空格需要减
 * 少一个，即2^(n-1)个空格变为2^(n-1)-1个空格。第二行连接符计算时，不
 * 会出现这个问题，因为n=2时没有第二行连接符。
 */

void print( BiTree *root , int n )
{
    int j,d;
    int nhigh, na;
    Queue *que;
    que = queue_creat();
    BiTree *p;
    BiTree *end = malloc( sizeof(BiTree) );
    if( root == NULL )  return;
    nhigh = PostTreeDepth(root);
    EnterQueue( que, root );
    EnterQueue( que, end );
    for( d=nhigh; d>=1; d-- ) 
    {
        for( na=1,j=0; j<d-1; ++j )  na*=2;
        for( ; ; )
        {
            DeleteQueue( que, &p );
            EnterQueue( que, p );
            if( p == end )  break;
            for( j=0; j<2*na-2; ++j )  printf(" ");
            printf("%c", p ? p->data:' ' );
            for( j=0; j<2*na+1; ++j )  printf(" ");
        }
        printf("\n");
        if( d == 1 )  break;
        for( ; ; )
        {
            DeleteQueue( que, &p );
            EnterQueue( que, p );
            if( p == end )  break;
            for( j=0; j<( d!=2?na:na-1 ); ++j )  printf(" ");
            for( j=0; j<na-3; ++j )
                printf("%c", p&&p->Lchild ? '_':' ' );
            printf("%c", p&&p->Lchild ? '/':' ' );
            printf(" ");
            printf("%c", p&&p->Rchild ? '\\':' ');
            for( j=0; j<na-3; ++j )
                printf("%c", p&&p->Rchild ? '_':' ' );
            for( j=0; j<(d!=2?na+3:na+2); ++j )  printf(" ");
        }
        printf("\n");    
    
        if( d != 2 )
        {
            for( ; ; )
            {
                DeleteQueue( que, &p );
                EnterQueue( que, p );
                if( p == end )  break;
                for( j=0; j<na-1; ++j )  printf(" ");
                printf("%c", p&&p->Lchild ? '/':' ' );
                for( j=0; j<2*na-3; ++j )  printf(" ");
                printf("%c", p&&p->Rchild ? '\\':' ' );
                for( j=0; j<na+2; ++j )  printf(" ");
            }
            printf("\n");
        }

        for( ; ; )
        {
            DeleteQueue( que, &p );
            if( p == end )  break;
            EnterQueue( que, p ? p->Lchild:NULL );
            EnterQueue( que, p ? p->Rchild:NULL );
        }
        EnterQueue( que, end );
    }
    free(end);
}
