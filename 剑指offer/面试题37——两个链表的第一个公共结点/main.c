#include <stdio.h>
#include <limits.h>
#define N 1001
int first[N];
int second[N];


int main()
{
	//freopen("test.txt", "r", stdin);
	int n, m, i, distance, index, value;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		index = -1;
		for (i = 0; i < n; i++)
			scanf("%d", &first[i]);
		for (i = 0; i < m; i++)
			scanf("%d", &second[i]);
		if (n > m)
		{
			distance = n - m;
			for (i = 0; i < m; i++)
			{
				if (first[i+distance] == second[i])
				{
					index = i;
					value = second[i];
					break;
				}
			}
		}
		else
		{
			distance = m - n;
			for (i = 0; i < n; i++)
			{
				if (first[i] == second[i+distance])
				{
					index = i;
					value = first[i];
					break;
				}
			}
		}
		if (index == -1)
			printf("My God\n");
		else
			printf("%d\n", value);

	}
	return 0;
}

