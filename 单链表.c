#include<stdio.h>
#include<malloc.h>

typedef int DataType;				//����DataType����Ϊ int ���� 
typedef struct Linknode				//������洢����
{
	DataType data;					//������������ 
	struct Linknode *next;			//������ָ���� 
 } LinkList;
 
 
LinkList *InitList()
{
 	//��ʼ������
	 LinkList *head;
	 head = (LinkList*)malloc(sizeof(LinkList));		//��̬������ռ�
	 head->next = NULL;
	 return head;					//ͷ���ָ����Ϊ�գ���ʾ������ 
 } 
  
  
void CreateList_H(LinkList *head, int n)
{
	//ͷ�巨����������
	LinkList *s;
	int i;
	printf("������%d��������",n);
	for(i=0; i<n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));	//�����½�㣬������ռ�
		scanf("%d",&s->data );						//�����½��������� 
		s->next = head->next;
		head->next = s;								//���½�����ͷ���֮�� 
	 } 
	printf("������������ɹ���");
 } 


void CreateList_L(LinkList *head, int n)
{
	//β�巨����������
	LinkList *s, *last;
	int i;
	last = head;			//lastʼ��ָ��β��㣬��ʼʱָ��ͷ���
	printf("������%d��������",n);
	for(i=0; i<n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));		//�����½�� 
		scanf("%d",&s->data );		//�����½��������
		s->next = NULL;				//���½���ָ����Ϊ�� 
		last->next = s;				//���½������β 
		last = s; 
	 } 
	printf("������������ɹ���"); 
}

int LengthList(LinkList *head)
{
	//��������
	LinkList *p = head->next;
	int j = 0;
	while(p != NULL)		//��p��ָ������β��ʱ
	{
		p = p->next;
		j++;
	 }
	return j;
 } 


void Locate(LinkList *head, DataType x)
{
	//�������в���ֵΪ x ��λ��
	int j = 1;					//������
	LinkList *p;
	p = head->next; 
	while(p != NULL && p->data != x)
	{
		p = p->next;
		j++;
	 } 
	if(p = NULL)
		printf("δ�ҵ�ֵΪ%d�Ľ�㣡",x);
	else
		printf("�ڱ��%dλ���ҵ�ֵΪ%d�Ľ�㣡",j,x); 
 } 
 

void SearchList(LinkList *head, int i)
{
	//�������е�λ�ò���Ԫ��ֵ
	LinkList *p;
	int j = 0;
	p = head;					//pָ��ͷ��� 
	if(i > LengthList(head))
		printf("λ�ô���������û�и�λ�ã�");
	while(p->next != NULL && j<i)		//�жϵ�ǰ����Ƿ���i 
	{
		p = p->next;
		j++;
	 } 
	if(j==i)
		printf("�ڵ�%dλ���ϵ�Ԫ��ֵΪ%d!",i,p->data);
}


void InsList(LinkList *head, int i, DataType x)
{
	//��λ�ò���Ԫ��
	int j = 0;
	LinkList *p,*s;
	p = head;
	while(p->next != NULL && j<i-1)		//���Ҷ�λ��Ҫ�����λ�� 
	{
		p = p->next;
		j++;
	 } 
	if(p != NULL) 		//*p��Ϊ�����½����뵽p��
	{
		s = (LinkList*)malloc(sizeof(LinkList));		//�����½��
		s->data = x;				//������x��ֵ���½��������� 
		s->next = p->next;			//���½��s��ָ������p������Ԫ������
		p->next = s;				//��p���½��s����
		printf("����Ԫ�سɹ���"); 
	 } 
	else 
		printf("����Ԫ��ʧ�ܣ�");
}


void DelList(LinkList *head, int i)
{
	//��λ��ɾ��������Ԫ�� 
	int j = 0;
	DataType x;
	LinkList *p = head, *s;
	while(p->next != NULL && j<i-1)				//��λɾ���� 
	{
		p = p->next;
		j++;
	}
	if(p->next != NULL && j==i-1)
	{
		s = p->next;			//*qΪҪɾ���Ľ�� 
		x = s->data;			//��Ҫɾ���Ľ�����ݷ���ָ�����x�� 
		p->next = s->next;		//��p����ָ������q������Ԫ������ 
		free(s);
		printf("ɾ����%dλ�ϵ�Ԫ��%d�ɹ���",i,x); 
	}
	else
		printf("ɾ�����λ�ô���ɾ��ʧ�ܣ�");
}


void DispList(LinkList *head)
{
	//���������
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
	printf("\n               ���Ա���ϵͳ");
	printf("\n ========================================");
	printf("\n|            1--����                     |"); 
	printf("\n|            2--����                     |");
	printf("\n|            3--ɾ��                     |");
	printf("\n|            4--��λ�ò���               |");
	printf("\n|            5--��Ԫ��ֵ����             |");
	printf("\n|            6--���                   |");
	printf("\n|            0--����                     |");
	printf("\n ========================================");
	printf("\n ������˵��ţ�0-6����"); 
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
				printf("������Ҫ�������Ա�ĳ��ȣ�");
				scanf("%d",&n);
				CreateList_L(head,n);			//��ͷ�巨���뽨�����Ա�
				printf("����������Ա�Ϊ��\n");
				DispList(head);
				break;
			case '2':
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				scanf("%d",&i);
				getchar();
				printf("������Ҫ�����Ԫ��ֵ��");
				scanf("%d",&x);
				InsList(head,i,x);
				printf("����Ԫ��%d������Ա�Ϊ��\n",x);
				DispList(head);
				break;
			case '3':
				printf("������Ҫɾ��Ԫ�ص�λ�ã�");
				scanf("%d",&i);
				DelList(head,i);
				printf("ɾ����%dλ��Ԫ�غ�����Ա�Ϊ��\n",i);
				DispList(head);
				break;
			case '4':
				printf("���������Ԫ�ص�λ�ã�ֵΪ����1����������");
				scanf("%d",&i);
				SearchList(head,i);
				break;
			case '5':
				printf("��������ҵ�������");
				scanf("%d",&x);
				Locate(head,x);
				break;
			case '6':
				printf("�����Ա���Ϊ%d!",LengthList(head));
				break;
			case '0':
				ch1 = 'n';
				break;
			default:
				printf("������������������0-9����ѡ��"); 
		}
		if(ch2!='0')
		{
			printf("\n ���س�����������������������˵���\n");
			a=getchar();
			if(a!='\xA')
			{
				getchar();
				ch1='n';
			}
		 } 
	}
}
