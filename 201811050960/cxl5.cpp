#include<stdio.h>
#include<stdlib.h>
#define OK    100001
#define ERROR 100002
struct node
{
    int data;
    struct node* next;
};

typedef struct node Node;

struct stack
{
    Node* top;
    int count;
};

typedef struct stack Stack;
int InitStack(Stack* a)
{
    a->top = NULL;
    a->count = 0;

    return OK;
}
int EmptyStack(Stack* a)
{
    return (a->count == 0) ? OK : ERROR;
}
int Push(Stack* a, int e)
{
    Node* b= (Node*)malloc(sizeof(Node));
    if (NULL == b)
    {
        return ERROR;
    }
    b->data = e;
    b->next = a->top;
    a->top = b;
    a->count++;
    return OK;
}
int GetTop(Stack* a)
{
    if (NULL == a->top)
    {
        return ERROR;
    }

    return (a->top->data);
}
int Priority(char s)
{
    switch (s)
    {
    case '(':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int Pop(Stack* a)
{
    int e;

    if (NULL == a->top)
    {
        return ERROR;
    }
    Node* b = a->top;
    e = b->data;
    a->top = b->next;
    free(b);
    a->count--;
    return e;
}
int main()
{
    char str[100] = { 0 };
    int i = 0, tmp = 0, j;
    Stack num, opt;
    if (InitStack(&num) != OK || InitStack(&opt) != OK)
    {
        printf("Init Failure!\n");
        exit(1);
    }
    printf("Please input operator :\n");
    scanf_s("%s", &str);

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
                switch (Pop(&opt))
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
    printf("%d\n", Pop(&num));
    return 0;
}