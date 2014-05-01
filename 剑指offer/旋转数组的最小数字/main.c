#include <stdio.h>
#define N 1000000

int main()
{
	//freopen("test.txt", "r", stdin);
	int count, i, input[N];

	while (scanf("%d", &count) != EOF)
	{
		for (i = 0; i < count; i++)
			scanf("%d", &input[i]);
		for (i = count - 1; i > 0; i--)
		{
			if (input[i] >= input[i-1])
				continue;
			if (input[i] < input[i-1])
			{
				printf("%d\n", input[i]);
				break;
			}
		}
		if (i == 0)
			printf("%d\n", input[0]);
	}
	return 0;
}

/**************************************************************
Problem: 1386
User: lintingbin2009
Language: C
Result: Accepted
Time:690 ms
Memory:4744 kb
 ****************************************************************/
