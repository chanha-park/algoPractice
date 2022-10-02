#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(long *)a;
	int	y = *(long *)b;

	if (x > y)
		return (1);
	else if (x < y)
		return (-1);
	else
		 return (0);
}

int	main(void)
{
	int	n, m;
	long	*arr;
	long	tmp;
	int		count = 0;

	scanf("%d %d", &n, &m);
	arr = malloc(sizeof(long) * (n + 1));
	arr[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%ld", &tmp);
		arr[i + 1] = arr[i] + tmp;
	}
	for (int i = 1; i < n + 1; i++)
	{
		tmp = arr[i] - m;
		if (bsearch((const void *)&tmp, arr, i, sizeof(long), cmp))
			count++;
	}
	printf("%d\n", count);
	return (0);
}
