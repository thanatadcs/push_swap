#include "stack.h"
#include <stdio.h>

void multi_push(t_stack *s, int *arr, int n)
{
	for (int i=0;i<n;i++)
		push(s, arr[i]);
}

int	main(void)
{
	const int N = 3;
	int	in[] = {1, 2, 3};
	t_stack *a = new_stack();

	// Pop
	multi_push(a, in, N);
	for (int i=0;i<N + 1;i++)
	{
		if (a->top != 0)
			printf("%d ", pop(a));
	}
	printf("\n");

	// get_node_at
	multi_push(a, in, N);
	t_dlist *node;
	for (int i=0;i<N + 1;i++)
	{
		node = get_node_at(a, i);
		if (node != 0)
			printf("%d ", node->num);
	}
	printf("\n");

	printf("%d", pop_all(a));
	free(a);
}
