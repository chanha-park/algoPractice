#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	v, e, start;
	int	x, y, z;
	long long	**map;


	scanf("%d %d", &v, &e);
	scanf("%d", &start);
	map = malloc(sizeof(long long *) * v);
	for (int i = 0; i < v; i++)
	{
		map[i] = malloc(sizeof(long long) * v);
		for (int j = 0; j < v; j++)
		{
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = 2147483647;
		}
	}
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		if (map[x - 1][y - 1] > z)
			map[x - 1][y - 1] = z;
	}
	for (int k = 0; k < v; k++)
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	for (int i = 0; i < v; i++)
	{
		if (start - 1 == i)
			printf("0\n");
		else if (map[start - 1][i] == 2147483647)
			printf("INF\n");
		else
			printf("%lld\n", map[start - 1][i]);
	}
	return (0);
}
