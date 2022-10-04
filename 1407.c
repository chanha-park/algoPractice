#include <stdio.h>

long long	f(long long n)
{
	long long	x = 1;
	long long	sum = 0;

	while (x <= n)
		x <<= 1;
	while (x > 1)
	{
		x >>= 1;
		sum += x * ((n / x + (n / x) % 2) / 2);
	}
	return (sum);
}

int	main(void)
{
	long long	a, b;

	scanf("%lld %lld", &a, &b);
	printf("%lld\n", f(b) - f(a - 1));
	return (0);
}
