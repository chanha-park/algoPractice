#include <stdio.h>
#include <stdlib.h>

typedef struct s_qtree
{
	int				data;
	struct s_qtree	*leftup;
	struct s_qtree	*rightup;
	struct s_qtree	*leftdown;
	struct s_qtree	*rightdown;
}	qtree;

void	print_qtree(qtree *node)
{
	if (!node)
		return ;
	if (node->left)
	{
		printf("(");
		print_qtree(node->leftup);
		print_qtree(node->rightup);
		print_qtree(node->leftdown);
		print_qtree(node->rightdown);
		printf(")");
	}
	else
		printf("%d", node->data);
}
