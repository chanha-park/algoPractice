#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int	start;
	int	end;
	int	cost;
}	edge;

typedef struct
{
	int	cost;
	int	connected;
}	graph;

typedef struct
{
	edge	*arr;
	int		size;
}	heap;

int	cmp(edge a, edge b)
{
	if (a.cost > b.cost)
		return (1);
	else if (a.cost < b.cost)
		return (-1);
	else
		return (0);
}

void	enque(heap *que, edge elem)
{
	int	i;

	(que->size)++;
	i = que->size;
	while (i > 1 && cmp(elem, que->arr[i / 2]) < 0)
	{
		que->arr[i] = que->arr[i / 2];
		i >>= 1;
	}
	que->arr[i] = elem;
}

edge	deque(heap *que)
{
	edge	root = que->arr[1];
	edge	tmp = que->arr[que->size];
	int		parent = 1;
	int		child = 2;
	(que->size)--;
	while (child <= que->size)
	{
		if (child < que->size && cmp(que->arr[child], que->arr[child + 1]) > 0)
			child++;
		if (cmp(tmp, que->arr[child]) <= 0)
			break ;
		que->arr[parent] = que->arr[child];
		parent = child;
		child <<= 1;
	}
	que->arr[parent] = tmp;
	return (root);
}

int	is_heap_empty(heap *que)
{
	return (que->size == 0);
}

heap	init_heap(int max_size)
{
	heap	que;

	que.size = 0;
	que.arr = malloc(sizeof(edge) * (max_size + 1));
	return (que);
}

int	dijkstra(graph **map, int n, int start, int end)
{
	heap	edge_heap = init_heap(n);
	graph	*min_cost = malloc(sizeof(graph) * n);
	edge	tmp;
	int		ret;

	memmove(min_cost, map[start], sizeof(graph) * n);
	for (int i = 0; i < n; i++)
	{
		if (min_cost[i].connected == 1)
			enque(&edge_heap, (edge){start, i, min_cost[i].cost});
	}

	while (!is_heap_empty(&edge_heap))
	{
		tmp = deque(&edge_heap);
		if (min_cost[tmp.end].cost < tmp.cost)
			continue ;
		for (int i = 0; i < n; i++)
		{
			if (map[tmp.end][i].connected == 1)
			{
				if (min_cost[i].connected == 0 || (min_cost[i].cost > min_cost[tmp.end].cost + map[tmp.end][i].cost))
				{
					min_cost[i].cost = min_cost[tmp.end].cost + map[tmp.end][i].cost;
					enque(&edge_heap, (edge){start, i, min_cost[i].cost});
				}
				min_cost[i].connected = 1;
			}
		}
	}

	ret = min_cost[end].cost;

	free(edge_heap.arr);
	free(min_cost);
	return (ret);
}

int	main(void)
{
	int	n, m, start, end, cost;
	graph	**map;

	scanf("%d", &n);
	scanf("%d", &m);
	map = malloc(sizeof(graph *) * n);
	for (int i = 0; i < n; i++)
		map[i] = calloc(n, sizeof(graph));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &start, &end, &cost);
		if (map[start - 1][end - 1].connected == 0 || cost < map[start - 1][end - 1].cost)
			map[start - 1][end - 1].cost = cost;
		map[start - 1][end - 1].connected = 1;
	}
	scanf("%d %d", &start, &end);
	printf("%d\n", dijkstra(map, n, start - 1, end - 1));
	system("leaks $PPID");
	return (0);
}
