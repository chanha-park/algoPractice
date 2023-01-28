#include <stdio.h>

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%s\n", n % 2 ? "SK" : "CY");
	return (0);
}
