#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	char	*data;
}	tree;

tree	*new_node(char *data)
{
	tree	*new;

	new = malloc(sizeof(*new));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}

int	cmp_str(char *s1, char *s2)
{
	int	idx1 = strlen(s1) - 1;
	int	idx2 = strlen(s2) - 1;

	if (idx1 != idx2)
		return (idx1 - idx2);
	while (idx1 >=0 && s1[idx1] == s2[idx1])
	{
		idx1--;
	}
	return (s1[idx1] - s2[idx1]);
}

void	add_tree(tree **root, tree *new)
{
	if (*root)
	{
		if (cmp_str((*root)->data, new->data) < 0)
			add_tree(&((*root)->right), new);
		else
			add_tree(&((*root)->left), new);
	}
	else
	{
		*root = new;
	}
}

void	print_tree(tree *root)
{
	if (!root)
		return ;
	print_tree(root->left);
	printf("%s\n", root->data);
	print_tree(root->right);
}

int	main(void)
{
	char	buff[101];
	int		n;
	char	curr[101];
	int		len = 0;
	int		ret;
	int		flag;
	tree	*root = NULL;

	scanf("%d", &n);
	while (n--)
	{
		ret = read(0, buff, 101);
		buff[ret] = '\0';
		flag = 0;
		for (int i = 0; i < ret; i++)
		{
			if (buff[i] >= '0' && buff[i] <= '9')
			{
				if (len != 0 || buff[i] != '0')
				{
					curr[len++] = buff[i];
				}
				if (len == 0)
					flag = 1;
			}
			else
			{
				curr[len] = '\0';
				if (i && curr[0])
					add_tree(&root, new_node(strdup(curr)));
				else if (flag)
				{
					add_tree(&root, new_node(strdup("0")));
				}
				flag = 0;
				len = 0;
				curr[0] = '\0';
			}
		}
	}
	if (curr[0])
		add_tree(&root, new_node(strdup(curr)));
	else if (flag)
	{
		add_tree(&root, new_node(strdup("0")));
	}
	print_tree(root);
}
