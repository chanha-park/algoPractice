#include <stdio.h>

int	gcd(int a, int b)
{
	if (a < b)
		return (gcd(b, a));
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int	main(void)
{
	int	a[4];
	int	x, y;
	int	g;

	scanf("%d %d", &a[0], &a[1]);
	scanf("%d %d", &a[2], &a[3]);

	x = a[0] * a[3] + a[1] * a[2];
	y = a[1] * a[3];
	g = gcd(x, y);
	printf("%d %d\n", x / g, y / g);
	return (0);
}
