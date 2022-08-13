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

int	get_exp(int n, int p)
{
	int	count = 0;

	while (p <= n)
	{
		n /= p;
		count += 1;
	}
	return (count);
}

int	crt(int a, int b, int c)
{
	int	r = c;

	while (r % 289 != b)
		r = (r + 379721) % 987654321;
	while (r % 9 != a)
		r = (r + 109739369) % 987654321;
	return (r % 987654321);
}

int	oms(int n)
{
	plist	primes;
	long long	mod9, mod289, mod379721;
	int	exp;

	if (n < 3)
		return (n);
	if (n == 3)
		return (6);
	if (n >= 379721)
		return (0);
	mod9 = mod289 = mod379721 = 1;
	primes.head = new_node(2);
	primes.tail = primes.head;
	exp = get_exp(n, 2);
	while (exp-- > 0)
	{
		mod9 = (mod9 * 2) % 9;
		mod289 = (mod289 * 2) % 289;
		mod379721 = (mod379721 * 2) % 379721;
	}
	for (int p = 3; p <= n; p += 2)
	{
		if (is_prime(&primes, p))
		{
			add_prime(&primes, p);
			exp = get_exp(n, p);
			while (exp-- > 0)
			{
				mod9 = (mod9 * (p % 9)) % 9;
				mod289 = (mod289 * (p % 289)) % 289;
				mod379721 = (mod379721 * (p % 379721)) % 379721;
			}
		}
	}
	return (crt(mod9, mod289, mod379721));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", oms(n));
	return (0);
}
