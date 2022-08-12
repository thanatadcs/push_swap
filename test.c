#include "stack.h"
#include <stdio.h>

int	main(void)
{
	const int N = 3;
	int	in[] = {1, 2, 3};
	t_stack *a = new_stack();
	// Push
	for (int i=0;i<N;i++)
	{
		push(a, in[i]);
		if (a->top != 0)
			printf("%d ", a->top->num);
	}
	printf("\n");
	printf("%d", pop_all(a));
	// Pop
	//for (int i=0;i<N;i++)
	//	printf("%d ", pop(a));
	printf("\n");
	free(a);
}
