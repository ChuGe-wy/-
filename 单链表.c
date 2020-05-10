#include<stdio.h>
#include<malloc.h>

typedef int DataType;				//定义DataType类型为 int 类型 
typedef struct Linknode				//单链表存储类型
{
	DataType data;					//定义结点数据域 
	struct Linknode *next;			//定义结点指针域 
 } LinkList;
 
 
LinkList *InitList()
{
 	//初始化链表
	 LinkList *head;
	 head = (LinkList*)malloc(sizeof(LinkList));		//动态分配结点空间
	 head->next = NULL;
	 return head;					//头结点指针域为空，表示空链表 
 } 
  
  
void CreateList_H(LinkList *head, int n)
{
	//头插法创建链表函数
	LinkList *s;
	int i;
	printf("请输入%d个整数：",n);
	for(i=0; i<n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));	//生成新结点，分配结点空间
		scanf("%d",&s->data );						//读入新结点的数据域 
		s->next = head->next;
		head->next = s;								//将新结点插入头结点之后 
	 } 
	printf("建立链表操作成功！");
 } 


void CreateList_L(LinkList *head, int n)
{
	//尾插法插入链表函数
	LinkList *s, *last;
	int i;
	last = head;			//last始终指向尾结点，开始时指向头结点
	printf("请输入%d个整数：",n);
	for(i=0; i<n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));		//生成新结点 
		scanf("%d",&s->data );		//读入新结点数据域
		s->next = NULL;				//将新结点的指针域为空 
		last->next = s;				//将新结点插入表尾 
		last = s; 
	 } 
	printf("建立链表操作成功！"); 
}

int LengthList(LinkList *head)
{
	//求链表长度
	LinkList *p = head->next;
	int j = 0;
	while(p != NULL)		//当p不指向链表尾部时
	{
		p = p->next;
		j++;
	 }
	return j;
 } 


void Locate(LinkList *head, DataType x)
{
	//在链表中查找值为 x 的位置
	int j = 1;					//计数器
	LinkList *p;
	p = head->next; 
	while(p != NULL && p->data != x)
	{
		p = p->next;
		j++;
	 } 
	if(p = NULL)
		printf("未找到值为%d的结点！",x);
	else
		printf("在表第%d位置找到值为%d的结点！",j,x); 
 } 
 

void SearchList(LinkList *head, int i)
{
	//在链表中的位置查找元素值
	LinkList *p;
	int j = 0;
	p = head;					//p指向头结点 
	if(i > LengthList(head))
		printf("位置错误，链表中没有该位置！");
	while(p->next != NULL && j<i)		//判断当前结点是否是i 
	{
		p = p->next;
		j++;
	 } 
	if(j==i)
		printf("在第%d位置上的元素值为%d!",i,p->data);
}


void InsList(LinkList *head, int i, DataType x)
{
	//按位置插入元素
	int j = 0;
	LinkList *p,*s;
	p = head;
	while(p->next != NULL && j<i-1)		//查找定位需要插入的位置 
	{
		p = p->next;
		j++;
	 } 
	if(p != NULL) 		//*p不为空则将新结点插入到p后
	{
		s = (LinkList*)malloc(sizeof(LinkList));		//生成新结点
		s->data = x;				//将数据x赋值到新结点的数据域 
		s->next = p->next;			//将新结点s的指针域与p结点后面元素相连
		p->next = s;				//将p与新结点s链接
		printf("插入元素成功！"); 
	 } 
	else 
		printf("插入元素失败！");
}


void DelList(LinkList *head, int i)
{
	//按位置删除链表中元素 
	int j = 0;
	DataType x;
	LinkList *p = head, *s;
	while(p->next != NULL && j<i-1)				//定位删除点 
	{
		p = p->next;
		j++;
	}
	if(p->next != NULL && j==i-1)
	{
		s = p->next;			//*q为要删除的结点 
		x = s->data;			//将要删除的结点数据放入指针变量x中 
		p->next = s->next;		//将p结点的指针域与q结点后面元素相连 
		free(s);
		printf("删除第%d位上的元素%d成功！",i,x); 
	}
	else
		printf("删除结点位置错误，删除失败！");
}


void DispList(LinkList *head)
{
	//输出链表函数
	LinkList *p;
	p = head->next;
	while(p != NULL)
	{
		printf("%5d",p->data );
		p=p->next;
	 } 
}



void Menu()
{
	printf("\n               线性表子系统");
	printf("\n ========================================");
	printf("\n|            1--建立                     |"); 
	printf("\n|            2--插入                     |");
	printf("\n|            3--删除                     |");
	printf("\n|            4--按位置查找               |");
	printf("\n|            5--按元素值查找             |");
	printf("\n|            6--求表长                   |");
	printf("\n|            0--返回                     |");
	printf("\n ========================================");
	printf("\n 请输入菜单号（0-6）："); 
}
main()
{
	LinkList *head;
	DataType x;
	int i,n;
	char ch1='y',ch2,a;
	while(ch1=='y' || ch2=='Y')
	{
		Menu();
		scanf("%c",&ch2);
		getchar();
		switch(ch2)
		{
			case '1':
				head = InitList();
				printf("请输入要建立线性表的长度：");
				scanf("%d",&n);
				CreateList_L(head,n);			//用头插法插入建立线性表
				printf("建立后的线性表为：\n");
				DispList(head);
				break;
			case '2':
				printf("请输入要插入元素的位置：");
				scanf("%d",&i);
				getchar();
				printf("请输入要插入的元素值：");
				scanf("%d",&x);
				InsList(head,i,x);
				printf("插入元素%d后的线性表为：\n",x);
				DispList(head);
				break;
			case '3':
				printf("请输入要删除元素的位置：");
				scanf("%d",&i);
				DelList(head,i);
				printf("删除第%d位的元素后的线性表为：\n",i);
				DispList(head);
				break;
			case '4':
				printf("请输入查找元素的位置（值为大于1的整数）：");
				scanf("%d",&i);
				SearchList(head,i);
				break;
			case '5':
				printf("请输入查找的整数：");
				scanf("%d",&x);
				Locate(head,x);
				break;
			case '6':
				printf("该线性表长度为%d!",LengthList(head));
				break;
			case '0':
				ch1 = 'n';
				break;
			default:
				printf("输入有误，请重新输入0-9进行选择！"); 
		}
		if(ch2!='0')
		{
			printf("\n 按回车键继续，按任意键返回主菜单！\n");
			a=getchar();
			if(a!='\xA')
			{
				getchar();
				ch1='n';
			}
		 } 
	}
}
