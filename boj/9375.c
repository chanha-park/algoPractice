#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cloth
{
	char			key[21];
	int				num;
	struct cloth	*left;
	struct cloth	*right;
}	cloth;

void	free_tree(cloth *closet)
{
	if (closet)
	{
		free_tree(closet->left);
		free_tree(closet->right);
		free(closet);
	}
}

void	add_bst(cloth **root, cloth *node)
{
	int	diff;

	if (*root)
	{
		diff = strcmp((*root)->key, node->key);
		if (diff > 0)
			add_bst(&((*root)->left), node);
		else if (diff < 0)
			add_bst(&((*root)->right), node);
		else
		{
			(*root)->num += 1;
			free_tree(node);
		}
	}
	else
	{
		*root = node;
	}
}

cloth *new_node(char *key)
{
	cloth *node = malloc(sizeof(cloth));

	memcpy(node->key, key, 21);
	node->num = 1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	traversal(cloth *closet)
{
	if (closet)
	{
		return ((1 + closet->num) * traversal(closet->left) * traversal(closet->right));
	}
	else
	{
		return (1);
	}
}

void	testcase(void)
{
	int		n;
	char	name[21];
	char	type[21];
	int		count = 1;
	cloth	*closet = NULL;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", name, type);
		add_bst(&closet, new_node(type));
	}
	count = traversal(closet);
	printf("%d\n", count - 1);
	free_tree(closet);
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	while (t--)
		testcase();
	return (0);
}
