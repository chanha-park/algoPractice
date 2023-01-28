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

	curr = primes->head;
	while (curr && curr->data <= n / curr->data)
	{
		if (n % curr->data == 0)
			return (0);
		curr = curr->next;
	}
	return (1);
}

long long	sol1(long long n)
{
	if (n & 1)
	{
		n >>= 1;
		return (n * n);
	}
	else
	{
		n >>= 1;
		return (n * (n - 1));
	}
}

long long	find_subsum(int *arr, int idx)
{
	int	count = 0;

	for (int i = 0; i < idx; i++)
	{
		for (int j = i; j < idx; j++)
		{
			count += (arr[i] + arr[j] == arr[idx]);
		}
	}
	return (count);
}

long long	sol2(int n)
{
	int	*arr = malloc(sizeof(int) * n);
	int	count = 0;
	long long	ret = 0;

	for (int i = 1; i <= n / i; i++)
	{
		if (n % i == 0)
			arr[count++] = i;
	}
	for (int left = count - 1; left >= 0; left--)
	{
		if (arr[left] != n / arr[left])
			arr[count++] = n / arr[left];
	}
	for (int i = 0; i < count; i++)
		ret += find_subsum(arr, i);
	return (ret);
}

long long	sol3(plist *primes, int n)
{
	int	count = 0;

	for (int p = 3; p <= n; p += 2)
	{
		if (is_prime(primes, p))
		{
			if (primes->tail->data + 2 == p)
				count++;
			add_prime(primes, p);
		}
	}
	return (count);
}

int	main(void)
{
	int		n;
	plist	primes;

	scanf("%d", &n);
	primes.head = new_node(2);
	primes.tail = primes.head;
	printf("%lld\n", sol1(n));
	printf("%lld\n", sol2(n));
	printf("%lld\n", sol3(&primes, n));
	return (0);
}
