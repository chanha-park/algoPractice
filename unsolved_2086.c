#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	arr[7812500] = {0};

# define MOD 1000000000
# define EXP_2 512
# define EXP_5 1953125
# define PERIOD_2 768
# define PERIOD_5 7812500

typedef unsigned long long	ull;

// fibo (39) = 63245986
// fibo(40) = 102334155
// fibo(41) = 165580141

// F1 = F2 = 1;
// S0 = 0;
// Sn = Fn+2 - 1;

int	crt(ull mod2, ull mod5)
{
	ull	n = mod2;

	while (n % PERIOD_5 != mod5)
	{
		n += PERIOD_2;
	}
	return (n);
}

int	fibo(ull n)
{
	ull	mod2, mod5;

	if (n <= 2)
		return (1);
	if (arr[n - 1] == 0)
		arr[n - 1] = (fibo(n - 1) + fibo(n - 2)) % MOD;
	return (arr[n - 1]);
}

int	sum(ull n)
{
	if (n == 0)
		return (0);
	return (fibo(n + 2) - 1);
}

int	main(void)
{
	/* int	fibo_mod2, fibo_mod5; */
	ull	a, b;

	scanf("%lld %lld", &a, &b);
	a %= 6000000000LL;
	b %= 6000000000LL;
	printf("%d\n", fibo(b + 2) - fibo(a + 1));
	return (0);
}
