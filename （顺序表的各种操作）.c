#include<stdio.h>
//#include<malloc.h>
#define MAXLEN 100				//����MAXLENΪ100��ʾ�洢�ռ����� 

//˳���ĸ��ֲ��� 


 typedef int DataType; 			//����DateTypeΪint���� 
 typedef struct					//������洢���� 
 {
 	DataType data[MAXLEN];		//���������Ա������ 
 	int Length;					//����Length˳���ĳ��� 
 }SeqList;
 SeqList L;						//����һ��˳��� L
 
  
int  InitList(SeqList *L)
 {
 	/*��ʼ��˳��� L*/
	L->Length = 0;			//��ʼ��˳���Ϊ�� 
  } 
 
 
int CreateList(SeqList *L, int n)
{
	//����˳���������Ԫ�غ���
	int i;
	printf("������%d��������",n);
	for(i = 0; i < n; i++ )
		scanf("%d",&L->data[i]);
	L->Length = i;			//�����Ա�ĳ���Ϊ i 
}


int GetElem(SeqList *L,int i,DataType *x)
{
	//��ȡ˳����е� i λ��Ԫ�غ���
	if (i < 1 || i > L->Length)		//������λ�� i ����ȷʱ
		return 0;
	else
	{
		*x = L->data[i-1];		//��˳����е� i ��Ԫ�ظ�ֵ��ָ�� x ��ָ����
			return 1; 
	 } 
 } 
 
 
int  Locate(SeqList *L, DataType x)
{
	//��˳��� l �ж�λԪ�� x ����
	int i = 0;
	while(i < L->Length && L->data[i] != x)
		i++;
		if(i >= L->Length)
			return 0;
		else
			return i+1;				//���ص���Ԫ��λ�� 
}


int InsElem(SeqList *L, int i, DataType x)
{
	//��˳��� l ���ڵ� i Ϊ�в�����Ԫ�� x �ĺ���
	int j;
	if(L->Length >= MAXLEN)
	{
		printf("˳���������");
		return -1;					//���������ܲ��� 
	 } 
	if(i < 1 || i > L->Length + 1)		//�������Ĳ���λ�õ���ȷ��
	{
	 	printf("����λ�ó���");
	 	return 0;	
	 }
	if(i == L->Length + 1)				//�����λ��Ϊ��β������Ҫ�ƶ�ֱ�Ӳ��뼴��
	{
		L -> data[i-1] = x;
		L -> Length++;
		return 1; 
	} 
	for (j=L->Length-1; j >= i-1; j--)
	//�������ĳλ�ã���������������
		L->data[j+1] = L->data[j];
		L->data[i-1] = x;					//��Ԫ�ز��� 
		L->Length++;						//˳������� 1 
		return 1;							//����ɹ������� 
}


int DelElem(SeqList *L, int i, DataType *x)
{
	//��˳��� L ��ɾ���� i ��Ԫ�غ���
	int j;
	if(L->Length == 0)
	{
		printf("˳���Ϊ�գ�");
		return 0;							//��գ�����ɾ�� 
	}
	if(i < 1 || i > L->Length)				//����Ƿ�ձ�ɾ��λ�õĲ��Ϸ���
	{
		printf("�����ڵ� i ��Ԫ��");
		return 0;
	 } 
	*x = L->data [i-1];						//��ָ�����*x����ɾ����Ԫ��ֵ 
	for (j=i; j<L->Length; j++)				//����ƶ� 
		L->data[j-1] = L->data[j];
	 	L->Length--;						//˳����ȼ�1 
	 	return 1;							//ɾ���ɹ������� 
}


int DispList(SeqList *L)
{
	//��ʾ���˳��� L ��ÿ��Ԫ�غ���
	int i;
	for(i=0; i < L->Length; i++)
		printf("%5d  ",L->data[i]); 
}


int Extreme(SeqList *L)
{
	//��ʾ���˳��� L �е������Сֵ 
	int i,max,min;
	max = min = L->data[0];					//��ʼ�������Сֵ 
	for(i=0; i < L->Length; i++)
	{
		if(L->data[i] > max)
			max = L->data[i]; 				//�����ֵ��ֵ��max 
		if(L->data[i] < min)
			min = L->data[i];				//����Сֵ��ֵ��min 
	}
	printf("˳�����Ԫ�����ֵΪ: %d\n˳�����Ԫ����СֵΪ��%d",max,min);
}


