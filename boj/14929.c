#include <stdio.h>

int	main(void)
{
	long long sum = 0;
	long long square_sum = 0;
	int	n, x;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		sum += x;
		square_sum += x * x;
	}
	printf("%lld\n", ((sum * sum) - square_sum) / 2);
	return (0);
}
