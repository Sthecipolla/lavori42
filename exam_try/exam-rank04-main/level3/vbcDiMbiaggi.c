#include <stdio.h>
#include <malloc.h> // change this to <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

node    *parse_num(char **s);
node    *parse_fact(char **s);
node    *parse_expr(char **s);

node    *parse_num(char **s)
{
	if (isdigit(**s))
	{
		node node = {VAL, **s - '0', NULL, NULL};
		(*s)++;
		return (new_node(node));
	}
	else if (accept(s, '('))
	{
		node *node = parse_expr(s);
		if (node == NULL)
			return(NULL);
		if (!expect(s, ')')) 
		{
            destroy_tree(node);
            return (NULL);
        }
        return (node);
    }
    unexpected(**s);
	return (NULL);
}

int count_bracket(char *s)
{
	int count = 0;
	int i = 0;
	int count_rv = 0;

	while(s[i] != '\0')
	{
		if(s[i] == '(')
			count ++;
		if(s[i] == ')')
			count_rv ++;
		i ++;
	}
	if (count - count_rv == 0)
		return (0);
	return (1);

}

node    *parse_fact(char **s)
{
	node *left = parse_num(s);
	if (left == NULL)
		return(NULL);
	while (accept(s, '*'))
	{
		node *right = parse_fact(s);
		if (right == NULL)
		{
			destroy_tree(left);
			return (NULL);
		}
		node node = {MULTI, 0, left, right};
		return(new_node(node));
	}
/* 	
	if (!accept(s, '\0'))
	{
		unexpected(**s);
	}
*/
	return (left);
}

node    *parse_expr(char **s)
{
	node *left = parse_fact(s);
	if (left == NULL)
		return(NULL);
	while (accept(s, '+'))
	{
		node *right = parse_expr(s);
		if (right == NULL)
		{
			destroy_tree(left);
			return (NULL);
		}
		node node = {ADD, 0, left, right};
		return(new_node(node));
	}
/* 	if (!accept(s, '\0'))
	{
		unexpected(**s);
	} */
	return (left);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
	return (3);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(&argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}
