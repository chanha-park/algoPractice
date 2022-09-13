#include <stdio.h>

int	is_prime(int n)
{
	if (n == 1)
		return (0);
	for (int i = 2; i <= n / i; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

void	testcase(void)
{
	int	n;
	int	count;

	scanf("%d", &n);
	for (int p = 2; p <= n; p++)
	{
		if (is_prime(p))
		{
			count = 0;
			while (n % p == 0)
			{
				n /= p;
				count++;
			}
			if (count > 0)
				printf("%d %d\n", p, count);
		}
	}
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	while (t--)
		testcase();
	return (0);
}
