#include <stdio.h>

int	get_last(int n)
{
	int	ans = 1;

	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		while (ans % 10 == 0)
			ans /= 10;
		ans %= 100000;
	}
	return (ans % 10);
}

int	main(void)
{
	int	n;

	while (scanf("%d", &n) > 0)
	{
		printf("%5d -> %d\n", n, get_last(n));
	}
	return (0);
}
