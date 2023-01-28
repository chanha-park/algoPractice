#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(int *)a;
	int	y = *(int *)b;

	if (x > y)
		return (1);
	else if (x < y)
		return (-1);
	else
		return (0);
}

int	main(void)
{
	int	*a, *b;
	int	idx_a = 0;
	int	idx_b = 0;
	int	count = 0;
	int	na, nb;

	scanf("%d %d", &na, &nb);
	a = malloc(sizeof(int) * na);
	b = malloc(sizeof(int) * nb);
	for (int i = 0; i < na; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < nb; i++)
		scanf("%d", &b[i]);
	qsort(a, na, sizeof(int), cmp);
	qsort(b, nb, sizeof(int), cmp);
	while (idx_a < na && idx_b < nb)
	{
		if (a[idx_a] > b[idx_b])
		{
			idx_b++;
			count++;
		}
		else if (a[idx_a] < b[idx_b])
		{
			idx_a++;
			count++;
		}
		else
		{
			idx_a++;
			idx_b++;
		}
	}
	while (idx_a++ < na)
		count++;
	while (idx_b++ < nb)
		count++;
	printf("%d\n", count);
	return (0);
}
