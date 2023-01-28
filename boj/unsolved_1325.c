#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	map[10000][10000];

char	visited[10000];

int		result[10000];
int		max, idx;

int	count;

int	comp(const void *a, const void *b)
{
	int	*x = (int *)a;
	int	*y = (int *)b;

	if (x[0] < y[0])
		return (1);
	if (x[0] > y[0])
		return (-1);
	if (x[1] > y[1])
		return (1);
	if (x[1] < y[1])
		return (-1);
	return (0);
}

void	dfs(int curr, int n)
{
	visited[curr] = 1;
	count++;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0 && map[i][curr])
			dfs(i, n);
	}
}

int	main(void)
{
	int	n, m, x, y;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		map[x - 1][y - 1] = '\1';
	}
	for (int i = 0; i < n; i++)
	{
		count = 0;
		dfs(i, n);
		if (count > max)
		{
			idx = 0;
			max = count;
			result[idx++] = i + 1;
		}
		else if (count == max)
		{
			result[idx++] = i + 1;
		}
		memset(visited, 0, n * sizeof(char));
	}
	for (int i = 0; i < idx; i++)
		printf("%d ", result[i]);
	printf("\n");
	return (0);
}
