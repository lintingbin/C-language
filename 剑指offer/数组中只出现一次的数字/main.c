#include <stdio.h>
#define N 1000001

int input[N];

static void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, i, j, combine, test, one;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &input[i]);
		combine = 0;
		for (i = 0; i < n; i++)
			combine ^= input[i];
		test = 0x01;
		while ((combine&test) == 0)
			test = test<<1;
		j = -1;
		for (i = 0; i < n; i++)//通过与上combine的最低不为0的位，把数组分成两部分，分别可以算出两个值
		{
			if ((test&input[i]) == 0)
			{
				swap(&input[++j], &input[i]);
			}
		}
		one = 0;
		for (i = 0; i < j+1; i++)
			one ^= input[i];
		if (one < (one^combine))
			printf("%d %d\n", one, one^combine);
		else
			printf("%d %d\n", one^combine, one);
	}
	return 0;
}

