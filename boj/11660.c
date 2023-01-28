#include <stdio.h>

int	map[1024][1024];

int	get_val(int map[1024][1024], int size, int r, int c)
{
	if (r < 0 || c < 0 || r >= size || c >= size)
		return (0);
	else
		return (map[r][c]);
}

int	diff(int map[1024][1024], int size, int x1, int y1, int x2, int y2)
{
	return (map[x2][y2] - get_val(map, size, x2, y1 - 1) - get_val(map, size, x1 - 1, y2) + get_val(map, size, x1 - 1, y1 - 1));
}

int	main(void)
{
	int	n, m, tmp;
	int	x1, y1, x2, y2;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &tmp);
			map[i][j] = tmp + get_val(map, n, i - 1, j) + get_val(map, n, i, j - 1) - get_val(map, n, i - 1, j - 1);
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", diff(map, n, x1 - 1, y1 - 1, x2 - 1, y2 - 1));
	}
	return (0);
}
