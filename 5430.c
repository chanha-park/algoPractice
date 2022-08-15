#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	r(int *arr, int n)
{
	int	i = 0;
	int	j = n - 1;
	int	tmp;

	while (i < j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
}

void	print_(int *arr, int n)
{
	if (arr == NULL)
		printf("error\n");
	else
	{
		printf("[");
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				printf("%d", arr[i]);
			else
				printf(",%d", arr[i]);
		}
		printf("]\n");
	}
}

void	operate(int *arr, int n, char *p)
{
	int	flag = 0;

	while (*p)
	{
		if (*p == 'D')
		{
			if (n == 0)
			{
				print_(NULL, n);
				return ;
			}
			if (flag % 2)
				r(arr, n);
			arr++;
			n--;
			flag = 0;
		}
		else
			flag++;
		p++;
	}
	if (flag % 2)
		r(arr, n);
	print_(arr, n);
}

void	test(void)
{
	int		n;
	char	p[100001] = {0};
	char	c = '\0';
	int		*arr;
	int		curr = 0;
	int		idx = 0;

	scanf("%s", p);
	getchar();
	scanf("%d", &n);
	getchar();
	arr = malloc(sizeof(int) * n);
	while (read(0, &c, 1) && c != '\n')
	{
		if (c >= '0' && c <= '9')
			curr = curr * 10 + c - '0';
		else if (c == ',')
		{
			arr[idx++] = curr;
			curr = 0;
		}
	}
	if (n)
		arr[idx] = curr;
	operate(arr, n, p);
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
