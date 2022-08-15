#include <stdio.h>
#include <stdlib.h>

void	heapify(int *heap, int index, int size)
{
	int	smallest = index;
	int	left = 2 * index;
	int	right = 2 * index + 1;
	int	temp;

	if (left < (1 + size) && heap[left] < heap[smallest])
		smallest = left;
	if (right < (1 + size) && heap[right] < heap[smallest])
		smallest = right;
	if (smallest != index)
	{
		temp = heap[smallest];
		heap[smallest] = heap[index];
		heap[index] = temp;
		heapify(heap, smallest, size);
	}
}

void	push_heap(int *heap, int x, int *size)
{
	*size += 1;
	heap[*size] = x;
	heapify(heap, *size / 2, *size);
}

void	pop_heap(int *heap, int *size)
{
	if (*size == 0)
		printf("0\n");
	else
	{
		printf("%d\n", heap[1]);
		heap[1] = heap[*size];
		heap[*size] = 0;
		*size -= 1;
		heapify(heap, 1, *size);
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
		if (x)
			push_heap(heap, x, &size);
		else
			pop_heap(heap, &size);
	}
	free(heap);
	return (0);
}
