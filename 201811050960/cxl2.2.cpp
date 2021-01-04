#include <stdio.h>  
#define MaxSize 10000  
void king(int m,int n)
{
    int monkey[MaxSize];
    int i=0,j=0,t=-1;
    while(i<m)
    {
        monkey[i]=1;
        i++;
    }
    i=0;
    while(i<m)
    {
        while(j<n)
        {
            t=(t+1)%m;
            if(monkey[t]==1)
                j++;
        }
        monkey[t]=0;
        printf("%d ",t+1);
        i++;
        j=0;
    }
}
int main()
{
    int m,n;
    printf("请输入猴子个数及出列序号：");
    scanf_s("%d %d",&m,&n);
    king(m,n);
    return 0;
}