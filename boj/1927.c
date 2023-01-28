#include <stdio.h>
#include <stdlib.h>

void	push_heap(int *heap, int x, int *size)
{
	int	idx;

	*size += 1;
	idx = *size;
	while (idx > 1 && heap[idx / 2] > x)
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
			if (child < *size && heap[child] > heap[child + 1])
				child++;
			if (temp <= heap[child])
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
