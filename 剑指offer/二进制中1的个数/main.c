#include <stdio.h>
/*时间复杂度只和1的个数有关*/
int main()
{
	//freopen("test.txt", "r", stdin);
	int num, count, n, i;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num);
			count = 0;
			while (num)
			{
				num = num & (num - 1);
				count++;
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
