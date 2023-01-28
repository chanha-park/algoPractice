#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tree
{
	float			value;
	int				n_node;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*new_node(float value)
{
	t_tree	*node = malloc(sizeof(t_tree));

	if (!node)
		return (NULL);
	node->value = value;
	node->n_node = 1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	add_node(t_tree **root, t_tree *node)
{
	if (!*root)
	{
		*root = node;
		return (0);
	}
	if (!node)
		return (0);
	(*root)->n_node += 1;
	if ((*root)->value > node->value)
		return (add_node(&((*root)->right), node));
	else
		return (add_node(&((*root)->left), node));
}

void	ax_b(t_root **root, int *sign, float a, float b)
{
	if (a == 0)
	{
		if (b == 0)
			*sign = 0;
		else if (b < 0)
			*sign *= -1;
	}
	else
	{
		add_node(root, new_node((float)-b / a));
		if (a < 0)
			*sign *= -1;
	}
}

void	print_sign(t_tree *root, int sign, float c)
{
	int	count = 0;

	if (sign == 0)
		printf("0\n");
}

int	main(void)
{
	int		q, t;
	float	a, b, c;
	int		idx = 0;
	t_tree	*root = NULL;
	int		sign = 1;

	scanf("%d", &q);
	while (idx++ < q)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%f %f", &a, &b);
			ax_b(&root, &sign, a, b);
		}
		else
		{
			scanf("%f", &c);
			print_sign(root, sign, c);
		}
	}
}
