#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, m, x, min, max;
	int	d = 0;
	int	arr[20001] = {0,};
	int	*ptr = arr + 10000;
	int	count;

	min = 2147483647;
	max = -2147483648;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		*(ptr + x) += 1;
		if (min > x)
			min = x;
		if (max < x)
			max = x;
	}
	count = m;
	for (int i = min; i <= max; i++)
	{
		if (*(ptr + i))
		{
			if (count == m)
				d += 2 * abs(i);
			count--;
			if (count == 0)
				count = m;
		}
		if (i == 0)
			count = m;
	}
	if (min + max > 0)
		d -= max;
	else
		d += min;
	printf("%d\n", d);
	return (0);
}
