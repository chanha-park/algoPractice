#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list
{
	int	x;
	int	y;
	int	z;
	int	depth;
}	t_list;

typedef struct
{
	t_list	*arr;
	int		head;
	int		tail;
}	t_que;

int	raw_count = 0;

void	enque(t_que *que, int x, int y, int z, int depth)
{
	que->arr[que->tail].x = x;
	que->arr[que->tail].y = y;
	que->arr[que->tail].z = z;
	que->arr[que->tail].depth = depth;
	que->tail = (que->tail + 1) % 1000000;
}

t_list	deque(t_que *que)
{
	t_list	ret = que->arr[que->head];

	que->head = (que->head + 1) % 1000000;
	return (ret);
}

int	is_raw(int map[100][100][100], int m, int n, int h, int x, int y, int z)
{
	if (x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= h)
		return (0);
	return (map[x][y][z] == 0);
}

void	bfs_inner(int map[100][100][100], int m, int n, int h, int x, int y, int z, int depth, t_que *que)
{
	if (is_raw(map, m, n, h, x, y, z))
	{
		raw_count--;
		map[x][y][z] = 1;
		enque(que, x, y, z, depth);
	}
}

int	bfs(int map[100][100][100], int m, int n, int h, t_que *que)
{
	int	max_depth = 0;
	t_list	tmp;

	while (que->head != que->tail)
	{
		tmp = deque(que);
		if (max_depth < tmp.depth)
			max_depth = tmp.depth;
		bfs_inner(map, m, n, h, tmp.x + 1, tmp.y, tmp.z, tmp.depth + 1, que);
		bfs_inner(map, m, n, h, tmp.x, tmp.y + 1, tmp.z, tmp.depth + 1, que);
		bfs_inner(map, m, n, h, tmp.x, tmp.y, tmp.z + 1, tmp.depth + 1, que);
		bfs_inner(map, m, n, h, tmp.x - 1, tmp.y, tmp.z, tmp.depth + 1, que);
		bfs_inner(map, m, n, h, tmp.x, tmp.y - 1, tmp.z, tmp.depth + 1, que);
		bfs_inner(map, m, n, h, tmp.x, tmp.y, tmp.z - 1, tmp.depth + 1, que);
	}
	if (raw_count > 0)
		return (-1);
	return (max_depth);
}

int	main(void)
{
	int	m, n, h;
	int	map[100][100][100];
	t_que	que;

	scanf("%d %d %d", &m, &n, &h);
	que.arr = malloc(sizeof(t_list) * 1000000);
	que.head = 0;
	que.tail = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 0)
					raw_count++;
				else if (map[i][j][k] == 1)
					enque(&que, i, j, k, 0);
			}
		}
	}
	printf("%d\n", bfs(map, n, m, h, &que));
	return (0);
}
