#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	k, n;
	int	*arr;
	int	j;
	int	step;
	char	c;

	scanf("%d", &k);
	n = (1 << k) - 1;
	arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < k; i++)
	{
		j = -1;
		step = 1 << (k - i - 1);
		c = ' ';
		while (j < n)
		{
			if (j + step >= n)
				c = '\n';
			if (arr[j])
			{
				printf("%d%c", arr[j], c);
				arr[j] = 0;
			}
			j += step;
		}
	}
	return (0);
}
