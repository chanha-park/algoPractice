#include <stdio.h>

int	main(void)
{
	int	n;
	long long	prod = 1;

	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		prod *= i;
		while (prod % 10 == 0)
			prod /= 10;
		prod %= 1000000000000L;
	}
	prod %= 100000;
	printf("%.5lld\n", prod);
	return (0);
}
