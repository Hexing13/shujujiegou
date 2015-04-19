/*************************************************************************
	> File Name: xishujuzhen.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月09日 星期四 20时10分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100      //非零元素个数的最大值

typedef struct
{
    int row, col;     //行下标，列下标
    int value;   //非零元素值
}Triple;

typedef struct
{
    Triple data[Maxsize+1];   //非零元素三元组表，data[0]未用
    int rows, cols, nums;     //矩阵的行数，列数，非零元素的个数
}Tsmatrix;

//创建稀疏矩阵
void CreateTsmatrix(Tsmatrix *m)
{
    int row, col, value, i;

    //m->data[0].row = 0;   //为以下比较顺序做准备
    printf("请输入矩阵的行数，列数，非零元素的个数：");
    scanf("%d%d%d", &m->rows, &m->cols, &m->nums);
    for(i = 1; i <= m->nums; i++){
        printf("请输入第%d个非零元素的行数，列数，元素值：", i);
        scanf("%d %d %d", &row, &col, &value);
        if(row < 1 || row > m->rows || col < 1 || col > m->cols){
            printf("抱歉，行或列数超出范围!\n");
            exit(1);
        }
        if(row <= m->data[i-1].row && col <= m->data[i-1].col){
            printf("抱歉，行或列顺序出错!\n");
            exit(1);
        }
        m->data[i].row = row;
        m->data[i].col = col;
        m->data[i].value = value;
    }
}

//矩阵相加
void HeTsmatrix(Tsmatrix *m, Tsmatrix *n, Tsmatrix *q)
{
    int i = 1, j = 1, k = 1;

    if(m->rows != n->rows || m->cols != n->cols){
        printf("抱歉，不满足矩阵相加的条件！\n");
        exit(0);
    }
    while(i <= m->nums && j <= n->nums){
        if(m->data[i].row < n->data[j].row){   //m矩阵的行数小
            q->data[k] = m->data[i];
            k++;
            i++;
        }else if(m->data[i].row > n->data[j].row){  //ｎ矩阵行数小
            q->data[k] = n->data[j];
            k++;
            j++;
        }else if(m->data[i].row == n->data[j].row){   //ｍ，ｎ矩阵的行数相等
            if(m->data[i].col < n->data[j].col){   //ｍ矩阵的列数小
                q->data[k] = m->data[i];
                k++;
                i++;
            }else if(m->data[i].col > n->data[j].col){   //ｎ矩阵的列数小
                q->data[k] = n->data[j];
                k++;
                j++;
            }else if(m->data[i].col == n->data[j].col){  //ｍ，ｎ矩阵行列相等
                q->data[k].value = m->data[i].value + n->data[j].value;
                if(!q->data[k].value){   //值相加等零
                    i++;
                    j++;
                }else{        //值相加不为零
                    q->data[k].row = n->data[j].row;
                    q->data[k].col = n->data[j].col;
                    i++;
                    j++;
                    k++;
                }
            }
        }
    }
    while(i <= m->nums){
            q->data[k] = m->data[i];
            k++;
            i++;
    }
    while(j <= n->nums){
            q->data[k] = n->data[j];
            k++;
            j++;
    }
    q->rows = n->rows;
    q->cols = n->cols;
    q->nums = k-1;
}

//矩阵相减
void ChaTsmatrix(Tsmatrix *m, Tsmatrix *n, Tsmatrix *q)
{
    int i;
    if(m->rows != n->rows || m->cols != n->cols){
        printf("抱歉，不满足矩阵相加的条件！\n");
        exit(0);
    }
    for(i = 1; i <= n->nums; i++)
        n->data[i].value *= -1;
    HeTsmatrix(m, n, q);
}

//矩阵逆置
void TransposeTsmatrix(Tsmatrix *m, Tsmatrix *n)
{
    int num[Maxsize+1], position[Maxsize+1];
    int col, t, q;

    n->rows = m->cols;
    n->cols = m->rows;
    n->nums = m->nums;
    if(n->nums){
        //初始化num值
        for(col = 1; col <= m->cols; col++)
            num[col] = 0;

        //计算num值
        for(t = 1; t <= m->cols; t++)
            num[m->data[t].col]++;

        //计算position的值
        position[1] = 1;
        for(col = 2; col <= m->cols; col++)
            position[col] = position[col-1] + num[col-1];

        //再次扫描，一次性确定位置
        for(t = 1; t <= m->nums; t++){
            col = m->data[t].col;
            q = position[col];
            n->data[q].row = m->data[t].col;
            n->data[q].col = m->data[t].row;
            n->data[q].value = m->data[t].value;
            position[col]++;
        }
    }
}

//输出稀疏矩阵
void PrintTsmatrix(Tsmatrix *m)
{
    int i, j, k = 1;

    for(i = 1; i <= m->rows; i++){
        for(j = 1; j <= m->cols; j++){
            if(k <= m->nums && m->data[k].row == i && m->data[k].col == j){
                printf("%3d", m->data[k].value);
                k++;
            }else{
                printf("%3d", 0);
            }       
        }
        printf("\n");
    }
}


int main()
{
    Tsmatrix m, n, q;
    char ch;

    printf("****************     稀疏矩阵运算器     *****************\n\n");
    printf("                  A. 矩阵相加\n");
    printf("                  B. 矩阵相减\n");
    printf("                  C. 矩阵逆置\n");
    printf("                  Y. 继续运算\n");
    printf("                  N. 结束运算\n\n");
    printf("********************************************************\n\n");
    printf("                  请输入您的选择: ");
    scanf("%c", &ch);
    while(ch != 'N'){
        switch(ch){
            case 'A': printf("两矩阵求和\n");
                      printf("请输入第一个矩阵：\n");
                      CreateTsmatrix(&m);
                      printf("输入的第一个矩阵为: \n");
                      PrintTsmatrix(&m);
                      printf("请输入第二个矩阵: \n");
                      CreateTsmatrix(&n);
                      printf("输入的第二个矩阵为: \n");
                      PrintTsmatrix(&n);
                      HeTsmatrix(&m, &n, &q);
                      printf("两矩阵之和为：\n");
                      PrintTsmatrix(&q);
                      printf("请继续输入您的选择:");
                      getchar();
                      scanf("%c", &ch);
                      break;
            
            case 'B': printf("两矩阵求差\n");
                      printf("请输入第一个矩阵：\n");
                      CreateTsmatrix(&m);
                      printf("输入的第一个矩阵为: \n");
                      PrintTsmatrix(&m);
                      printf("请输入第二个矩阵: \n");
                      CreateTsmatrix(&n);
                      printf("输入的第二个矩阵为: \n");
                      PrintTsmatrix(&n);
                      ChaTsmatrix(&m, &n, &q);
                      printf("两矩阵求差为：\n");
                      PrintTsmatrix(&q);
                      printf("请继续输入您的选择:");
                      getchar();
                      scanf("%c", &ch);
                      break;
            case 'C': printf("矩阵转置\n");
                      printf("请输入要转置的矩阵：\n");
                      CreateTsmatrix(&m);
                      printf("输入的矩阵为: \n");
                      PrintTsmatrix(&m);
                      TransposeTsmatrix(&m, &n);
                      printf("转置后的矩阵为：\n");
                      PrintTsmatrix(&n);
                      printf("请继续输入您的选择: ");
                      getchar();
                      scanf("%c", &ch);
                      break;
            case 'Y': printf("请继续输入您的选择:");
                      getchar();
                      scanf("%c", &ch);
                      break;
            default:  printf("抱歉，您的选择有误，请重新选择: ");
                      getchar();
                      scanf("%c", &ch);
                      break;
        }
    }
    printf("***********      运算结束     **************\n\n");
    return 0;
}
