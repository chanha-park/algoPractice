#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}	t_list;

typedef struct s_primes
{
	t_list	*head;
	t_list	*tail;
}	t_primes;

void	add_prime(t_primes *primes, int p)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->next = NULL;
	new_node->data = p;
	primes->tail->next = new_node;
	primes->tail = new_node;
}

int	is_prime(t_primes primes, int n)
{
	int	data;

	for (t_list	*curr = primes.head; curr; curr = curr->next)
	{
		data = curr->data;
		if (data > n / data)
			break ;
		if (n % data == 0)
			return (0);
	}
	return (1);
}

void	clear_list(t_primes *primes)
{
	t_list	*head = primes->head;
	t_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	primes->head = NULL;
	primes->tail = NULL;
}

int	main(void)
{
	long 	n;
	long	max;
	t_primes	primes;
	int	count;


	while (1)
	{
		scanf("%ld", &n);
		if (n == 0)
			break ;
		count = n;
		max = n;
		primes.head = malloc(sizeof(t_list));
		primes.head->next = NULL;
		primes.head->data = 2;
		primes.tail = primes.head;
		if (n % 2 == 0)
		{
			count /= 2;
			max /= 2;
		}
		for (int i = 3; i <= max; i += 2)
		{
			if (is_prime(primes, i))
			{
				if (i > primes.tail->data)
					add_prime(&primes, i);
				if (n % i == 0)
				{
					while (max % i == 0)
						max /= i;
					count /= i;
					count *= i - 1;
				}
			}
		}
		printf("%d\n", count);
	}
	clear_list(&primes);
	return (0);
}
