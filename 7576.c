#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int	x;
	int	y;
	int	depth;
	struct list	*next;
}	t_list;

typedef struct
{
	t_list	*head;
	t_list	*tail;
}	t_que;

int	raw_count = 0;

t_list	*new_node(int x, int y, int depth)
{
	t_list	*node = malloc(sizeof(t_list));

	node->x = x;
	node->y = y;
	node->depth = depth;
	node->next = NULL;
	return (node);
}

void	enque(t_que *que, t_list *node)
{
	if (que->head)
		que->tail->next = node;
	else
		que->head = node;
	que->tail = node;
}

t_list	*deque(t_que *que)
{
	t_list	*tmp;

	tmp = que->head;
	if (que->head)
	{
		que->head = que->head->next;
		tmp->next = NULL;
	}
	return (tmp);
}

int	is_raw(int **map, int m, int n, int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return (0);
	return (map[x][y] == 0);
}

int	bfs(int **map, int m, int n, t_que *que)
{
	int	max_depth = 0;
	t_list	*tmp;

	while (que->head)
	{
		tmp = deque(que);
		if (max_depth < tmp->depth)
			max_depth = tmp->depth;
		if (is_raw(map, m, n, tmp->x + 1, tmp->y))
		{
			raw_count--;
			map[tmp->x + 1][tmp->y] = 1;
			enque(que, new_node(tmp->x + 1, tmp->y, tmp->depth + 1));
		}
		if (is_raw(map, m, n, tmp->x, tmp->y + 1))
		{
			raw_count--;
			map[tmp->x][tmp->y + 1] = 1;
			enque(que, new_node(tmp->x, tmp->y + 1, tmp->depth + 1));
		}
		if (is_raw(map, m, n, tmp->x - 1, tmp->y))
		{
			raw_count--;
			map[tmp->x - 1][tmp->y] = 1;
			enque(que, new_node(tmp->x - 1, tmp->y, tmp->depth + 1));
		}
		if (is_raw(map, m, n, tmp->x, tmp->y - 1))
		{
			raw_count--;
			map[tmp->x][tmp->y - 1] = 1;
			enque(que, new_node(tmp->x, tmp->y - 1, tmp->depth + 1));
		}
		free(tmp);
	}
	if (raw_count > 0)
		return (-1);
	return (max_depth);
}

int	main(void)
{
	int	m, n;
	int	**map;
	t_que	que;

	scanf("%d %d", &m, &n);
	map = malloc(sizeof(int *) * n);
	que.head = NULL;
	que.tail = NULL;
	for (int i = 0; i < n; i++)
	{
		map[i] = malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				raw_count++;
			else if (map[i][j] == 1)
				enque(&que, new_node(i, j, 0));
		}
	}
	printf("%d\n", bfs(map, n, m, &que));
	for (int i = 0; i < n; i++)
		free(map[i]);
	free(map);
	/* system("leaks $PPID"); */
	return (0);
}
