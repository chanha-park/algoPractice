#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	struct node	*next;
	int	row;
	int	col;
	int	depth;
}	node;

typedef struct que
{
	node	*head;
	node	*tail;
}	que;

node	*newNode(int row, int col, int depth)
{
	node	*newElem = malloc(sizeof(node));

	newElem->row = row;
	newElem->col = col;
	newElem->depth = depth;
	return (newElem);
}

void	enque(que *queArr, int row, int col, int depth)
{
	node	*elem;

	elem = newNode(row, col, depth);
	if (queArr->head)
		queArr->tail->next = elem;
	else
		queArr->head = elem;
	queArr->tail = elem;
}

node	*deque(que *queArr)
{
	node	*tmp;

	tmp = queArr->head;
	if (queArr->head == queArr->tail)
	{
		queArr->head = NULL;
		queArr->tail = NULL;
	}
	else
	{
		queArr->head = tmp->next;
	}
	return (tmp);
}

int	bfs_maze(char **maze, int row, int col)
{
	que	queArr;

	que.head = NULL;
	que.tail = NULL;
}

int	main(void)
{
	int	n, m;
	char	**maze;

	scanf("%d %d", &n, &m);
	maze = malloc(sizeof(char *) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		maze[i] = malloc(sizeof(char) * (m + 1));
		scanf("%s", maze[i]);
	}
	maze[n] = NULL;
	printf("%d\n", bfs_maze(maze, n, m));
	return (0);
}
