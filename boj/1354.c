#include <stdio.h>

#define SIZE 10000000

long long arr[SIZE];
long long p, q, x, y;

long long f_(long long n)
{
	if (n <= 0)
		return (1);
	if (n >= SIZE)
		return (f_((n / p) - x) + f_((n / q) - y));
	if (n < SIZE && arr[n] == 0)
		arr[n] = f_((n / p) - x) + f_((n / q) - y);
	return (arr[n]);
}

int	main(void)
{
	long long n;

	scanf("%lld %lld %lld %lld %lld", &n, &p, &q, &x, &y);
	printf("%lld\n", f_(n));
	return (0);
}
