#include "stdio.h"
void main()
{
	int M, N, c;
	char y[10000][10000];
	int a, b, x;

	printf("请输入长和宽\n");
	scanf_s("%d%d", &N, &M);
	for (a = 0; a < M; a++)
	{
		for (b = 0; b < N + 1; b++)
		{
			scanf_s("%c", &y[a][b]);
		}
	}


	scanf_s("%d", &c);
	for (x = 0; x < c; x++)
	{
		for (a = 0; a < M; a++)
		{
			for (b = 0; b < N + 1; b++)
			{
				if (y[a][b] == 'X')
				{
					if (y[a + 1][b] == 'O')
						y[a + 1][b] = 'N';
					if (y[a - 1][b] == 'O')
						y[a - 1][b] = 'N';
					if (y[a][b + 1] == 'O')
						y[a][b + 1] = 'N';
					if (y[a][b - 1] == 'O')
						y[a][b - 1] = 'N';
				}
			}
		}
		for (a = 0; a < M; a++)
		{
			for (b = 0; b < N; b++)
			{
				if (y[a][b] == 'N')
					y[a][b] = 'X';
			}
		}
	}

	for (a = 0; a < M; a++)
	{
		for (b = 0; b < N + 1; b++)
		{
			printf("%c", y[a][b]);
		}printf("\n");
	}printf("\n");
}