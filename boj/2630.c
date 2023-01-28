#include <stdio.h>
#include <stdlib.h>

int	white = 0;
int	blue = 0;

int	check(char **map, int x, int y, int size)
{
	char	start = map[x][y];

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

void	count(char **map, int x, int y, int size)
{
	if (check(map, x, y, size))
	{
		if (map[x][y] == '1')
			blue++;
		else
			white++;
	}
	else
	{
		count(map, x, y, size / 2);
		count(map, x + size / 2, y, size / 2);
		count(map, x, y + size / 2, size / 2);
		count(map, x + size / 2, y + size / 2, size / 2);
	}
}

int	main(void)
{
	int		n;
	char	buff[260];
	char	**map;

	scanf("%d", &n);
	map = malloc(sizeof(char *) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		scanf("\n%[^\n]", buff);
		map[i] = malloc(sizeof(char) * (n + 1));
		for (int j = 0; buff[j]; j++)
		{
			if (buff[j] != ' ')
				map[i][j / 2] = buff[j];
		}
		map[i][n] = '\0';
	}
	map[n] = NULL;
	count(map, 0, 0, n);
	printf("%d\n%d\n", white, blue);
	for (int i = 0; i < n; i++)
		free(map[i]);
	free(map);
	system("leaks $PPID");
	return (0);
}
