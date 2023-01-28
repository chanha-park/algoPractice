#include <stdio.h>

static char	orig[101][101];
static char	visit1[101][101];
static char	visit2[101][101];

int	n;
int	count1 = 0;
int	count2 = 0;

int	f_(int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return (0);
	if (visit1[x][y] == 0 && orig[x][y] == c)
	{
		visit1[x][y] = 1;
		f_(x + 1, y, orig[x][y]);
		f_(x - 1, y, orig[x][y]);
		f_(x, y + 1, orig[x][y]);
		f_(x, y - 1, orig[x][y]);
		return (1);
	}
	return (0);
}

int	g_(int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return (0);
	if (visit2[x][y] == 0)
	{
		if (orig[x][y] == 'B' && c != 'B')
			return (0);
		if (orig[x][y] != 'B' && c == 'B')
			return (0);
		visit2[x][y] = 1;
		g_(x + 1, y, orig[x][y]);
		g_(x - 1, y, orig[x][y]);
		g_(x, y + 1, orig[x][y]);
		g_(x, y - 1, orig[x][y]);
		return (1);
	}
	return (0);
}

int	main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", orig[i]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count1 += f_(i, j, orig[i][j]);
			count2 += g_(i, j, orig[i][j]);
		}
	}
	printf("%d %d\n", count1, count2);
	return (0);
}
