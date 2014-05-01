#include <stdio.h>
#include <string.h>
#define N 100000

int main()
{
	//freopen("test.txt", "r", stdin);
	int count, i, stack0[N], stack1[N], top0, top1;
	char opt[10];

	while (scanf("%d", &count) != EOF)
	{
		top0 = top1 = -1;
		for (i = 0; i < count; i++)
		{
			scanf("%s", opt);
			if (strcmp(opt, "PUSH") == 0)
			{
				scanf("%d", &stack0[++top0]);
			} else
			{
				if (top1 != -1)
					printf("%d\n", stack1[top1--]);
				else if (top0 == -1)
					printf("-1\n");
				else
				{
					while(top0 != -1)
						stack1[++top1] = stack0[top0--];
					printf("%d\n", stack1[top1--]);
				}
			}
		}
	}
	return 0;
}

/**************************************************************
Problem: 1512
User: lintingbin2009
Language: C
Result: Accepted
Time:70 ms
Memory:1620 kb
 ****************************************************************/
