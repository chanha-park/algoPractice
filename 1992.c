#include <stdio.h>
#include <stdlib.h>

int	is_same(char **map, int r, int c, int size)
{
	char	k = map[r][c];

	for (int i = r; i < r + size; i++)
		for (int j = c; j < c + size; j++)
			if (k != map[i][j])
				return (0);
	return (1);
}

void	f(char **map, int r, int c, int size)
{
	if (is_same(map, r, c, size))
		printf("%c", map[r][c]);
	else
	{
		size >>= 1;
		printf("(");
		f(map, r, c, size);
		f(map, r, c + size, size);
		f(map, r + size, c, size);
		f(map, r + size, c + size, size);
		printf(")");
	}
}

int	main(void)
{
	int	n;
	char	**map;

	scanf("%d", &n);
	map = malloc(sizeof(char *) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		map[i] = malloc(sizeof(char) * (n + 1));
		scanf("%s", map[i]);
	}
	map[n] = NULL;
	f(map, 0, 0, n);
	printf("\n");
	return (0);
}
