#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int	arr[10000];
	int	head;
	int	tail;
}	t_que;

void	enque(t_que *que, int n)
{
	que->arr[que->tail] = n;
	que->tail = (que->tail + 1) % 10000;
}

int	deque(t_que *que)
{
	int	ret = que->arr[que->head];
	que->head = (que->head + 1) % 10000;
	return (ret);
}

void	update(int **mat, int n, t_que *que, int tmp)
{
	int	flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (mat[tmp][i] == 1)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[tmp][j] == 0 && mat[i][j] == 1)
				{
					flag = 1;
					mat[tmp][j] = 1;
				}
			}
		}
	}
	if (flag)
		enque(que, tmp);
}

void	check(int **mat, int n)
{
	t_que	que;
	int		tmp;

	memset(&que, 0, sizeof(t_que));
	for (int i = 0; i < n; i++)
		enque(&que, i);
	while (que.head != que.tail)
	{
		tmp = deque(&que);
		update(mat, n, &que, tmp);
	}
}

int	main(void)
{
	int	n;
	int	**mat;

	scanf("%d", &n);
	mat = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		mat[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}
	check(mat, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return (0);
}
