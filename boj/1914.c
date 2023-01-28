#include <string.h>
#include <unistd.h>
#include <stdio.h>

void	print_hanoi(int n, int a, int b)
{
	if (n == 1)
	{
		printf("%d %d\n", a, b);
		return ;
	}
	print_hanoi(n - 1, a, 6 - a - b);
	printf("%d %d\n", a, b);
	print_hanoi(n - 1, 6 - a - b, b);
}

void	plus_one(char *a)
{
	if (*a < '9')
		*a += 1;
	else
	{
		*a = '0';
		plus_one(a + 1);
	}
}

void	make_double(char *a)
{
	int	index = 0;
	int	carr = 0;
	int	sum;

	while (a[index])
	{
		sum = 2 * (a[index] - '0') + carr;
		carr = sum / 10;
		a[index++] = '0' + sum % 10;
	}
	if (carr)
		a[index] = '1';
	plus_one(a);
}

void	print_a(char *a)
{
	if (*a == '\0')
		return ;
	print_a(a + 1);
	write(1, a, 1);
}

void	print_count(int n)
{
	char	a[35];
	int		max = 0x7fffffff;
	int		index = 0;

	if (n <= 31)
	{
		printf("%d\n", (1 << n) - 1);
		return ;
	}
	memset(a, 0, 35);
	while (max)
	{
		a[index] = '0' + max % 10;
		max /= 10;
		index++;
	}
	a[index] = '\0';
	while (n > 31)
	{
		make_double(a);
		n--;
	}
	print_a(a);
	printf("\n");
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	print_count(n);
	if (n <= 20)
		print_hanoi(n, 1, 3);
	return (0);
}
