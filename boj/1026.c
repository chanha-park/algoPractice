#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, x, i, j;
	int	sum = 0;
	int	*a = calloc(101, sizeof(int));
	int	*b = calloc(101, sizeof(int));

	scanf("%d", &n);
	i = 0;
	j = 0;
	while (i < n)
	{
		scanf("%d", &x);
		a[100 - x] += 1;
		i++;
	}
	while (i)
	{
		scanf("%d", &x);
		b[x] += 1;
		i--;
	}
	while (n--)
	{
		while (i < 101 && a[i] == 0)
			i++;
		while (j < 101 && b[j] == 0)
			j++;
		sum += (100 - i) * j;
		a[i] -= 1;
		b[j] -= 1;
	}
	printf("%d\n", sum);
	free(a);
	free(b);
	return (0);
}
