#include <stdio.h>

int	get_height(int n)
{
	return ((1 << n) - 1);
}

int	get_width(int n)
{
	return ((1 << (n + 1)) - 3);
}

void	print_count(char c, int count)
{
	while (count--)
	{
		printf("%c", c);
	}
}

void	print_line(int n, int line)
{
}

void	print_(int n)
{
	if (n == 1)
		printf("*\n");
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	print_(n);
	return (0);
}

n = 1 -> 1;

n = 2 -> 3;

n = 3; 1 2 1 2 1; -> 7 -> 13;

n = 4; 1 6 1 6 1; -> 15 -> 29;
