#include <stdio.h>
#define N 71

int main()
{
	//freopen("test.txt", "r", stdin);
	int count, i, j;
	long long result[N] = {0};//注意类型大小

	result[0] = 0;
	result[1] = 1;
	result[2] = 2;
	for (i = 3; i < N; i++)
	{
		for (j = i - 1; j >= 1; j--)
			result[i] += result[j];//先保存起来，以后就不用每次都计算
		result[i]++;
	}

	while (scanf("%d", &count) != EOF)
	{
		printf("%lld\n", result[count]);
	}
	return 0;
}

/**************************************************************
Problem: 1389
User: lintingbin2009
Language: C
Result: Accepted
Time:0 ms
Memory:912 kb
 ****************************************************************/
