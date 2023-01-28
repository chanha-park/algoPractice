#include <stdio.h>

int	main(void)
{
	int	a, b, c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (a + b + c == 180)
	{
		if (a == b)
		{
			if (b == c)
				printf("Equilateral\n");
			else
				printf("Isosceles\n");
		}
		else if (a == c)
		{
			if (b == c)
				printf("Equilateral\n");
			else
				printf("Isosceles\n");
		}
		else if (b == c)
			printf("Isosceles\n");
		else
			printf("Scalene\n");
	}
	else
		printf("Error\n");
	return (0);
}
