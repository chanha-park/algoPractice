#include <stdlib.h>
#include <stdio.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(int *)a;
	int	y = *(int *)b;

	if (x > y)
		return (1);
	if (x < y)
		return (-1);
	return (0);
}

int	main(void)
{
	int	n;
	int	*orig;
	int	*copy;
	int	*ptr;

	scanf("%d", &n);
	orig = malloc(sizeof(int) * n);
	copy = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &orig[i]);
		copy[i] = orig[i];
	}
	qsort(copy, n, sizeof(int), cmp);
	int	len = 0;
	int	idx = 0;
	while (idx + 1 < n)
	{
		if (copy[idx] != copy[idx + 1])
			copy[len++] = copy[idx];
		idx++;
	}
	copy[len++] = copy[idx];
	for (int i = 0; i < n; i++)
	{
		ptr = bsearch(&orig[i], copy, len, sizeof(int), cmp);
		printf("%lu ", ptr - copy);
	}
	return (0);
}
