#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_(int *begin, int *end, int sign)
{
	if (sign > 0)
	{
		printf("[");
		while (begin <= end)
		{
			printf("%d", *begin);
			begin++;
			if (begin <= end)
				printf(",");
		}
		printf("]\n");
	}
	else
	{
		printf("[");
		while (begin >= end)
		{
			printf("%d", *begin);
			begin--;
			if (begin >= end)
				printf(",");
		}
		printf("]\n");
	}
}

void	operate(int *begin, int *end, int sign, char *cmd)
{
	if (*cmd)
	{
		if (*cmd == 'R')
		{
			sign *= -1;
			operate(end, begin, sign, cmd + 1);
		}
		else
		{
			if (sign > 0 && begin > end)
				printf("error\n");
			else if (sign < 0 && begin < end)
				printf("error\n");
			else
				operate(begin + sign, end, sign, cmd + 1);
		}
	}
	else
	{
		print_(begin, end, sign);
	}
}

void	test(void)
{
	int		n;
	char	p[100001] = {0};
	int		*arr;

	scanf("%s", p);
	/* getchar(); */
	scanf("%d", &n);
	getchar();
	arr = malloc(sizeof(int) * n);
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (i)
				scanf(",%d", &arr[i]);
			else
				scanf("[%d", &arr[i]);
		}
	}
	else
		scanf("[");
	getchar();
	operate(arr, arr + n - 1, 1, p);
	free(arr);
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	while (t--)
	{
		test();
	}
	return (0);
}
