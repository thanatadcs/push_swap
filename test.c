#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void multi_push(t_stack *s, int *arr, int n)
{
	for (int i=0;i<n;i++)
	{
		push(s, arr[i]);
	}
}

void	int_eq(uintptr_t actual, uintptr_t expected)
{
	printf("%s ", (actual == expected) ? GREEN"PASS"RESET : RED"FAIL"RESET);
}

void	int_neq(uintptr_t actual, uintptr_t expected)
{
	printf("%s ", (actual != expected) ? GREEN"PASS"RESET : RED"FAIL"RESET);
}

void test_basic_stack_ops(void)
{
	const int n = 3;
	int	in[] = {1, 2, 3};
	t_stack *a = new_stack();

	printf("TEST BASIC STACK OPERATIONS\n");
	// Push
	printf("PUSH TEST: ");
	int_eq((uintptr_t)push(0, 1), 0);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	
	push(a, 1);
	int_eq(a->top->num, 1);
	int_eq(a->bot->num, 1);
	int_eq((uintptr_t)a->top->front, 0);
	int_eq(a->bot->num, 1);

	push(a, 2);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 1);

	push(a, 3);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 1);
	printf("\n");

	// Pop
	printf("POP TEST: ");
	int_eq(pop(0), 0);

	int_eq(pop(a), 3);
	int_neq((uintptr_t)a->top, 0);
	int_neq((uintptr_t)a->bot, 0);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 1);

	int_eq(pop(a), 2);
	int_neq((uintptr_t)a->top, 0);
	int_neq((uintptr_t)a->bot, 0);
	int_eq(a->top->num, 1);
	int_eq(a->bot->num, 1);

	int_eq(pop(a), 1);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	int_eq((uintptr_t)a->top, (uintptr_t)a->bot);

	int_eq(pop(a), 0);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	int_eq((uintptr_t)a->top, (uintptr_t)a->bot);

	int_eq(pop(a), 0);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	int_eq((uintptr_t)a->top, (uintptr_t)a->bot);
	printf("\n");

	// Pop all
	printf("TEST POP ALL: ");
	push(a, 5);
	push(a, 5);
	push(a, 5);
	push(a, 5);
	push(a, 5);
	int_eq(a->top->num, 5);
	int_eq(pop_all(a), 5);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	printf("\n");

	// Get node at
	printf("TEST GET NODE AT: ");
	multi_push(a, in, n);
	int_eq(get_node_at(a, 0)->num, 3);
	int_eq(get_node_at(a, 1)->num, 2);
	int_eq(get_node_at(a, 2)->num, 1);
	int_eq((uintptr_t)get_node_at(a, -1), 0);
	int_eq((uintptr_t)get_node_at(a, 3), 0);
	pop_all(a);
	printf("\n");

	free(a);
}

void	test_push_swap_ops(void)
{
}

int	main(void)
{
	test_basic_stack_ops();
}
