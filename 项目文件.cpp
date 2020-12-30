1、
//返回值实现
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
   printf("请输入两个两位数:");
   scanf("%d%d",&a,&b);
   printf("%d\n",fun(a,b));
}
//引用参数实现
#include<stdio.h>
main()
{
	int a,b,c,d,e,f,g;
	printf("请输入两个两位数的正整数:");
	scanf("%d%d",&a,&b);
	d=a/10,e=b%10,f=a%10,g=b/10;
	c=1000*d+100*e+10*f+g;
	printf("最终结果:%d\n",c);
}
//指针参数实现
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
  printf("合并结果c是: "%d\n", c);
  main();     
}
2、代码：
//数组方法
#include <stdio.h>
int main()
{ 
 int p[999];
 int i,j,t;
    int m,n;
    scanf("%d %d", &m, &n);
    for (i=0; i<m; i++)        
        p[i]=1;    //把所有猴子都先定义为1，此时所有猴子都没出圈
    t=-1;                        
    printf("大王:");
    for (i=1; i<=m; i++)        
    {
        j=1;    
        while(j<=n) //数了n个猴子后跳出，开始淘汰
        {
            t=(t+1)%m;       
            if (p[t]==1) j++;
        }
        p[t]=0; //数到n个时，把第n个变成0，代表出圈 
            
    }
 printf("%d\n ",t+1); //最后一个出圈的，也就是最后的大王
    return 0;
}
//链表方法
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
    if(m==1)//只有一只猴子时猴王为1 
       king=1;
    p=q=(linklist)malloc(sizeof(node));//给新节点分配空间 
    head=p;//head指向头元素节点 
    head->num=1;//给第一只猴子编号 
    for(i=1;i<m;i++)
{   //建立m只猴子围成的圆圈 
        p=(linklist)malloc(sizeof(node));//p为等待插入的节点 
        p->num=i+1;//p的编号为i+1 
        q->next=p;//q始终记录尾节点(实质是链表的尾插法) 
        q=p;
    }
    q->next=head;//链表尾指向链表头 

    p=head;//开始计数 
    for(i=1;i<m;i++){//循环m-1轮，淘汰m-1只猴子 
        for(j=1;j<n-1;j++){//让p指向要淘汰的元素的前驱元素 
            p=p->next;
        }
            q=p->next;//q指向要淘汰的猴子 
            p->next=q->next;//删除q 
            p=q->next;//一定要让下一次计数起点为被删除元素的后继 
            free(q);//释放q 
    }
    king=p->num;
    free(p);
    printf("猴王是第%d只\n",king);
}
3、代码：
#include<bits/stdc++.h>
using namespace std;
struct students
{
	int all; 
	int yw;//语文 
	int ss;//数学 
	int yy;//英语 
	int id;//学号 
}
s[305];//储存以上信息的数组
int judge(students a,students b)
{
		if(a.all==b.all)
	   { 
	       //按语文成绩高低排序 
		    if(a.yw==b.yw)   return a.id<b.id; 
		    return a.yw>b.yw;
	   }
	   return a.all>b.all;  
	
}
int main()
{
	int n;//学生总人数 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].yw>>s[i].ss>>s[i].yy;
		s[i].all=s[i].ss+s[i].yw+s[i].yy;
		s[i].id=i;       
	}
	sort(s+1,s+n+1,judge);//排序总分
	for(int i=1;i<=5;i++)//按题目要求顺序输出 
	{
		cout<<s[i].id<<' '<<s[i].all<<endl; 
	}
}
4、代码：
#include <iostream>
using namespace std;
int main() {
	cout << "病毒传染模型" << endl;
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
	// 输入区域数组进行初始化

	cin >> c;

	// 进行替换
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

	// 输出结果
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
5、代码：
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
6、代码：
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
	cout << "汽车种类：" << name << endl;
	cout << "汽车车轮数：" << wheels << endl;
	cout << "汽车重量：" << weight << endl;
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
	cout << "汽车种类：" << name << endl;
	cout << "汽车车轮数：" << wheels << endl;
	cout << "最大载人数：" << passengerLoad << endl;
	cout << "汽车重量：" << weight << "kg" << endl;
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
	cout << "汽车种类：" << name << endl;
	cout << "汽车车轮数：" << wheels << endl;
	cout << "最大载人数：" << passenger_Load << endl;
	cout << "载重量：" << payload << "吨" << endl;
	cout << "汽车重量：" << weight << "吨" << endl;
}
int main()
{
	Car car1(5, 4, 1500, "小车");
	car1.show();
	Truck truck1(4, 3, 8, 5, "卡车");
	truck1.show();

	system("PAUSE");
	return 0;
} 
