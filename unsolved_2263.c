#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	char	*arr;
	int		max_size;
	int		curr_size;
	int		head;
	int		tail;
}	stack;

stack	*new_stack(int max_size)
{
	stack	*ret = malloc(sizeof(stack));

	ret->arr = malloc(sizeof(int) * max_size);
	ret->max_size = max_size;
	ret->curr_size = 0;
	ret->head = 0;
	ret->tail = 0;
	return (ret);
}

void	push_stack(stack *s, int n)
{
	s->arr[s->tail] = n;
	s->tail = (s->tail + 1) % s->max_size;
	(s->curr_size)++;
}

int	pop_stack(stack *s)
{
	s->tail = (s->tail - 1 + s->max_size) % s->max_size;
	(s->curr_size)--;
	return (s->arr[s->tail]);
}

int	deque_stack(stack *s)
{
	(s->curr_size)--;
	return (s->arr[(s->head)++]);
}

void	clear_stack(stack *s)
{
	free(s->arr);
	free(s);
}

int	is_empty(stack *s)
{
	return (stack->head == stack->tail);
}

void	print_pre(stack *post, stack *pre, stack *in)
{
	int	tmp;

	while (!is_empty(post) || !is_empty(in))
	{
		tmp = pop_stack(post);
	}
}

int	main(void)
{
	int	n, tmp;
	stack	*post;
	stack	*in;
	stack	*pre;

	scanf("%d", &n);
	post = new_stack(n);
	in = new_stack(n);
	pre = new_stack(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		push_stack(in, tmp);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		push_stack(post, tmp);
	}
	print_pre(post, pre, in);
	return (0);
}
