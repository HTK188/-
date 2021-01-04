#include<stdio.h>
#include<stdlib.h>
#define maxsize 10000
typedef int status;
typedef int elemtype;
typedef struct node
{
    elemtype num;
    struct node* next;
}node;
typedef struct node* linklist;
int main(void)
{
    linklist a, b, head;
    int m, n, king, i, j;
    scanf_s("%d %d", &m, &n);
    if (m == 1)
        king = 1;
    a = b = (linklist)malloc(sizeof(node));
    head = a;//head
    head->num = 1;
    for (i = 1; i < m; i++)
    {
        a = (linklist)malloc(sizeof(node));
        a->num = i + 1;
        b->next = a;
        b = a;
    }
    b->next = head;

    a = head;
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            a = a->next;
        }
        b = a->next;
        a->next = b->next;
        a = b->next;
        free(b);
    }
    king = a->num;
    free(a);
    printf("猴王是:%d\n", king);
}