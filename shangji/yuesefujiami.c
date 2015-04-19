#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

//自定义的结构体类型
typedef struct node
{
	int num;
	int password;
	struct node *next;
}Lnode, *Linklist;

//创建单向循环链表
Linklist Creatlist(int n);

//打印循环链表
void Printlist(Linklist head);

//运行约瑟夫环问题
void Josephusoperate(Linklist head, int m);

int main()
{
	int n = 0, m = 0;
	Lnode *head;

	//控制总人数
	do {
		if(n > MAXLEN) 
			printf("人数太多，请重新输入!\n");
		printf("请输入人数n(最多%d个)：", MAXLEN);
		scanf("%d", &n);
	} while(n > MAXLEN);

	//获得初始的密码
	printf("请输入初始密码m：");
	scanf("%d", &m);

	//创建单向循环链表
	head = Creatlist(n);

	printf("\n--------------------------  打印循环链表  -------------------------\n");
	Printlist(head);
	
	printf("\n--------------------------  打印出队情况  --------------------------\n");
	Josephusoperate(head, m);

	return 0;
}

Linklist Creatlist(int n)
{
	Lnode *head, *p, *s;
	int i = 1, password = 0; 

	head = p = (Lnode *)malloc(sizeof(Lnode));
	p->num = i;
	printf("请输入第%d个人的密码： ",  i++);
	scanf("%d", &password);
	p->password = password;

	while(i <= n) {
		s = (Lnode *)malloc(sizeof(Lnode));
		printf("请输入第%d个人的密码： ", i);
		scanf("%d", &password);
		s->num = i;
		s->password = password;
		p->next = s;
		p = s;
		i++;
	}
	p->next = head;
	return head;
}

void Printlist(Linklist head)
{
	Lnode *p = head;
	printf("\n    ID      PASSWORD\n");
	while(p->next != head) {
		printf("%5d%10d\n", p->num, p->password);
		p = p->next;
	}
}

void Josephusoperate(Linklist head, int m)
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
			printf("第%d个人出列, 密码: %d\n", s->num, s->password);
			m = s->password;
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
	printf("第%d个人出列，密码：%d\n\n", s->num, s->password);
	free(s);
}








