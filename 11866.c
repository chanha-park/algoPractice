#include <stdio.h>
#include <stdlib.h>

typedef struct listType
{
	int	data;
	struct listType	*prev;
	struct listType	*next;
}	list;

void	remove_lst(list **head, list *temp)
{
	if (*head == temp)
	{
		*head = (*head)->next;
		if (*head == temp)
			*head = NULL;
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	printf("%d", temp->data);
}

int	main(void)
{
	int	n, k, i;
	list	*head = NULL;
	list	*tail = NULL;
	list	*temp;

	scanf("%d %d", &n, &k);
	i = 1;
	while (i <= n)
	{
		temp = malloc(sizeof(list));
		temp->data = i;
		temp->prev = NULL;
		temp->next = NULL;
		if (head)
		{
			tail->next = temp;
			temp->prev = tail;
		}
		else
		{
			head = temp;
		}
		tail = temp;
		i++;
	}
	tail->next = head;
	head->prev = tail;
	temp = head;
	i = 1;
	printf("<");
	while (head)
	{
		if (i % k == 0)
		{
			remove_lst(&head, temp);
			i = 0;
			if (head)
				printf(", ");
		}
		i++;
		temp = temp->next;
	}
	printf(">\n");
}
