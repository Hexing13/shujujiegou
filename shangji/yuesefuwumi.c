#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 100
#define TRUE 1
#define FALSE 0

//创建结点的结构体
typedef struct node
{
	int num;
	struct node *next;
}Lnode, *Linklist;

//创建带头结点的链表
Linklist Creat_linklist(int n);

//运行约瑟夫
void Josephusoperate(Linklist head, int m, int b[]);

//比较给定的值与出列顺序是否相等
int Equal(int a[], int b[], int k, int n);

int main()
{
	int i, n, k, a[MAXNUM], b[MAXNUM];
	Lnode *head;
	
	//输入个数和给定的值得个数
	printf("Please input integets n, k: ");
	scanf("%d %d", &n, &k);

	//输入给定的值
	printf("please input k numbers: ");
	for(i = 1; i <= k; i++ ) 
		scanf("%d", &a[i]);
	
	//循环找到适合的m值
	for(i = 1; i <= n; i++) {
		head = Creat_linklist(n);
		Josephusoperate(head, i, b);
		if(Equal(a, b, k, n)) {
			return TRUE;
		}
	}
	return FALSE;
}

Linklist Creat_linklist(int n)
{
	Lnode *head, *p, *s;
	int i = 1;

	head = p = (Lnode *)malloc(sizeof(Lnode));
	p->num = i;
	while(i < n) {
		i++;
		s = (Lnode *)malloc(sizeof(Lnode));
		s->num = i;
		p->next = s;
		p = s;
	}
	p->next = head;
	return head;
}

void Josephusoperate(Linklist head, int m, int b[])
{
	Lnode *p = head, *s = head, *del = NULL;
	int i = 1, j = 1;
	
	//p指针移至最后一个
	while(p->next != head)
		p = p->next;

	//循环出列
	while(s != s->next) {
		//出列的信息
		if(i == m) {
			del = s;
			p->next = s->next;
			printf("出列号为b[%d]: %d\n", j, s->num);

			b[j++] = s->num;
			s = s->next;
			free(del);
			i = 1;
			continue;
		}
		
		//不符合指针继续移动
		p = s;
		s = s->next;
		i++;
	}
	printf("出列号为b[%d]: %d\n\n", j, s->num);
	b[j] = s->num;
	free(s);
}

int  Equal(int a[], int b[], int k, int n)
{	
	//从最后一个元素开始比较
	for(; k; k--) {
		if(a[k] != b[n--]) {
			printf("Sorry, fail!\n");
			return FALSE;
		}
			
	}
	printf("Congratulation!\n");
	return TRUE;	
}

