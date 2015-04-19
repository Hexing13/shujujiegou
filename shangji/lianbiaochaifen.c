//单链表拆分

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LEN 5

//创建节点的结构体
typedef struct number
{
	int num;
	struct number *next;
}Lnode, *Linklist;

//创建链表
Linklist Creat_linklist();

//拆分链表
Linklist Divide_linklist(Linklist head);

//输出链表
void Output_linklist(Linklist head);

int main()
{
	Lnode *head;

	head = Creat_linklist();
	printf("拆分前：");
	Output_linklist(head);
	Divide_linklist(head);
	printf("\n拆分后: ");
	Output_linklist(head);
	printf("\n");
}

Linklist Creat_linklist()
{
	Lnode *head, *p, *s;
	int i = 0;

	head = p = (Lnode *)malloc(sizeof(Lnode));
	while(i++ < LEN) {
		s = (Lnode *)malloc(sizeof(Lnode));
		printf("please input integer: ");
		scanf("%d", &s->num);
		p->next = s;
		p = s;
	} 
	p->next = NULL;
	return head;
}

Linklist Divide_linklist(Linklist head)
{
	Lnode *p1, *p2, *r, *s;
	int num;

	p1 = p2 = head->next;
	r = p1->next;
	num = p1->num;
	while(r) {
		s = r->next;
		if(num > r->num) {
			r->next = p1;
			head->next = r;
			p1 = r;
		}
		if(num < r->num) {
			p2->next = r;
			p2 = r;
		}
		r = s;
	}

	return head;

}

void Output_linklist(Linklist head)
{
	Lnode *p = head->next;

	while(p) {
		printf("%d ", p->num);
		p = p->next;
	}
}
