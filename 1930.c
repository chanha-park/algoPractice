#include <stdio.h>
#include <stdlib.h>

int	state(int *arr)
{
	return ((arr[0] < arr[1]) + (arr[1] < arr[2]) + (arr[2] < arr[0]));
}

void	rotate(int *arr)
{
	int	temp;

	temp = arr[1];
	arr[1] = arr[2];
	arr[2] = arr[3];
	arr[3] = temp;
}

void	swap(int *arr)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

int	is_side_same(int *a, int *b)
{
	int	flag;

	flag = 1;
	for (int i = 1; i < 4 && flag == 1; i++)
	{
		if (a[i] != b[i])
			flag = 0;
	}
	if (flag == 1)
		return (1);
	rotate(b);
	flag = 1;
	for (int i = 1; i < 4 && flag == 1; i++)
	{
		if (a[i] != b[i])
			flag = 0;
	}
	if (flag == 1)
		return (1);
	rotate(b);
	flag = 1;
	for (int i = 1; i < 4 && flag == 1; i++)
	{
		if (a[i] != b[i])
			flag = 0;
	}
	if (flag == 1)
		return (1);
}

int	is_same(int *a, int *b)
{
	int	i = 0;

	while (i < 4)
	{
		if (a[0] == b[i])
			break ;
		i++;
	}
	if (i == 4)
		return (0);
	if (i == 0)
		return (is_side_same(a, b));
	while (i-- > 1)
		rotate(b);
	swap(b);
	return (1 - is_side_same(a, b));
}

int	main(void)
{
	int	k;
	int	a[4];
	int	b[4];

	scanf("%d", &k);
	while (k--)
	{
		for (int i = 0; i < 4; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < 4; i++)
			scanf("%d", &b[i]);
		printf("%d\n", is_same(a, b));
	}
	return (0);
}
