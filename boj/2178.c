#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int visited[100][100];

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
	newElem->next = NULL;
	return (newElem);
}

void	enque(que *queArr, char **maze, int row, int col, int depth, int n, int m)
{
	node	*elem;

	if (row < 0 || col < 0 || row >= n || col >= m)
		return ;
	if (visited[row][col] == 1)
		return ;
	if (maze[row][col] == '1')
	{
		elem = newNode(row, col, depth);
		if (queArr->head)
			queArr->tail->next = elem;
		else
			queArr->head = elem;
		queArr->tail = elem;
		visited[row][col] = 1;
	}
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

int	is_que_empty(que *queArr)
{
	return (queArr->head == NULL);
}

int	bfs_maze(char **maze, int n, int m)
{
	que	queArr;
	node *tmp;
	int	ans;

	queArr.head = NULL;
	queArr.tail = NULL;

	enque(&queArr, maze, 0, 0, 1, n, m);
	while (!is_que_empty(&queArr))
	{
		tmp = deque(&queArr);
		if (tmp->row + 1 == n && tmp->col + 1 == m)
		{
			ans = tmp->depth;
			free(tmp);
			while (!is_que_empty(&queArr))
				free(deque(&queArr));
			return (ans);
		}
		enque(&queArr, maze, tmp->row + 1, tmp->col, tmp->depth + 1, n, m);
		enque(&queArr, maze, tmp->row - 1, tmp->col, tmp->depth + 1, n, m);
		enque(&queArr, maze, tmp->row, tmp->col + 1, tmp->depth + 1, n, m);
		enque(&queArr, maze, tmp->row, tmp->col - 1, tmp->depth + 1, n, m);
		free(tmp);
	}
	return (-1);
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
	for (int i = 0; i < n; i++)
		free(maze[i]);
	free(maze);
	return (0);
}
