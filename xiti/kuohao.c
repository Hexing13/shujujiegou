/*
 * =====================================================================================
 *
 *       Filename:  kuohao.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月25日 19时35分57秒
 *       Revision:  none
 *       Compiler:  gcc

 *         Author:  Hexing, 1776898728@qq.com
 *        Company:  Xiyou linux
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define datatype char 
#define Maxlen 50

typedef struct 
{
	datatype data[Maxlen];
	int top;
}Seqstack;

//初始化栈
Seqstack *Init_seqstack();

//判断空栈
int Isempty_seqstack(Seqstack *s);

//入栈
int Push_seqstack(Seqstack *s, datatype x);

//出栈
int Pop_seqstack(Seqstack *s);

//取栈顶
datatype Get_top(Seqstack *s);

//匹配括号
void Match(Seqstack *s, char *str);

int main(int argc, char *argv[])
{
	Seqstack *s;
	char str[Maxlen];

	s = Init_seqstack();
	printf("请输入要匹配的括号: ");
	scanf("%s", str);
	if(strlen(str)%2 == 1){
		printf("抱歉，括号为基数!\n");
		exit(1);
	}else{
		Match(s, str);
	}

	return EXIT_SUCCESS;
}


//初始化栈
Seqstack *Init_seqstack()
{
	Seqstack *s;

	s = malloc(sizeof(Seqstack));
	s->top = -1;

	return s;
}

//判断空栈
int Isempty_seqstack(Seqstack *s)
{
	if(s->top == -1){
		printf("抱歉，栈空!\n");
		return 1;
	}else{
		return 0;
	}
}

//入栈
int Push_seqstack(Seqstack *s, datatype x)
{
	if(s->top == Maxlen-1){
		printf("抱歉，栈满!\n");
		return 0;
	}else{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

//出栈
int Pop_seqstack(Seqstack *s)
{
	if(s->top == -1){
		printf("抱歉，栈空!\n");
		return 0;
	}else{
	//	*x = s->data[s->top];
		s->top --;
		return 1;
	}
}

//取栈顶
datatype Get_top(Seqstack *s)
{
	if(s->top == -1){
		printf("抱歉，栈空!\n");
		return 0;
	}else{
		return s->data[s->top];
	}
}

//匹配括号
void Match(Seqstack *s, char *str)
{
	while(*str){
		if(*str == '(' || *str == '[' || *str == '{'){
			Push_seqstack(s, *str);
		}else{
			if(Isempty_seqstack(s)){
				printf("抱歉，右括号多余!\n");
				exit(1);
			}
			if(*str == ')' && Get_top(s) == '(' || *str == '}' && Get_top(s) == '{' || *str == ']' && Get_top(s) == '['){
				printf("%c %c\n", Get_top(s), *str);
				Pop_seqstack(s);	
			}else{
				printf("抱歉，不匹配!\n");
				exit(1);
			}
		}
		str++;
	}

	if(s->top != -1) {
		printf("抱歉，左括号多余!\n");
		exit(1);
	}
	printf("恭喜，匹配成功!\n");
}

//出现的问题：
//	栈中的都是左括号!
