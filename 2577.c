#include <stdio.h>

int	main(void)
{
	int	a,b,c,n;
	int	arr[10] = {0};

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	n = a * b * c;
	while (n)
	{
		arr[n % 10] += 1;
		n /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
