#include <stdio.h>

int	code1(int n, int a, int b)
{
	if (n <= 2)
		return (b);
	return (code1(n - 1, b, a + b));
}

int	code2(int n)
{
	return (n - 2);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d %d\n", code1(n, 1, 1), code2(n));
	return (0);
}
