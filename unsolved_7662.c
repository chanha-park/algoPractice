#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	*arr;
	int	size;
	int	cap;
}	heap;

// {{{
/* int	is_empty(heap *que)      */
/* {                            */
/*     return (que->size == 0); */
/* }                            */

/* void	enque_min(heap *que, int data)                                     */
/* {                                                                       */
/*     int	idx;                                                            */

/*     (que->size)++;                                                      */
/*     idx = que->size;                                                    */
/*     while (idx > 1 && data < que->arr[idx / 2])                         */
/*     {                                                                   */
/*         que->arr[idx] = que->arr[idx / 2];                              */
/*         idx >>= 1;                                                      */
/*     }                                                                   */
/*     que->arr[idx] = data;                                               */
/* }                                                                       */

/* void	enque_max(heap *que, int data)                                     */
/* {                                                                       */
/*     int	idx;                                                            */

/*     (que->size)++;                                                      */
/*     idx = que->size;                                                    */
/*     while (idx > 1 && data > que->arr[idx / 2])                         */
/*     {                                                                   */
/*         que->arr[idx] = que->arr[idx / 2];                              */
/*         idx >>= 1;                                                      */
/*     }                                                                   */
/*     que->arr[idx] = data;                                               */
/* }                                                                       */

/* int	deque_min(heap *que)                                                */
/* {                                                                       */
/*     int	root = que->arr[1];                                             */
/*     int	tmp = que->arr[que->size];                                      */
/*     int	parent = 1;                                                     */
/*     int	child = 2;                                                      */

/*     (que->size)--;                                                      */
/*     while (child <= que->size)                                          */
/*     {                                                                   */
/*         if (child < que->size && que->arr[child] > que->arr[child + 1]) */
/*             child++;                                                    */
/*         if (tmp <= que->arr[child])                                     */
/*             break ;                                                     */
/*         que->arr[parent] = que->arr[child];                             */
/*         parent = child;                                                 */
/*         child <<= 1;                                                    */
/*     }                                                                   */
/*     que->arr[parent] = tmp;                                             */
/*     return (root);                                                      */
/* }                                                                       */

/* int	deque_max(heap *que)                                                */
/* {                                                                       */
/*     int	root = que->arr[1];                                             */
/*     int	tmp = que->arr[que->size];                                      */
/*     int	parent = 1;                                                     */
/*     int	child = 2;                                                      */

/*     (que->size)--;                                                      */
/*     while (child <= que->size)                                          */
/*     {                                                                   */
/*         if (child < que->size && que->arr[child] < que->arr[child + 1]) */
/*             child++;                                                    */
/*         if (tmp >= que->arr[child])                                     */
/*             break ;                                                     */
/*         que->arr[parent] = que->arr[child];                             */
/*         parent = child;                                                 */
/*         child <<= 1;                                                    */
/*     }                                                                   */
/*     que->arr[parent] = tmp;                                             */
/*     return (root);                                                      */
/* }                                                                       */
// }}}

void	testcase(void)
{
	int		k;
	heap	que;
	char	c[2];
	int		n;

	scanf("%d", &k);
	que.cap = k;
	que.size = 0;
	que.arr = malloc(sizeof(int) * (k + 1));
	while (k--)
	{
		scanf("%s %d", c, &n);
		if (c[0] == 'I')
		{
			if (max < n)
				max = n;
			enque(&que, n);
		}
		else if (is_empty(&que))
			continue ;
		else if (n == 1)
		{
			deque_max(&que);
		}
		else
			deque_min(&que);
	}
	if (is_empty(&que))
		printf("EMPTY\n");
	else
		printf("%d %d\n", max, min);
	free(que.arr);
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	while (t--)
		testcase();
	return (0);
}
