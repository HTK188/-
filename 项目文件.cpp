1��
//����ֵʵ��
#include <stdio.h>
int fun(int a,int b)
{   
	int c;
    c=(a/10)*1000+(b%10)*100+(a%10)*10+b/10;
    return c;
}
void main()
{
   int a,b;
   printf("������������λ��:");
   scanf("%d%d",&a,&b);
   printf("%d\n",fun(a,b));
}
//���ò���ʵ��
#include<stdio.h>
main()
{
	int a,b,c,d,e,f,g;
	printf("������������λ����������:");
	scanf("%d%d",&a,&b);
	d=a/10,e=b%10,f=a%10,g=b/10;
	c=1000*d+100*e+10*f+g;
	printf("���ս��:%d\n",c);
}
//ָ�����ʵ��
#include "stdio.h"
void main();
  void fun(int a, int b, long *c)     
{ 
    *c=a/10*1000+a%10*10+b/10+b%10*100;

}    
  void main()  
{   int a,b;
  long c;     
  printf("Input a, b:"); 
  scanf("%d%d", &a, &b);  
  fun(a, b, &c);     
  printf("�ϲ����c��: "%d\n", c);
  main();     
}
2�����룺
//���鷽��
#include <stdio.h>
int main()
{ 
 int p[999];
 int i,j,t;
    int m,n;
    scanf("%d %d", &m, &n);
    for (i=0; i<m; i++)        
        p[i]=1;    //�����к��Ӷ��ȶ���Ϊ1����ʱ���к��Ӷ�û��Ȧ
    t=-1;                        
    printf("����:");
    for (i=1; i<=m; i++)        
    {
        j=1;    
        while(j<=n) //����n�����Ӻ���������ʼ��̭
        {
            t=(t+1)%m;       
            if (p[t]==1) j++;
        }
        p[t]=0; //����n��ʱ���ѵ�n�����0�������Ȧ 
            
    }
 printf("%d\n ",t+1); //���һ����Ȧ�ģ�Ҳ�������Ĵ���
    return 0;
}
//������
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define maxsize 10
typedef int status;
typedef int elemtype;

typedef struct node{
    elemtype num;
    struct node * next;
}node;

typedef struct node* linklist;

int main(void){
    linklist p,q,head;
    int m,n,king,i,j;
    scanf("%d %d",&m,&n);
    if(m==1)//ֻ��һֻ����ʱ����Ϊ1 
       king=1;
    p=q=(linklist)malloc(sizeof(node));//���½ڵ����ռ� 
    head=p;//headָ��ͷԪ�ؽڵ� 
    head->num=1;//����һֻ���ӱ�� 
    for(i=1;i<m;i++)
{   //����mֻ����Χ�ɵ�ԲȦ 
        p=(linklist)malloc(sizeof(node));//pΪ�ȴ�����Ľڵ� 
        p->num=i+1;//p�ı��Ϊi+1 
        q->next=p;//qʼ�ռ�¼β�ڵ�(ʵ���������β�巨) 
        q=p;
    }
    q->next=head;//����βָ������ͷ 

    p=head;//��ʼ���� 
    for(i=1;i<m;i++){//ѭ��m-1�֣���̭m-1ֻ���� 
        for(j=1;j<n-1;j++){//��pָ��Ҫ��̭��Ԫ�ص�ǰ��Ԫ�� 
            p=p->next;
        }
            q=p->next;//qָ��Ҫ��̭�ĺ��� 
            p->next=q->next;//ɾ��q 
            p=q->next;//һ��Ҫ����һ�μ������Ϊ��ɾ��Ԫ�صĺ�� 
            free(q);//�ͷ�q 
    }
    king=p->num;
    free(p);
    printf("�����ǵ�%dֻ\n",king);
}
3�����룺
#include<bits/stdc++.h>
using namespace std;
struct students
{
	int all; 
	int yw;//���� 
	int ss;//��ѧ 
	int yy;//Ӣ�� 
	int id;//ѧ�� 
}
s[305];//����������Ϣ������
int judge(students a,students b)
{
		if(a.all==b.all)
	   { 
	       //�����ĳɼ��ߵ����� 
		    if(a.yw==b.yw)   return a.id<b.id; 
		    return a.yw>b.yw;
	   }
	   return a.all>b.all;  
	
}
int main()
{
	int n;//ѧ�������� 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].yw>>s[i].ss>>s[i].yy;
		s[i].all=s[i].ss+s[i].yw+s[i].yy;
		s[i].id=i;       
	}
	sort(s+1,s+n+1,judge);//�����ܷ�
	for(int i=1;i<=5;i++)//����ĿҪ��˳����� 
	{
		cout<<s[i].id<<' '<<s[i].all<<endl; 
	}
}
4�����룺
#include <iostream>
using namespace std;
int main() {
	cout << "������Ⱦģ��" << endl;
	int m, n, c;
	cin >> m;
	cin >> n;

	char array1[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> array1[i][j];
		}
	}
	// ��������������г�ʼ��

	cin >> c;

	// �����滻
	int array2[2][100];
	int a = 0, b = 0,k = 1;
	while (k <= c)
	{
		for (int i = 0; i < n; i++) {
			for ( int j = 0; j < m; j++) {
				if (array1[i][j] == 'X')
				{
					array2[b][a] = i;
					array2[b + 1][a] = j;
					a++;
				}
			}
		}
		for ( i = 0; i < a; i++) {
			if (array2[b][i] == 0) {

				if (array2[b + 1][i] == 0)
				{
					if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}

				else if (array2[b + 1][i] == m - 1) {
					if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
				}

				else
				{
					if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}
			}
			else if (array2[b][i] == n - 1)
			{
				if (array2[b + 1][i] == 0) {
					if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}

				else if (array2[b + 1][i] == m - 1) {
					if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
				}

				else
				{
					if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}
			}
			else if (array2[b + 1][i] == 0) {
			if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
			}
				}
			else if (array2[b + 1][i] == m - 1) {
			if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
			}
				}
			else {
			if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
			}
				}
		}
		k++;
		a = 0;
	}

	// ������
	for ( i = 0; i < n; i++)
	{
		for ( int j = 0; j < m; j++)
		{
			cout << array1[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
5�����룺
#include<stdio.h>
#include<stdlib.h>
#define OK    100001
#define ERROR 100002
struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

struct stack
{
    Node *top;
    int count;
};

typedef struct stack Stack;
int InitStack(Stack *S)
{
    S->top = NULL;
    S->count = 0;

    return OK;
}
int EmptyStack(Stack *S)
{
    return (S->count == 0) ? OK : ERROR;
}
int Push(Stack *S, int e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (NULL == p)
    {
        return ERROR;
    }
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return OK;
}
int GetTop(Stack *S)
{
    if (NULL == S->top)
    {
        return ERROR;
    }

    return (S->top->data);
}
int Priority(char s)
{
    switch(s)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default :
            return 0;
    }
}
int Pop(Stack *S)
{
    int e;

    if (NULL == S->top)
    {
        return ERROR;
    }
    Node *p = S->top;
    e = p->data;
    S->top = p->next;
    free(p);
    S->count--;
    return e;
}
int main()
{
    char str[100] = {0};
    int i = 0, tmp = 0, j;
    Stack num, opt;
    if (InitStack(&num) != OK || InitStack(&opt) != OK)
    {
        printf("Init Failure!\n");
        exit(1);
    }
    printf("Please input operator :\n");
    scanf("%s",&str);

    while (str[i] != '\0' || EmptyStack(&opt) != OK)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            tmp = tmp * 10 + str[i] - '0';
            i++;

            if (str[i] < '0' || str[i] >'9')
            {
                Push(&num, tmp);
                tmp = 0;
            }
        }
        else
        {
            if (EmptyStack(&opt) == OK || (GetTop(&opt) == '(' && str[i] != ')') || 
                Priority(str[i]) > Priority(GetTop(&opt)))
            {
                Push(&opt, str[i]);
                i++;
                continue;
            }
            if (GetTop(&opt) == '(' && str[i] == ')')
            {
                Pop(&opt);
                i++;
                continue;
            }
            if ((str[i] == '\0' && EmptyStack(&opt) != OK) || str[i] == ')' && GetTop(&opt) != '(' ||
                Priority(str[i]) <= Priority(GetTop(&opt)))
            {
                switch(Pop(&opt))
                {
                    case '+':
                        Push(&num, Pop(&num) + Pop(&num));
                        break;
                    case '-':
                        j = Pop(&num);
                        Push(&num, Pop(&num) - j);
                        break;
                    case '*':
                        Push(&num, Pop(&num) * Pop(&num));
                        break;
                    case '/':
                        j = Pop(&num);
                        Push(&num, Pop(&num) / j);
                        break;
                }
                continue;
            }
        }
    }
    printf("%d\n",Pop(&num));
    return 0;
}
6�����룺
#include<iostream>
#include<string>
using namespace std;
class Vehicle
{
private:

protected:
	string name;
	int wheels;
	int weight;
public:
	Vehicle(int wh, int we, string nm) :wheels(wh), weight(we) { name = nm; }
	void SetWheels(int wh) { wheels = wh; }
	void SetWeight(int we) { weight = we; }
	void SetName(char nm[]) { name = nm; }
	int GetWheels() const { return wheels; }
	int GetWeight() const { return weight; }
	string GetName() const { return name; }
	void show() const;
};
void Vehicle::show() const
{
	cout << "�������ࣺ" << name << endl;
	cout << "������������" << wheels << endl;
	cout << "����������" << weight << endl;
}
class Car :private Vehicle
{
protected:
	int passenger_Load;
public:
	Car(int pl, int wh, int we, string nm) :Vehicle(wh, we, nm), passenger_Load(pl) {}
	void SetPassenger_Load(int pl) { passenger_Load = pl; }
	int GetPassenger_Load() const { return passenger_Load; }
	void show() const;
};
void Car::show() const
{
	cout << "�������ࣺ" << name << endl;
	cout << "������������" << wheels << endl;
	cout << "�����������" << passengerLoad << endl;
	cout << "����������" << weight << "kg" << endl;
}
class Truck :private Vehicle
{
protected:
	int passenger_Load;
	int payload;
public:
	Truck(int p, int pd, int wh, int we, string nm) :Vehicle(wh, we, nm), passenger_Load(p), payload(pd) {}
	void SetPassenger(int p) { passenger_Load = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passenger_Load; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const
{
	cout << "�������ࣺ" << name << endl;
	cout << "������������" << wheels << endl;
	cout << "�����������" << passenger_Load << endl;
	cout << "��������" << payload << "��" << endl;
	cout << "����������" << weight << "��" << endl;
}
int main()
{
	Car car1(5, 4, 1500, "С��");
	car1.show();
	Truck truck1(4, 3, 8, 5, "����");
	truck1.show();

	system("PAUSE");
	return 0;
} 
