#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, m, x, y;
	int	**connect;
	int	*stack;
	int	*visited;
	int	count = 0;
	int	idx = 0;
	int	pop;
	int	start = 0;

	scanf("%d %d", &n, &m);

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
	while (1)
	{
		while (start < n && visited[start] == 1)
			start++;
		if (start == n)
			break ;
		count++;
		stack[idx++] = start;
		visited[start] = 1;
		while (idx > 0)
		{
			pop = stack[--idx];
			for (int i = 0; i < n; i++)
			{
				if (connect[pop][i] == 1 && visited[i] == 0)
				{
					stack[idx++] = i;
					visited[i] = 1;
				}
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
