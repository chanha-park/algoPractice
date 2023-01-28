#include <stdio.h>
#include <stdlib.h>

/* typedef struct s_list                                          */
/* {                                                              */
/*     struct s_list	*next;                                       */
/*     int				data;                                               */
/* }	t_list;                                                      */

/* typedef struct s_primes                                        */
/* {                                                              */
/*     t_list	*head;                                              */
/*     t_list	*tail;                                              */
/* }	t_primes;                                                    */

/* void	add_prime(t_primes *primes, int p)                        */
/* {                                                              */
/*     t_list	*new_node;                                          */

/*     new_node = malloc(sizeof(t_list));                         */
/*     new_node->next = NULL;                                     */
/*     new_node->data = p;                                        */
/*     primes->tail->next = new_node;                             */
/*     primes->tail = new_node;                                   */
/* }                                                              */

/* int	is_prime(t_primes *primes, int n)                          */
/* {                                                              */
/*     int	data;                                                  */

/*     for (t_list	*curr = primes->head; curr; curr = curr->next) */
/*     {                                                          */
/*         data = curr->data;                                     */
/*         if (data > n / data)                                   */
/*             break ;                                            */
/*         if (n % data == 0)                                     */
/*             return (0);                                        */
/*     }                                                          */
/*     return (1);                                                */
/* }                                                              */

/* void	delete_prime(t_primes *primes)                            */
/* {                                                              */
/*     t_list *node = primes->head;                               */
/*     t_list *tmp;                                               */

/*     while (node)                                               */
/*     {                                                          */
/*         tmp = node;                                            */
/*         node = node->next;                                     */
/*         free(tmp);                                             */
/*     }                                                          */
/*     primes->head = NULL;                                       */
/*     primes->tail = NULL;                                       */
/* }                                                              */

/* void	test(void)                           */
/* {                                         */
/*     int	n;                                */
/*     t_primes primes = {NULL, NULL};       */

/*     scanf("%d", &n);                      */
/*     primes.head = malloc(sizeof(t_list)); */
/*     primes.head->data = 2;                */
/*     primes.head->next = NULL;             */
/*     primes.tail = primes.head;            */
/*     for (int i = 3; i <= n; i += 2)       */
/*     {                                     */
/*         if (is_prime(&primes, i))         */
/*             add_prime(&primes, i);        */
/*     }                                     */
/*     int	prev = primes.tail->data;         */
/*     while (!is_prime(&primes, n))         */
/*         n++;                              */
/*     printf("%d\n", n - prev);             */
/*     delete_prime(&primes);                */
/* }                                         */

int	is_prime(int n)
{
	if (n == 1)
		return (0);
	if (n <= 3)
		return (1);
	if (n % 2 == 0)
		return (0);
	for (int i = 3; i <= n / i; i += 2)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

void	test(void)
{
	int	n;

	scanf("%d", &n);
	int	prev = n;

	while (!is_prime(prev))
		prev--;
	if (n == prev)
		printf("0\n");
	else
	{
		int	next = n + 1;
		while (!is_prime(next))
			next++;
		printf("%d\n", next - prev);
	}
}

int main(void) {
  int t;

  scanf("%d", &t);
  while (t--)
	  test();
  return (0);
}
