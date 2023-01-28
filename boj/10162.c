#include <stdio.h>

int	main(void)
{
	int	t, a, b, c;

	a = b = c = 0;
	scanf("%d", &t);
	if (t % 10)
		printf("-1\n");
	else
	{
		a = t / 300;
		t %= 300;
		b = t / 60;
		t %= 60;
		c = t / 10;
		printf("%d %d %d\n", a, b, c);
	}
	return (0);
}
