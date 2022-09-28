#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

int	main(void)
{
	int	n, m;
	long	*arr;
	int		tmp;
	int		count = 0;

	scanf("%d %d", &n, &m);
	arr = malloc(sizeof(long) * (n + 1));
	arr[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arr[i + 1] = arr[i] + tmp;
	}
	for (int i = 1; i < n + 1; i++)
	{
		tmp = arr[i] - m;
		if (bsearch((const void *)&tmp, arr, i, sizeof(int), cmp))
			count++;
	}
	printf("%d\n", count);
	return (0);
}
