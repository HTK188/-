#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int chinese;
    int math;
    int english;
    int num;
    int sum;
}student[10000];
int cmp(node a, node b)
{
    if (a.sum==b.sum &&a.chinese!= b.chinese) 
        return a.chinese>b.chinese;
    if (a.sum==b.sum &&a.chinese==b.chinese)
        return a.num<b.num;
    else 
        return a.sum>b.sum;
}
int main()
{
    int i,j,n,m;
    scanf_s("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf_s("%d%d%d",&student[i].chinese,&student[i].math,&student[i].english);
        student[i].num=i+1;
        student[i].sum =student[i].chinese+student[i].math+student[i].english;
    }
    sort(student, student + n, cmp);
    for (i=0;i<5;i++)
        printf("%d %d\n",student[i].num,student[i].sum);
    while (1);
    return 0;
}