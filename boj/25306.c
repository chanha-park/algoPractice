#include <stdio.h>

typedef unsigned long long	ull;

int	get_max_digit(ull n)
{
	ull	max = (ull)1 << 63;
	int	i = 63;

	while (i > 0)
	{
		if (max & n)
			break ;
		max >>= 1;
		i--;
	}
	return (i);
}

ull	count_(ull n, int i)
{
	int	max_digit = get_max_digit(n);
	ull	count;
	ull	diff;

	if (n == 0)
		return (0);
	if (i > max_digit)
		return (0);
	if (i == 0)
		return ((1 + n) >> 1);
	diff = n & (~((ull)1 << max_digit));
	if (i == max_digit)
		return (diff + 1);
	count = 1 << (max_digit - 1);
	count += count_(diff, i);
	return (count);
}

ull	calc(ull a, ull b)
{
	ull	r = 0;

	for (int i = 0; i <= 63; i++)
	{
		if ((count_(b, i) - count_(a - 1, i)) % 2)
			r |= (ull)1 << i;
	}
	return (r);
}

int	main(void)
{
	ull	a, b;

	scanf("%lld %lld", &a, &b);
	printf("%lld\n", calc(a, b));
	return (0);
}
