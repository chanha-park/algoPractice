#include <stdio.h>

int	main(void)
{
	int	n, r, c;
	long long	k, mask;

	scanf("%d %d %d", &n, &r, &c);
	k = 0;
	while (n > 1)
	{
		mask = 1 << (n - 1);
		if (r & mask)
			k += 2 * mask * mask;
		if (c & mask)
			k += mask * mask;
		n--;
		r %= mask;
		c %= mask;
	}
	printf("%lld\n", k + 2 * r + c);
	return (0);
}
