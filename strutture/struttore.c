#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
	int	max;
	struct s_tree *destr;
}t_tree;

t_tree *scorri(t_tree *f)
{
	if(f -> destr != NULL)
		f = scorri(f -> destr);
	return (f);
}

void fill(t_tree *f, int b)
{
	f = scorri(f);
	f -> max = b;
	//f -> destr = (t_tree *)calloc(1, sizeof(t_tree));
}
void new_tree(t_tree *f)
{
	f = scorri(f);
	f -> destr = (t_tree *)calloc(1, sizeof(t_tree));
}
void print(t_tree *f)
{	
	while(f != NULL)
	{
		printf("%d", f -> max);
		f = f -> destr;
	}
}

void	del(t_tree **f)
{
	if (*f)
		free(*f);
	*f = NULL;
}

void freeall(t_tree *f)
{
	t_tree *base = f;
	while(f != NULL)
	{
		base = base -> destr;
		free(f);
		f = base;
	}
}
int main ()
{
	t_tree *numeri;
	int i=-1;

	numeri = (t_tree *)calloc(1, sizeof(t_tree));

	while(++i <5)
	{
		fill(numeri, i);
		if(i != 4)
			new_tree(numeri);
	}
	print(numeri);
	freeall(numeri);

}