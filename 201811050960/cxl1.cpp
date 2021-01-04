#include<stdio.h>
int fun(int a, int b)
{
	int c, d, e, f, g;
	d = a / 10;
	e = a % 10;
	f = b / 10;
	g = b % 10;
	c = d * 10 + e * 1000 + f + g * 100;
	return c;
}
int main()
{
	int a, b, c;
	scanf_s("%d%d", &a, &b);
	c = fun(a, b);
	printf("c=%d\n", c);
	return 0;
}