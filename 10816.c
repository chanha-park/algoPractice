#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define HASH_SIZE	10011

typedef struct treeType
{
	int	data;
	int	count;
	struct treeType *left;
	struct treeType *right;
}	tree;

tree	*new_tree(int data)
{
	tree	*node = malloc(sizeof(tree));

	node->count = 1;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	add_bst(tree **root, int data)
{
	if (*root)
	{
		if ((*root)->data > data)
			add_bst(&(*root)->left, data);
		else if ((*root)->data < data)
			add_bst(&(*root)->right, data);
		else
			(*root)->count += 1;
	}
	else
		*root = new_tree(data);
}

void	find_bst(tree *root, int tmp)
{
	if (!root)
		printf("0 ");
	else if (root->data < tmp)
		find_bst(root->right, tmp);
	else if (root->data > tmp)
		find_bst(root->left, tmp);
	else
		printf("%d ", root->count);
}

void	free_tree(tree *root)
{
	if (root)
	{
		free_tree(root->left);
		free_tree(root->right);
		free(root);
	}
}

int	get_hash(int n)
{
	n += 10000000;
	return (n % HASH_SIZE);
}

int	main(void)
{
	int	n, m, tmp;
	tree	**hash;

	scanf("%d", &n);
	hash = malloc(sizeof(tree *) * HASH_SIZE);
	memset(hash, 0, sizeof(*hash));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		add_bst(&hash[get_hash(tmp)], tmp);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &tmp);
		find_bst(hash[get_hash(tmp)], tmp);
	}
	return (0);
}
