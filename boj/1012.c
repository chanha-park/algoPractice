#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int	x;
	int	y;
}	plant;

void	dfs(int (*arr)[50], int m, int n, int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return ;
	if (arr[x][y] == 0)
		return ;
	arr[x][y] = 0;
	dfs(arr, m, n, x + 1, y);
	dfs(arr, m, n, x - 1, y);
	dfs(arr, m, n, x, y + 1);
	dfs(arr, m, n, x, y - 1);
}

void	testcase(void)
{
	int	m, n, k, x, y;
	int	(*arr)[50];
	plant	*stack;
	plant	pop;
	int	stack_idx = 0;
	int	count = 0;

	scanf("%d %d %d", &m, &n, &k);
	stack = calloc(k, sizeof(plant));
	arr = calloc(m, sizeof(int [50]));
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		stack[stack_idx++] = (plant){x, y};
	}
	while (stack_idx > 0)
	{
		pop = stack[--stack_idx];
		if (arr[pop.x][pop.y] == 1)
		{
			dfs(arr, m, n, pop.x, pop.y);
			count++;
		}
	}
	printf("%d\n", count);
	free(arr);
	free(stack);
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	while (t--)
	{
		testcase();
	}
	return (0);
}
