#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

void	dfs(char **map, int n, int i, int j, int *count)
{
	if (i < 0 || j < 0 || i >= n || j >= n)
		return ;
	if (map[i][j] == '0')
		return ;
	*count += 1;
	map[i][j] = '0';
	dfs(map, n, i + 1, j, count);
	dfs(map, n, i - 1, j, count);
	dfs(map, n, i, j + 1, count);
	dfs(map, n, i, j - 1, count);
}

int	main(void)
{
	int	n;
	int	count;
	char	**map;
	int	*stack;
	int	stack_idx = 0;

	scanf("%d", &n);
	map = malloc(sizeof(char *) * (n + 1));
	stack = malloc(sizeof(int) * n * n);
	for (int i = 0; i < n; i++)
	{
		map[i] = malloc(sizeof(char) * (n + 1));
		scanf("%s", map[i]);
	}
	map[n] = NULL;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count = 0;
			if (map[i][j] == '1')
				dfs(map, n, i, j, &count);
			if (count > 0)
				stack[stack_idx++] = count;
		}
	}
	qsort(stack, stack_idx, sizeof(int), cmp);
	printf("%d\n", stack_idx);
	for (int i = 0; i < stack_idx; i++)
		printf("%d\n", stack[i]);
	for (int i = 0; i < n; i++)
		free(map[i]);
	free(map);
	free(stack);
	return (0);
}
