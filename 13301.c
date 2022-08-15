#include <stdio.h>

long long	fibo(int n, long long a, long long b)
{
	if (n == 1)
		return (b);
	return (fibo(n - 1, b, a + b));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%lld\n", 2 * fibo(n + 1, 1, 1));
	return (0);
}
