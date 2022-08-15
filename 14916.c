#include <stdio.h>

int	ans(int n)
{
	int	temp;

	if (n % 5 == 0)
		return (n / 5);
	if (n < 10)
	{
		if (n % 2 == 0)
			return (n / 2);
		if (n == 7 || n == 9)
			return (n / 2 - 1);
		return (-1);
	}
	temp = ans(n - 5 * (n / 5) + 5);
	if (temp < 0)
		return (temp);
	temp += n / 5 - 1;
	return (temp);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", ans(n));
	return (0);
}
