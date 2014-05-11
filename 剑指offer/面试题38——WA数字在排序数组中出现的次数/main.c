#include <stdio.h>
#define N 1000001

int input[N];

int compute_pos(int *array, int start, int end, int num)
{
	if (start > end)
		return -1;

	int cur = (end+start)/2;
	if (array[cur] == num)
	{
		if (cur == 0 || (cur > 0 && array[cur-1] != num))
			return cur;
		else
			return compute_pos(array, start, cur-1, num);
	}
	else if (array[cur] < num)
		return compute_pos(array, cur+1, end, num);
	else
		return compute_pos(array, start, cur-1, num);
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, m, i, j, num, count, cur;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &input[i]);

		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &num);
			cur = compute_pos(input, 0, n-1, num);  //返回找到的数的最小下标
			if (cur != -1)
			{
				count = 0;
				while (input[cur++] == num && cur < n)
					count++;
				printf("%d\n", count);
			}
			else
				printf("%d\n", 0);

		}
	}
	return 0;
}

