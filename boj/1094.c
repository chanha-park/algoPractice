#include <stdio.h>

int	main(void)
{
	int	n;
	int	sum = 0;

	scanf("%d", &n);
	while (n > 0)
	{
		sum += n & 1;
		n >>= 1;
	}
	printf("%d\n", sum);
	return (0);
}
