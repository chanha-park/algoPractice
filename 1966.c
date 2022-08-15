#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct slist
{
	struct slist	*next;
	int				name;
	int				prior;
}	list;

typedef struct sque
{
	list	*head;
	list	*tail;
	int		maxPrior;
	int		numNode;
}	que;

void	en_que(que *printQue, int i, int p)
{
	list	*node = malloc(sizeof(list));

	node->next = NULL;
	node->name = i;
	node->prior = p;

	if (printQue->head)
		printQue->tail->next = node;
	else
		printQue->head = node;
	printQue->tail = node;
	if (printQue->maxPrior < node->prior)
		printQue->maxPrior = node->prior;
	printQue->numNode++;
}

void	update_que(que *printQue)
{
	list	*node = printQue->head;

	printQue->maxPrior = 0;
	while (node)
	{
		if (printQue->maxPrior < node->prior)
			printQue->maxPrior = node->prior;
		node = node->next;
	}
}

void	print_que(que *printQue, int m)
{
	list	*node;
	int		count = 1;

	while (printQue->numNode)
	{
		node = printQue->head;
		printQue->head = node->next;
		if (node->prior == printQue->maxPrior)
		{
			update_que(printQue);
			printQue->numNode--;
			if (node->name == m)
			{
				printf("%d\n", count);
				free(node);
				return ;
			}
			free(node);
			count++;
		}
		else
		{
			printQue->tail->next = node;
			printQue->tail = node;
			node->next = NULL;
		}
	}
}

void	free_que(list *node)
{
	list	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

int	main(void)
{
	que	printQue;
	int	numTest;
	int	n, m, p;

	scanf("%d", &numTest);
	while (numTest--)
	{
		memset(&printQue, 0, sizeof(que));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p);
			en_que(&printQue, i, p);
		}
		print_que(&printQue, m);
		free_que(printQue.head);
	}
	return (0);
}