int Change(SeqList *L, int i, int j)
{
	int k;
	if(i > 0 && i <= L->Length &&j > 0 && j <= L->Length && (i != j))
	{
		k = L->data[i-1];
		L->data[i-1] = L->data[j-1];
		L->data[j-1] = k;
		return 1;
	}
	else
		return 0;
	
}


int Menu()
{
	//��ʾ�˵��Ӻ���
	printf("\n                           ˳���ĸ��ֲ���"); 
	printf("\n       ===============================================================");
	printf("\n      |                      1--����˳���                            |");
	printf("\n      |                      2--����Ԫ��                              |");
	printf("\n      |                      3--ɾ��Ԫ��                              |");
	printf("\n      |                      4--��λ����Ԫ��                          |");
	printf("\n      |                      5--��Ԫ��ֵ�������ڱ���λ��              |");
	printf("\n      |                      6--��˳���ĳ���                        |");
	printf("\n      |                      7--�鿴˳�����Ԫ�������Сֵ            |");
	printf("\n      |                      8--����˳�����Ԫ��˳��                  |"); 
	printf("\n      |                      0--����                                  |");
	printf("\n       ===============================================================");
	printf("\n������˵��ţ�0-8����");
}


int main()
{
	SeqList L;
	DataType x;
	InitList(&L);
	int n,i,loc,b,c,change;
	char ch1,ch2,a;
	ch1='y';
	while(ch1=='y' || ch2=='Y')
	{
		Menu();
		scanf("%c",&ch2);
		//getchar();
		switch(ch2)
		{
			case'1':
				InitList(&L);
				printf("�����뽨�����Ա�ĸ�����");
				scanf("%d",&n);
				CreateList(&L,n);
				printf("���������Ա�Ϊ��");
				DispList(&L);
				break;
			case'2':
				printf("������Ҫ�����λ�ã�");
				scanf("%d",&i);
				printf("������Ҫ�����Ԫ��ֵ��");
				scanf("%d",&x);
				if(InsElem(&L,i,x))
				{
					printf("�ѳɹ��ڵ�%d��λ���ϲ���%d�����������Ա�Ϊ��\n",i,x);
					DispList(&L);
				}
				else
					printf("�������Ĳ�������");
					break;
			case'3':
				printf("������Ҫɾ����Ԫ�ص�λ�ã�");
				scanf("%d",&i);
				if(DelElem(&L,i,&x))
				{
					printf("�ѳɹ��ڵ�%d��λ����ɾ��%d��ɾ��������Ա�Ϊ��\n",i,x);
					DispList(&L);
				}
				else
					printf("\n����ɾ���Ĳ�������");
				break;
			case'4':
				printf("������Ҫ�鿴����Ԫ��λ�ã���1��ʼ����");
				scanf("%d",&i);
				if(GetElem(&L,i,&x))
					printf("��ǰ���Ա��%d��Ԫ�ص�ֵΪ��%d",i,x);
				else
					printf("�����λ�ô���");
					break;
				case'5':
					printf("������Ҫ���ҵ�Ԫ�ص�ֵΪ��");
					scanf("%d",&x);
					loc=Locate(&L,x);
					if(loc)
						printf("����Ԫ��ֵΪ%d��λ��Ϊ��%d",x,loc);
					else
						printf("�ñ����޴�Ԫ�أ�");
					break;
				case'6':
					printf("��ǰ���Ա�ĳ���Ϊ��%d\n",L.Length );
					if (L.Length ==0)
					{
						printf("��ǰԪ��ֵΪ�գ�");
					}
					else
						printf("��ǰ���Ա�Ԫ��ֵΪ��\n");
						DispList(&L);
					break;
				case'7':
					Extreme(&L);
					break;
				case'8':
					printf("��������Ҫ����������Ԫ��λ�ã�");
					scanf("%d,%d",&b,&c);
					change = Change(&L,b,c); 
					if(change)
					{
						printf("���ĺ��˳���Ϊ��\n");
						DispList(&L);
					}
					else
						printf("����λ�ô���");
					break;
				case'0':
					ch1='n';
					break;
				default:
					printf("��������������0~8����ѡ��"); 
		}
		if(ch2!='0')
		{
			a=getchar();
			if(a!='\xA')
			{
				getchar();
				ch1='n';
			}
		}
	}
 } 
