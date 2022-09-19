#include <stdio.h>
#include <stdlib.h>

int	n, m;
int	*arr;
int	*ref;
int	idx;

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

void	recur()
{
	int	tmp;
	int	curr;

	if (idx == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", ref[arr[i]]);
		printf("\n");
	}
	else
	{
		tmp = idx;
		curr = arr[tmp - 1];
		for (int i = curr; i < n; i++)
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
	arr = malloc(sizeof(int) * m);
	ref = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ref[i]);
	qsort(ref, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++)
	{
		idx = 0;
		arr[idx++] = i;
		recur();
	}
	return (0);
}
