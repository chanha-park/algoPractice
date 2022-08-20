#include <stdio.h>
#include <stdlib.h>

// {{{ sol 1

/* typedef struct list                       */
/* {                                         */
/*     struct list	*next;                    */
/*     int			key;                            */
/* }	list;                                   */
/*                                           */
/* int	main(void)                            */
/* {                                         */
/*     int n, m, x;                          */
/*     list	*head, *tail, *node;             */
/*     int	count;                            */
/*                                           */
/*     while (1)                             */
/*     {                                     */
/*         head = tail = NULL;               */
/*         count = 0;                        */
/*         scanf("%d %d", &n, &m);           */
/*         if (n == 0 && m == 0)             */
/*             break ;                       */
/*         for (int i = 0; i < n; i++)       */
/*         {                                 */
/*             scanf("%d", &x);              */
/*             node = malloc(sizeof(list));  */
/*             node->next = NULL;            */
/*             node->key = x;                */
/*             if (head)                     */
/*                 tail->next = node;        */
/*             else                          */
/*                 head = node;              */
/*             tail = node;                  */
/*         }                                 */
/*         for (int i = 0; i < m; i++)       */
/*         {                                 */
/*             scanf("%d", &x);              */
/*             while (head && x > head->key) */
/*             {                             */
/*                 node = head;              */
/*                 if (head == tail)         */
/*                 {                         */
/*                     head = NULL;          */
/*                     tail = NULL;          */
/*                     free(node);           */
/*                     break ;               */
/*                 }                         */
/*                 else                      */
/*                     head = head->next;    */
/*                 free(node);               */
/*             }                             */
/*             if (head && x == head->key)   */
/*             {                             */
/*                 count++;                  */
/*                 node = head;              */
/*                 if (head == tail)         */
/*                 {                         */
/*                     head = NULL;          */
/*                     tail = NULL;          */
/*                 }                         */
/*                 else                      */
/*                     head = head->next;    */
/*                 free(node);               */
/*             }                             */
/*         }                                 */
/*         printf("%d\n", count);            */
/*     }                                     */
/*     return (0);                           */
/* }                                         */

// }}}

// {{{ sol 2

int	main(void)
{
	int	n, m, x, left, right, mid, count;
	int	arr[1000000];

	while (1)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break ;
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		left = 0;
		count = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &x);
			right = n;
			if (arr[right - 1] < x)
				left = n - 1;
			else if (arr[left] > x)
				continue ;
			while (left < right)
			{
				mid = (left + right) / 2;
				if (arr[mid] > x)
					right = mid;
				else
				{
					left = mid + 1;
					if (arr[mid] == x)
					{
						count++;
						break ;
					}
				}
			}
		}
		printf("%d\n", count);
	}
}

// }}}
