#include <stdio.h>

int	main(void)
{
	int	a, b, l, r;

	scanf("%d %d", &a, &b);
	l = 0;
	r = 0;
	while (a != 1 && b != 1)
	{
		if (a > b)
		{
			l += a / b;
			a %= b;
		}
		else
		{
			r += b / a;
			b %= a;
		}
	}
	if (a == 1)
		r += b - 1;
	else
		l += a - 1;
	printf("%d %d\n", l, r);
	return (0);
}
