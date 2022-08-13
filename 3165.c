#include <stdio.h>

int	count5(long long n)
{
	int	count = 0;

	while (n)
	{
		if (n % 10 == 5)
			count++;
		n /= 10;
	}
	return (count);
}

long long	find5(long long n, int k)
{
	int	count = count5(n);

	if (count >= k)
		return (n);
	if ((n / 10) % 10 != 5)
	{
		while (n % 5 != 0)
			n++;
		count = count5(n);
		if (count >= k)
			return (n);
		return (10 * find5(n / 10, k - 1) + 5);
	}
	if (n % 10 == 5)
	{
		return (100 * find5(n / 100, k - 2) + 55);
	}
	else
	{
		int	temp;
		if (k > 3)
		{
			temp = 100 * find5(n / 100, k - 2);
			if (temp >= n && count5(temp) >= k)
				return (temp);
			return (temp + 55);
		}
		else
		{
			if (n % 10 <= 5)
				return (10 * (n / 10) + 5);
			n = 100 * (n / 100 + 1);
			count = count5(n);
			if (count >= k)
				return (n);
			else
				return (n + 55);
		}
	}
}

int	main(void)
{
	long long	n;
	int	k;

	scanf("%lld %d", &n, &k);
	printf("%lld\n", find5(n + 1, k));
	return (0);
}
