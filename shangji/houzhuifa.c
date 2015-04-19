// =====================================================================================
//
//       Filename:  后缀法算式表达式.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月24日 21时36分42秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hexing (Lucia), 1776898728@qq.com
//        Company:  Xiyou linux
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>

#define Maxlen 50
#define Datatype char 
typedef struct 
{
        Datatype data[Maxlen];
        int top;
}Seqstack;

//中缀转为后缀表达式
void Trans(char *zhongzhui, char houzhui[]);

//计算后缀表达式
float Value(char houzhui[]);

int main()
{
        char zhongzhui[Maxlen], houzhui[Maxlen];

        printf("请输入中缀表达式： ");
        scanf("%s", zhongzhui);
        

        Trans(zhongzhui, houzhui);
        printf("转化后的后缀表达式：");
        printf("%s\n", houzhui);
        printf("value = %f\n", Value(houzhui));
        return 0;
}


void Trans(char *zhongzhui, char houzhui[])
{
        //申请一个栈，用于存放操作符
        Seqstack op;
        int i = 0, j = 0;
        
        op.top = -1;

        //依次读取中缀表达式直到结束
        while(*zhongzhui != '\0'){
                 switch(*zhongzhui){
                        case '(':          //左括号进栈
                                op.top++;
                                op.data[op.top] = *zhongzhui;
                                zhongzhui++;
                                break;
                        case ')':          //将op栈中'('　前面的运算符依次存入后缀表达式并删除它们及'('
                                while(op.data[op.top] != '('){
                                        houzhui[i++] = op.data[op.top];
                                        op.top--;
                                }
                                op.top--;   //将'('删除
                                zhongzhui++;
                                break;
                        case '+':
                        case '-':
                                //将栈中'('前面的运算符一次存入后缀表达式病删除它们
                                while(op.top != -1 && op.data[op.top] != '('){
                                        houzhui[i++] = op.data[op.top];
                                        op.top--;
                                }

                                //将'+'入栈
                                op.top++;
                                op.data[op.top] = *zhongzhui;
                                zhongzhui++;
                                break;
                        case '*':
                        case '/':
                                
                                //将栈中'*' 或'/'运算符输入后缀表达式
                                while(op.data[op.top] == '*' || op.data[op.top] == '/'){
                                        houzhui[i++] = op.data[op.top];
                                        op.top--;
                                }

                                //将'*' 或'/'入栈
                                op.top++;
                                op.data[op.top] = *zhongzhui;
                                zhongzhui++;
                                break;
                        case ' ':
                                break;
                        default:
                                while(*zhongzhui >= '0' && *zhongzhui <= '9'){
                                        houzhui[i++] = *zhongzhui;
                                        zhongzhui++;
                                }
                                houzhui[i++] = '#';
                 }
        }

        //彻底扫描栈中的元素
        while(op.top != -1){
                houzhui[i++] = op.data[op.top];
                op.top--;
        }
        houzhui[i] = '\0';
}

float Value(char *houzhui)
{       
        //申请栈存储操作数
        Seqstack s;
        float a, b, c, d;
        s.top = -1;

        while(*houzhui != '\0'){
                switch(*houzhui){
                        case '+':
                                a = s.data[s.top];
                                s.top--;
                                b = s.data[s.top];
                                s.top--;
                                c = a+b;
                                s.top++;
                                s.data[s.top] = c;
                                break;
                        
                        case '-':
                                a = s.data[s.top];
                                s.top--;
                                b = s.data[s.top];
                                s.top--;
                                c = b-a;
                                s.top++;
                                s.data[s.top] = c;
                                break;
                       
                        case '*':
                                a = s.data[s.top];
                                s.top--;
                                b = s.data[s.top];
                                s.top--;
                                c = a*b;
                                s.top++;
                                s.data[s.top] = c;
                                break;
                        
                        case '/':
                                a = s.data[s.top];
                                s.top--;
                                b = s.data[s.top];
                                s.top--;
                                if(a != 0){
                                         c = b/a;
                                         s.top++;
                                         s.data[s.top] = c;
                                }else{
                                        printf("除零错误!\n");
                                        exit(1);
                                }
                                break;
                        default:
                                d = 0;
                                while(*houzhui >= '0' && *houzhui <= '9'){
                                        d = 10*d + *houzhui-'0';
                                        houzhui++;
                                }
                                s.top++;
                                s.data[s.top] = d;
                                break;
                }
                houzhui++;
        }
        return s.data[s.top];
}
