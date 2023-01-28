#include <stdio.h>

static const int	ref[6] = {500, 100, 50, 10, 5, 1};

int	main(void)
{
	int	n;
	int	count = 0;

	scanf("%d", &n);
	n = 1000 - n;
	for (int i = 0; i < 6; i++)
	{
		count += n / ref[i];
		n %= ref[i];
	}
	printf("%d\n", count);
	return (0);
}
