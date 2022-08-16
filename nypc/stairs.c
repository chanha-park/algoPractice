#include <stdio.h>

int	f_(int m, int n)
{
	if (n % (m - 1))
		return (1 + n / (m - 1));
	else
		return (n / (m - 1));
}

int	main(void)
{
	int	m, f, n;

	scanf("%d %d %d", &m, &f, &n);
	printf("%d\n", f_(m, n));
	return (0);
}
