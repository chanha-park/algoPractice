#include <stdio.h>

int	f_(int h, int y)
{
	int	t0, t1;

	if (y < 1)
		return (h);
	t0 = f_(h + h / 20, y - 1);
	if (y < 3)
		return (t0);
	t1 = f_(h + h / 5, y - 3);
	t0 = t0 > t1 ? t0 : t1;
	if (y < 5)
		return (t0);
	t1 = f_(h + (7 * h) / 20, y - 5);
	return (t0 > t1 ? t0 : t1);
}

int	main(void)
{
	int	h, y, total;

	scanf("%d %d", &h, &y);
	total = f_(h, y);
	printf("%d\n", total);
	return (0);
}
