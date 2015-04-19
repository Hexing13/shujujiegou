#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//创建结点的结构体
typedef struct polynomial
{
	int coef;
	int expn;
	struct polynomial *next;
}Polynomial, *Polyn;

//创建多项式
Polyn Createpolyn();

//输出多项式
void Printpolyn(Polyn p);

//多项式相加
Polyn Addpolyn(Polyn pa, Polyn pb);

//多项式相减
Polyn Subtractpolyn(Polyn pa, Polyn pb);

//多项式相乘
Polyn Multiply(Polyn pa, Polyn pb);

//多项式求导
Polyn Qiudao(Polyn pa);

//求多项式的值
void Qiuzhi(Polyn pa);

Polyn Createpolyn()
{
	Polynomial *head, *rear, *s;
	int c, e;
	
	//创建链表，输入多项式的系数和指数(系数为0时结束输入)
	head = rear = (Polynomial *)malloc(sizeof(Polynomial));
	printf("请输入多项式的系数和指数(系数为0时结束输入): ");
	scanf("%d %d", &c, &e);
	while(c != 0) {
		s = (Polynomial *)malloc(sizeof(Polynomial));
		s->coef = c;
		s->expn = e;
		rear->next = s;
		rear = s;
		printf("请输入多项式的系数和指数(系数为0时结束输入): ");
		scanf("%d %d", &c, &e);
	}
	rear->next = NULL;
	return head;
}

void Printpolyn(Polyn p)
{
	Polyn q = p->next;
	int flag = 1;

	//空链表
	if(!q) {
		printf("0\n");
		return ;
	}
	
	//非空链表
	while(q) {
		//系数为正
		if(q->coef > 0 && flag != 1) {
			putchar('+');
		}

		//系数不是1或者-1
		if(q->coef != 1 && q->coef != -1) {
			printf("%d", q->coef);
			if(q->expn == 1) {
				putchar('X');
			} else if(q->expn) {
				printf("X^%d", q->expn);
			}

		} else {	//系数为1或者-1
			if(q->coef == 1) {
				if(!q->expn) {
					putchar('1');
				} else if(q->expn == 1) {
					putchar('X');
				} else {
					printf("X^%d", q->expn);
				}
			} 

			if(q->coef == -1) {
				if(!q->expn) {
					putchar('-1');
				} else if(q->expn == 1) {
					printf("-X");
				} else {
					printf("-X^%d", q->expn);
				}
			} 
		}
		q = q->next;
		flag++;

	}
	printf("\n");
}

Polyn Addpolyn(Polyn pa, Polyn pb)
{
	Polyn qa = pa->next ;
	Polyn qb = pb->next ;
	Polyn headc, pc, qc;

	headc = pc = (Polyn)malloc(sizeof(Polynomial));
	pc->next = NULL;
	
	//两个多项式均为扫描结束
	while(qa != NULL && qb != NULL) {
		qc = (Polyn)malloc(sizeof(Polynomial));

		//合并
		if(qa->expn < qb->expn) {
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa = qa->next;
		} else if(qa->expn == qb->expn) {
			qc->coef = qa->coef+qb->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			qb = qb->next;
		} else{
			qc->coef = qb->coef;
			qc->expn = qb->expn;
			qb = qb->next;
		}

		if(qc->coef != 0) {
			qc->next = pc->next;
			pc->next = qc;
			pc = qc;
		} else {
			free(qc);
		}
	}

	//pa中有剩余项
	while(qa != NULL) {
		qc = (Polyn)malloc(sizeof(Polynomial));
		qc->coef = qa->coef;
		qc->expn = qa->expn;
		qa = qa->next;
		qc->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	//pb中有剩余项
	while(qb != NULL) {
		qc = (Polyn)malloc(sizeof(Polynomial));
		qc->coef = qb->coef;
		qc->expn = qb->expn;
		qb = qb->next;
		qc->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	return headc;
}

//将pb的系数变为其相反数，然后调用相加函数
Polyn Subtractpolyn(Polyn pa, Polyn pb)
{
	Polynomial *h = pb, *p = pb->next, *pd;
	
	//系数乘以-1
	while(p) {
		p->coef *= -1;
		p = p->next;
	}

	//调用相加函数
	pd = Addpolyn(pa, h);

	//系数变回原值
	for(p = h->next; p; p = p->next)
		p->coef *= -1;

	return pd;
}

Polyn Multiply(Polyn pa, Polyn pb)
{
	Polynomial *head; 
	Polynomial *qa, *qb, *s, *r;

	head = (Polynomial *)malloc(sizeof(Polynomial));
	head->next = NULL;
	r = (Polynomial *)malloc(sizeof(Polynomial));
	r->next = NULL;
	
	//第一个多项式分别与第二个多项式的系数相乘然后相加
	for(qa = pa->next; qa; qa = qa->next) {
		for(qb = pb->next; qb; qb = qb->next) {
			s = (Polynomial *)malloc(sizeof(Polynomial)); 
			r->next = s;
			s->coef = qa->coef * qb->coef;
			s->expn = qa->expn + qb->expn; 
			s->next = NULL;
			head = Addpolyn(r, head);
		}
	}
	return head;
}

Polyn Qiudao(Polyn pa)
{
	Polyn qa = pa->next;
	
	while(qa) {
		if(qa->expn) {
			qa->coef = qa->coef * qa->expn;
			qa->expn = qa->expn -1;
		} else {
			qa->coef = 0;
		}
		qa = qa->next;
	}

	return pa;
}

void Qiuzhi(Polyn pa)
{	
	Polyn qa = pa->next;
	double x, sum = 0;

	printf("请输入x的值：");
	scanf("%lf", &x);
	while(qa) {
		sum += qa->coef * pow(x, qa->expn); 
		qa = qa->next;
	}
	printf("value = %lf\n", sum);
}

int main()
{	Polynomial *head1, *head2, *head3;
	int choice;
	while(1){
		printf("-----------------  一元多项式的运算  ---------------------\n\n");
		printf("		1. 输出多项式\n");
		printf("		2. 多项式相加求值\n");
		printf("		3. 多项式相减求值\n");
		printf("		4. 多项式相乘求值\n");
		printf("		5. 多项式求导求值\n");
		printf("		0. 退出多项式的运算\n");
		printf("		请输入您的选择: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: head1 = Createpolyn();
					Printpolyn(head1);
					break;
			case 2: head1 = Createpolyn();
					Printpolyn(head1);
					head2 = Createpolyn();
					Printpolyn(head2);
					head3 = Addpolyn(head1, head2);
					Printpolyn(head3);
					Qiuzhi(head3);
					break;
			case 3: head1 = Createpolyn();
					Printpolyn(head1);
					head2 = Createpolyn();
					Printpolyn(head2);
					head3 = Subtractpolyn(head1, head2);
					Printpolyn(head3);
					Qiuzhi(head3);
					break;
			case 4: head1 = Createpolyn();
					Printpolyn(head1);
					head2 = Createpolyn();
					Printpolyn(head2);
					head3 = Multiply(head1, head2);
					Printpolyn(head3);
					Qiuzhi(head3);
					break;
			case 5: head1 = Createpolyn();
					Printpolyn(head1);
					head2 = Qiudao(head1);
					Printpolyn(head2);
					Qiuzhi(head2);
					break;
			case 0: printf("--------------------  欢迎下次使用  ------------------------\n");
					return 0;	
		}
	}
	return 0;
}

//遇见的问题 ：pow(x, y)为double；
//			   相乘问题时， 第二项循环的初始化 qb = qb->next;
