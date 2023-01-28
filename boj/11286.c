#include <stdio.h>
#include <stdlib.h>

int	abs_(int n)
{
	return (0 > n ? -n : n);
}

int	cmp(int a, int b)
{
	if (abs_(a) > abs_(b))
	{
		return (1);
	}
	else if (abs_(a) < abs_(b))
	{
		return (-1);
	}
	else
	{
		if (a > b)
			return (1);
		else if (a < b)
			return (-1);
		else
			return (0);
	}
}

void	push_heap(int *heap, int x, int *size)
{
	int	idx;

	*size += 1;
	idx = *size;
	while (idx > 1 && cmp(heap[idx / 2], x) > 0)
	{
		heap[idx] = heap[idx / 2];
		idx /= 2;
	}
	heap[idx] = x;
}

void	pop_heap(int *heap, int *size)
{
	if (*size == 0)
		printf("0\n");
	else
	{
		int	root = heap[1];
		int	temp = heap[*size];
		int	parent = 1;
		int	child = 2;

		*size -= 1;
		while (child <= *size)
		{
			if (child < *size && cmp(heap[child], heap[child + 1]) > 0)
				child++;
			if (cmp(heap[child], temp) >= 0)
				break ;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		printf("%d\n", root);
	}
}

int	main(void)
{
	int	n;
	int	x;
	int	*heap;
	int	size = 0;

	scanf("%d", &n);
	heap = calloc(n + 1, sizeof(int));
	while (n--)
	{
		scanf("%d", &x);
		if (x != 0)
			push_heap(heap, x, &size);
		else
			pop_heap(heap, &size);
	}
	free(heap);
	return (0);
}
