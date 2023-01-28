#include <stdio.h>
#include <stdlib.h>

// sol 1

void	dfs(int **connect, int *visited, int n, int pop, int *count)
{
	for (int i = 0; i < n; i++)
	{
		if (connect[pop][i] == 1 && visited[i] == 0)
		{
			*count += 1;
			visited[i] = 1;
			dfs(connect, visited, n, i, count);
		}
	}
}

int	main(void)
{
	int	n, m, x, y;
	int	**connect;
	int	*visited;
	int	count = 0;

	scanf("%d", &n);
	scanf("%d", &m);

	connect = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
		connect[i] = calloc(n, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		connect[x - 1][y - 1] = 1;
		connect[y - 1][x - 1] = 1;
	}
	visited = calloc(n, sizeof(int));
	visited[0] = 1;
	dfs(connect, visited, n, 0, &count);
	printf("%d\n", count);
	for (int i = 0; i < n; i++)
		free(connect[i]);
	free(connect);
	free(visited);
	return (0);
}

/*
// sol 2
int	main(void)
{
	int	n, m, x, y;
	int	**connect;
	int	*stack;
	int	*visited;
	int	count = 0;
	int idx = 0;
	int	pop;

	scanf("%d", &n);
	scanf("%d", &m);

	connect = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
		connect[i] = calloc(n, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		connect[x - 1][y - 1] = 1;
		connect[y - 1][x - 1] = 1;
	}
	stack = calloc(n, sizeof(int));
	visited = calloc(n, sizeof(int));
	stack[idx++] = 0;
	visited[0] = 1;
	while (idx > 0)
	{
		pop = stack[--idx];
		for (int i = 0; i < n; i++)
		{
			if (connect[pop][i] == 1 && visited[i] == 0)
			{
				stack[idx++] = i;
				visited[i] = 1;
				count++;
			}
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < n; i++)
		free(connect[i]);
	free(connect);
	free(stack);
	free(visited);
	return (0);
}
*/
