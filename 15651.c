#include <stdio.h>

#define MAX 7

int	n, m;
int	arr[MAX];
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
			idx = tmp;
			arr[idx++] = i;
			recur();
		}
	}
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		idx = 0;
		arr[idx++] = i;
		recur();
	}
	return (0);
}
