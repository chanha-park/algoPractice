#include <stdio.h>

#define MAX 8

int	n, m;
int	arr[MAX];
int	visited[MAX];
int	idx;

void	recur()
{
	int	tmp;
	int	curr;

	if (idx == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		tmp = idx;
		curr = arr[tmp - 1];
		for (int i = 1; i <= n; i++)
		{
			if (visited[i - 1] == 0)
			{
				idx = tmp;
				visited[i - 1] = 1;
				arr[idx++] = i;
				recur();
				visited[i - 1] = 0;
			}
		}
	}
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		idx = 0;
		visited[i - 1] = 1;
		arr[idx++] = i;
		recur();
		visited[i - 1] = 0;
	}
	return (0);
}
