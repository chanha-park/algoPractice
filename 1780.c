#include <stdio.h>
#include <stdlib.h>

int	minus = 0;
int	zero = 0;
int	plus = 0;

int	check(int **map, int x, int y, int size)
{
	int	start = map[x][y];

	if (size < 2)
		return (1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (start != map[x + i][y + j])
				return (0);
		}
	}
	return (1);
}

void	count(int **map, int x, int y, int size)
{
	if (check(map, x, y, size))
	{
		if (map[x][y] == 1)
			plus++;
		else if (map[x][y] == -1)
			minus++;
		else
			zero++;
	}
	else
	{
		size /= 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				count(map, x + i * size, y + j * size, size);
		}
	}
}

int	main(void)
{
	int		n;
	int		**map;

	scanf("%d", &n);
	map = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		map[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	}
	printf("========\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("========\n");
	count(map, 0, 0, n);
	printf("%d\n%d\n%d\n", minus, zero, plus);
	for (int i = 0; i < n; i++)
		free(map[i]);
	free(map);
	system("leaks $PPID");
	return (0);
}
