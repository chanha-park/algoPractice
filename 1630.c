#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	struct list	*next;
	int			data;
}	list;

typedef struct plist
{
	list	*head;
	list	*tail;
}	plist;

list	*new_node(int data)
{
	list	*node = malloc(sizeof(list));

	node->next = NULL;
	node->data = data;
	return (node);
}

void	add_prime(plist *primes, int p)
{
	list	*node = new_node(p);

	primes->tail->next = node;
	primes->tail = node;
}

int	is_prime(plist *primes, int n)
{
	list	*curr;

	if (n > primes->tail->data)
	{
		curr = primes->head;
		while (curr->data <= n / curr->data)
		{
			if (n % curr->data == 0)
				return (0);
		}
		return (1);
	}
	else
	{
	}
}

int	oms(int n)
{
	plist	primes;
	int	mod9 = mod289 = mod379721 = 1;

	primes->head = new_node(2);
	primes->tail = primes->head;
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", oms(n));
	return (0);
}
