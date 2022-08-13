#include <stdio.h>

int	f(int n)
{
	if (n % 2)
		return (0);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", f(n));
}
