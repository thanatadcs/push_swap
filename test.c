#include "stack.h"
#include <stdio.h>

void multi_push(t_stack *s, int *arr, int n)
{
	for (int i=0;i<n;i++)
	{
		push(s, arr[i]);
		printf("push: %d, size: %zu\n", arr[i], s->size);
	}
}

// printf("%s ", (my_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);

int	main(void)
{
	const int N = 3;
	int	in[] = {1, 2, 3};
	t_stack *a = new_stack();

	// Pop
	printf("POP TEST\n");
	multi_push(a, in, N);
	printf("top: %d, bot: %d\n", a->top->num, a->bot->num);
	for (int i=0;i<N + 1;i++)
	{
		if (a->top != 0)
		{
			printf("top: %d, bot: %d\n", a->top->num, a->bot->num);
			printf("pop: %d, size: %zu\n", pop(a), a->size);
		}
		printf("top: %p, bot: %p\n", a->top, a->bot);
	}
	printf("\n");
/*
	// get_node_at
	printf("GET_NODE TEST\n");
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
*/
	free(a);
}
