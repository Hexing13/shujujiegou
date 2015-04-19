#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 50

typedef int datatype;
typedef struct stack
{
	datatype data[MAXSIZE];
	int top;
}Seqstack;

//建立栈空间，并初始化栈顶指针
Seqstack *Init_seqstack();

//判断栈是否为空
int Isempty_seqstack(Seqstack *s);

//入栈
int Push_seqstack(Seqstack *s, datatype x);


//出栈
int Pop_seqstack(Seqstack *s, datatype *x);

//取栈顶元素
int Get_top(Seqstack *s);

//判断读入的是运算符还是操作数
int RDorTR(char ch);

//判断栈顶运算符与读入运算符的优先关系
int Compare(char ch1, char ch2);

//二元运算函数
int Operate(int a, char ch, int b);

Seqstack *Init_seqstack()
{
	Seqstack *s;
	s = malloc(sizeof(Seqstack));
	if(!s){		
		//申请空间不足
		printf("抱歉， 空间不足!\n");
		return NULL;
	}else{
		//初始化申请空间
		s->top = -1;
		printf("恭喜， 栈初始化成功!\n");
		return s;
	}
}

int Isempty_seqstack(Seqstack *s)
{
	if(s->top == -1)	return 1;
	else 			return 0;
}

int Push_seqstack(Seqstack *s, datatype x)
{
	if(s->top == MAXSIZE-1){
		printf("抱歉， 栈满不能入栈!\n");
		return 0;
	}else{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

int Pop_seqstack(Seqstack *s, datatype *x)
{
	if(Isempty_seqstack(s)){
		printf("抱歉，栈空不能出栈!\n");
		return 0;
	}else{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
}

int Get_top(Seqstack *s)
{
	if(Isempty_seqstack(s)){
		printf("抱歉，栈空不能读取栈元素!\n");
		return 0;
	}else{
		return s->data[s->top];
	}
}

int RDorTR(char ch)
{	//flag = 1标志是操作数，flag = 0标志是操作符
	int flag = 1;
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '#' || ch == '(' || ch == ')')
		flag = 0;

	return flag;
}

int Compare(char in, char out)
{
	int c_temp1,c_temp2;
	//标志运算规则
	int temp;
	
	//操作符栈顶元素
	switch(in){
		case '^': c_temp1 = 5; break;
		case '*':
		case '/':
		case '%': c_temp1 = 4; break;
		case '+':
		case '-': c_temp1 = 2; break;
		case '(': c_temp1 = 0; break;
		case ')': c_temp1 = 6; break;
		case '#': c_temp1 = -1;
	}

	//读到的操作符
	switch(out){
		case '^': c_temp2 = 5; break;
		case '*':
		case '/':
		case '%': c_temp2 = 3; break;
		case '+':
		case '-': c_temp2 = 1; break;
		case '(': c_temp2 = 6; break;
		case ')': c_temp2 = 0; break;
		case '#': c_temp2 = -1;
	}

	//栈外算符优先级高入栈
	if (c_temp1<c_temp2) temp = -1;

	//栈内外算符优先级相等
	if (c_temp1==c_temp2) temp = 0;

	//栈内算符优先级高运算
	if (c_temp1>c_temp2) temp = 1;

	return(temp);
}

int Operate(int a, char ch, int b)
{
	int s;
	switch(ch){
		case '^': s=(int)pow(a,b); break;
		case '*': s=a*b; break;
		case '/': s=a/b; break;
		case '%': s=a%b; break;
		case '+': s=a+b; break;
		case '-': s=a-b; break;
	}
	return(s);
}

void main()
{	
	int ch, temp, data;
	int op, num1, num2;
	
	//oprd,optr分别指向操作数栈和操作符栈
	Seqstack *oprd, *optr;	
	
	//初始化操作数栈和操作符栈
	oprd = Init_seqstack();
	optr = Init_seqstack();
	Push_seqstack(optr, '#');
	system("cls");
	printf("------------------中缀表达式求值程序------------------\n\n");
	printf("-----使用：连续输入表达式#号结束按车键\n\n");
	printf("-----使用运算符包括：(、)、^、*、/、%、+、-\n\n");
	printf("-----注意：运算数0-9十个数字\n\n");
	printf("-----请输入表达式：");
	ch = getchar();
	while(ch != '#' || Get_top(optr) != '#'){
		//输入的是操作数
		if(RDorTR(ch)){
			data = ch - '0';
			ch = getchar();
			//将一个数转化为十进制
			while(RDorTR(ch)){
				data = data*10 + ch-'0';	
				ch = getchar();
			}
			//将操作数压入栈中
			Push_seqstack(oprd, data);
			printf("%d\n", data);
		}else{
			switch(Compare(Get_top(optr), ch)){
				//栈外算符优先级高入栈
				case -1: Push_seqstack(optr, ch);
						 ch = getchar();
					     break;

				//栈内外算符优先级相等
				case 0:  Pop_seqstack(optr, &temp);
					     ch = getchar();
					     break;

				//栈内算符优先级高运算
				case 1:  Pop_seqstack(optr, &op);
						 Pop_seqstack(oprd, &num2);
						 Pop_seqstack(oprd, &num1);
						 Push_seqstack(oprd, Operate(num1, op, num2));
					     break;
			}
		}
	}
	printf("value = : %d\n", Get_top(oprd));
}

//出现的问题:
//		int, char 类型转化的实质；
//		取出两个数字时的顺序问题;
