#include <stdio.h>
#include <string.h>

# define MOD 1000000000

typedef unsigned long long  ull;

// F1 = F2 = 1;
// S0 = 0;
// Sn = Fn+2 - 1;

ull	fibo(int n, ull a, ull b)
{
	if (n == 1)
		return (a);
	if (n == 2)
		return (b);
	return (fibo(n - 1, b, (a + b) % MOD));
}

ull	sum(int n)
{
	if (n == 0)
		return (0);
	return (fibo(n + 2, 1, 1) - 1);
}

int	main(void)
{
	ull	a, b, x, y;

	scanf("%lld %lld", &a, &b);
	x = sum(a - 1);
	y = sum(b);
	printf("%lld\n", (y - x + MOD) % MOD);
	return (0);
}
