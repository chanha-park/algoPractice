#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	ro, ri;

	scanf("%d %d", &ro, &ri);
	printf("%d\n", (ro * ro) - (2 * ro * ri));
	return (0);
}
