#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, x;
	int	*curr_stack;
	char	*print_stack;
	int	print_idx = 0;
	int	stack_idx = 0;
	int	nbr_to_push = 1;

	scanf("%d", &n);
	curr_stack = malloc(sizeof(int) * n);
	print_stack = malloc(sizeof(char) * 2 * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (stack_idx == 0 || curr_stack[stack_idx - 1] <  x)
		{
			while (nbr_to_push <= x)
			{
				curr_stack[stack_idx++] = nbr_to_push++;
				print_stack[print_idx++] = '+';
			}
		}
		if (curr_stack[stack_idx - 1] == x)
		{
			print_stack[print_idx++] = '-';
			stack_idx--;
		}
		else
		{
			print_idx = -1;
			printf("NO\n");
			break ;
		}
	}
	for (int i = 0; i < print_idx; i++)
	{
		printf("%c\n", print_stack[i]);
	}
	free(print_stack);
	free(curr_stack);
	return (0);
}
