#include <stdio.h>

int	hamming(int n)
{
	int	count = 0;

	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return (count);
}

int	main(void)
{
	int	n, k;
	int	count = 0;
	int	step = 1;

	scanf("%d %d", &n, &k);
	while (hamming(n) > k)
	{
		while ((n & 1) == 0)
		{
			n >>= 1;
			step <<= 1;
		}
		count += step;
		n++;
	}
	printf("%d\n", count);
	return (0);
}
