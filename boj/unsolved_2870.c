#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct strInt
{
	char	*num;
	int		size;
	int		len;
}	strInt;

strInt	initStrInt(int nbr)
{
	strInt	n;

	if (nbr == 0)
	{
		n.size = 2;
		n.len = 1;
		n.num = malloc(sizeof(char) * n.size);
		n.num[0] = '0';
		n.num[1] = '\0';
	}
	else
	{
		n.size = 11;
		n.len = 0;
		n.num = malloc(sizeof(char) * n.size);
		while (nbr)
		{
			n.num[n.len++] = nbr % 10 + '0';
			nbr /= 10;
		}
		n.num[n.len] = '\0';
	}
	return (n);
}

void	deleteStrInt(strInt *n)
{
	free(n->num);
	n->num = NULL;
	n->len = 0;
	n->size = 0;
}

strInt	addStrInt(strInt a, strInt b)
{
	strInt	c;
	int		temp;
	int		carr = 0;
	int		len = 0;

	c.size = a.size > b.size ? a.size : b.size;
	c.size ++;
	c.num = malloc(sizeof(char) * c.size);
	while (len < a.len && len < b.len)
	{
		temp = a.num[len] + b.num[len] - 96 + carr;
		c.num[len++] = temp % 10 + '0';
		carr = temp / 10;
	}
	if (len == a.len)
	{
		while (len < b.len)
		{
			temp = b.num[len] - 48 + carr;
			c.num[len++] = temp % 10 + '0';
			carr = temp / 10;
		}
	}
	else if (len == b.len)
	{
		while (len < a.len)
		{
			temp = a.num[len] - 48 + carr;
			c.num[len++] = temp % 10 + '0';
			carr = temp / 10;
		}
	}
	if (carr)
		c.num[len++] = carr + '0';
	c.num[len] = '\0';
	c.len = len;
	return (c);
}

void	printStrInt(strInt n)
{
	for (int i = n.len - 1; i >= 0; i--)
	{
		printf("%c", n.num[i]);
	}
	printf("\n");
}

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
