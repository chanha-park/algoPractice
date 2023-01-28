#include <stdio.h>

int    main(void)
{
	long    n;

	scanf("%ld", &n);
	printf("%ld\n", (n + 1) * n * (n - 1) / 2);
	return (0);
}
