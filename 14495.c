#include <stdio.h>

long long	quasi_fibo(int n, long long a, long long b, long long c)
{
	if (n == 1)
		return (a);
	if (n == 2)
		return (b);
	if (n == 3)
		return (c);
	return (quasi_fibo(n - 1, b, c, a + c));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%lld\n", quasi_fibo(n, 1, 1, 1));
	return (0);
}
