#include <stdlib.h>
#include <stdio.h>

typedef struct s_lista{
	int x;
	int y;
}t_lista;



int main()
{
	int *t = malloc(sizeof(int) * 1);
	*t = 10;

	int *t2;
	t2 = t;

	int **t3;
	t3 = &t;









	printf(" t1 %p\n",t);
	printf(" t1 & %p\n",&t);
	printf(" t1* %d\n", *t);
	printf("----------------\n");
	printf(" t2 %p\n",t2);
	printf(" &t2 %p\n",&t2);
	printf(" *t2 %d\n",*t2);
	printf("----------------\n");
	printf(" t3 %p\n",t3);
	printf(" &t3 %p\n",&(*t3));
	printf("----------------\n");






	return 0;
}

// []
// []
// []

// str[3]   =    *(*(str  + 3) + 2)
// str[3][2]   = (())

// 		t
// 		|
// [[] []]
