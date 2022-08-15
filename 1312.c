#include <stdio.h>

int	main(void)
{
	int	a, b, n;
	int	ret;

	scanf("%d %d %d", &a, &b, &n);
	a %= b;
	while (n)
	{
		a *= 10;
		ret = a / b;
		a %= b;
		n--;
	}
	printf("%d\n", ret);
	return (0);
}
