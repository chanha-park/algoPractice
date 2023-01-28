#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct treeStruct tree;
struct treeStruct
{
	char	name;
	tree	*left;
	tree	*right;
};

tree	*new_tree(char name)
{
	if (name == '.')
		return (NULL);
	tree	*new = malloc(sizeof(tree));
	new->name = name;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

tree	*find_node(tree *root, char name)
{
	tree	*find;

	if (!root)
		return (NULL);
	if (root->name == name)
		return (root);
	find = find_node(root->left, name);
	if (!find)
		find = find_node(root->right, name);
	return (find);
}

void	print_pre(tree *root)
{
	if (!root)
		return ;
	printf("%c", root->name);
	print_pre(root->left);
	print_pre(root->right);
}

void	print_in(tree *root)
{
	if (!root)
		return ;
	print_in(root->left);
	printf("%c", root->name);
	print_in(root->right);
}

void	print_post(tree *root)
{
	if (!root)
		return ;
	print_post(root->left);
	print_post(root->right);
	printf("%c", root->name);
}

int	main(void)
{
	tree	*root = NULL;
	tree	*find;
	char	a, b, c;
	int		count;

	scanf("%d", &count);
	while (count--)
	{
		scanf("\n%c %c %c", &a, &b, &c);
		if (!root)
		{
			root = new_tree(a);
			root->left = new_tree(b);
			root->right = new_tree(c);
		}
		else
		{
			find = find_node(root, a);
			find->left = new_tree(b);
			find->right = new_tree(c);
		}
	}
	print_pre(root);
	printf("\n");
	print_in(root);
	printf("\n");
	print_post(root);
	printf("\n");
	return (0);
}
