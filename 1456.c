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

const int	arr[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

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

int	count_pseudo(long a, long b, long p)
{
	long	curr = p;
	float	a_d = (float)a / p;
	float	b_d = (float)b / p;
	int		count = 0;

	while (curr < a_d)
		curr *= p;
	while (curr <= b_d)
	{
		b_d /= p;
		count++;
	}
	return (count);
}

int	main(void)
{
	long a, b;
	int	count;
	t_primes	primes;


	scanf("%ld %ld", &a, &b);
	primes.head = malloc(sizeof(t_list));
	primes.head->next = NULL;
	primes.head->data = 2;
	primes.tail = primes.head;
	count = count_pseudo(a, b, 2);
	for (int i = 1; i < 26; i++)
	{
		add_prime(&primes, arr[i]);
		count += count_pseudo(a, b, arr[i]);
	}
	for (int i = 103; i <= b / (long)i; i += 2)
	{
		if (is_prime(primes, i))
		{
			add_prime(&primes, i);
			count += count_pseudo(a, b, i);
		}
	}
	printf("%d\n", count);
	return (0);
}
