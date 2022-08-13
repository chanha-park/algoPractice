#include <stdio.h>

int	max(int a, int b, int c)
{
	int	max = a;

	if (max < b)
		max = b;
	if (max < c)
		return (c);
	return (max);
}

int	main(void)
{
	int	a,b,c;

	scanf("%d %d %d", &a, &b, &c);
	if (a == b)
	{
		if (b == c)
			printf("%d\n", 10000 + 1000 * a);
		else
			printf("%d\n", 1000 + 100 * b);
	}
	else if (b == c)
		printf("%d\n", 1000 + 100 * b);
	else if (a == c)
		printf("%d\n", 1000 + 100 * a);
	else
		printf("%d\n", 100 * max(a, b, c));
	return (0);
}
