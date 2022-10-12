#include <stdio.h>
#include <stdlib.h>

int	n, m;
int	size;
char	*map;
int	count = 0;
int	area;
int	max = 0;

int	*que;
int	head;
int	tail;

void	push(int nbr)
{
	que[tail] = nbr;
	tail = (tail + 1) % (size + 1);
}

int	pop(void)
{
	int	tmp = que[head];

	head = (head + 1) % (size + 1);
	return (tmp);
}

void	bfs(int start, int nbr)
{
	int	tmp;
	int	next;
	int	dir[4] = {1, -1, nbr, -nbr};

	push(start);
	while (head != tail)
	{
		tmp = pop();
		area++;
		for (int i = 0; i < 4; i++)
		{
			if (tmp % m == (m - 1) && i == 0)
				continue;
			if (tmp % m == 0 && i == 1)
				continue;
			if (tmp / m == (n - 1) && i == 2)
				continue;
			if (tmp / m == 0 && i == 3)
				continue;
			next = tmp + dir[i];
			if (map[next] == 1)
			{
				map[next] ^= 1;
				push(next);
			}
		}
	}
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	size = n * m;
	int	tmp;
	map = malloc(sizeof(char) * size);
	que = malloc(sizeof(int) * (size + 1));
	for (int i = 0; i < (size); i++)
	{
		scanf("%d", &tmp);
		map[i] = (char)tmp;
	}
	for (int i = 0; i < (size); i++)
	{
		if (map[i] == 1)
		{
			map[i] ^= 1;
			count++;
			area = 0;
			bfs(i, m);
			if (area > max)
				max = area;
		}
	}
	printf("%d\n%d\n", count ,max);
	return (0);
}
