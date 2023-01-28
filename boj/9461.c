#include <stdio.h>

// f_(n) = f_(n - 1) + f_(n - 5);

long long	f_(long long n, long long a, long long b, long long c, long long d, long long e)
{
	if (n == 1)
		return (a);
	if (n == 2)
		return (b);
	if (n == 3)
		return (c);
	if (n == 4)
		return (d);
	if (n == 5)
		return (e);
	return (f_(n - 1, b, c, d, e, a + e));
}

int	main(void)
{
	long long	t, n;

	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		printf("%lld\n", f_(n, 1, 1, 1, 2, 2));
	}
	return (0);
}
