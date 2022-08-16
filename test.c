#include "libft.h"
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

void	print_stack(t_stack *s)
{
	t_dlist *cur_node;
	if (s == 0)
		return ;
	printf("\n-- print stack --\n");
	cur_node = s->top;
	while (cur_node)
	{
		printf("%d ", cur_node->num);
		cur_node = cur_node->front;
	}
	printf("\n--  end stack  --\n");
}

void	int_eq(intptr_t actual, intptr_t expected)
{
	printf("%s ", (actual == expected) ? GREEN"PASS"RESET : RED"FAIL"RESET);
}

void	int_neq(intptr_t actual, intptr_t expected)
{
	printf("%s ", (actual != expected) ? GREEN"PASS"RESET : RED"FAIL"RESET);
}

void test_basic_stack_ops(void)
{
	const int n = 3;
	int	in[] = {1, 2, 3};
	t_stack *a = new_stack();

	printf("-- TEST BASIC STACK OPERATIONS --\n");
	// Push
	printf("PUSH TEST: ");
	int_eq((uintptr_t)push(0, 1), 0);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	int_eq(a->size, 0);
	
	int_neq((uintptr_t)push(a, 1), 0);
	int_eq(a->top->num, 1);
	int_eq(a->bot->num, 1);
	int_eq((uintptr_t)a->top->front, 0);
	int_eq(a->bot->num, 1);
	int_eq(a->size, 1);

	int_neq((uintptr_t)push(a, 2), 0);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 1);
	int_eq(a->size, 2);

	int_neq((uintptr_t)push(a, 3), 0);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 1);
	int_eq(a->size, 3);
	printf("\n");

	// Pop
	printf("POP TEST: ");
	int_eq(pop(0), 0);

	int_eq(pop(a), 3);
	int_neq((uintptr_t)a->top, 0);
	int_neq((uintptr_t)a->bot, 0);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 1);
	int_eq(a->size, 2);

	int_eq(pop(a), 2);
	int_neq((uintptr_t)a->top, 0);
	int_neq((uintptr_t)a->bot, 0);
	int_eq(a->top->num, 1);
	int_eq(a->bot->num, 1);
	int_eq(a->size, 1);

	int_eq(pop(a), 1);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	int_eq((uintptr_t)a->top, (uintptr_t)a->bot);
	int_eq(a->size, 0);

	int_eq(pop(a), 0);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	int_eq((uintptr_t)a->top, (uintptr_t)a->bot);
	int_eq(a->size, 0);

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
	pop_all(a);
	int_eq((uintptr_t)a->top, 0);
	int_eq((uintptr_t)a->bot, 0);
	pop_all(a);
	printf("\n");

	// Get node at
	printf("TEST GET NODE AT: ");
	multi_push(a, in, n);
	int_eq(get_int_at(a, 0), 3);
	int_eq(get_int_at(a, 1), 2);
	int_eq(get_int_at(a, 2), 1);
	int_eq(get_int_at(a, -1), 0);
	int_eq(get_int_at(a, 3), 0);
	pop_all(a);
	int_eq(get_int_at(a, 0), 0);
	int_eq(get_int_at(a, 1), 0);
	int_eq(get_int_at(a, 2), 0);
	printf("\n");

	free(a);
}

void	test_additional_stack_ops(void)
{
	// get_strs_stack
	printf("-- TEST ADDITIONAL STACK OPERATIONS --\n");
	printf("TEST GET STACK FROM STRS: ");
	char *strs[] = {"1", "2", "3"};
	t_stack *a = get_stack_strs(strs, 3);
	int_eq(pop(a), 1);	
	int_eq(pop(a), 2);	
	int_eq(pop(a), 3);	
	int_eq(pop(a), 0);
	free(a);
	printf("\n");

	// swap
	printf("TEST SWAP: ");
	a = get_stack_strs(strs, 3);
	int_eq(get_int_at(a, 0), 1);
	int_eq(a->top->num, 1);
	int_eq(a->bot->num, 3);
	swap(a);
	int_eq(get_int_at(a, 0), 2);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 3);
	swap(a);
	int_eq(get_int_at(a, 0), 1);
	int_eq(a->top->num, 1);
	int_eq(a->bot->num, 3);
	pop(a);
	int_eq(get_int_at(a, 0), 2);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 3);
	swap(a);
	int_eq(get_int_at(a, 0), 3);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 2);
	swap(0);
	pop_all(a);
	swap(a);
	printf("\n");
	free(a);

	// pop_push
	printf("TEST POP PUSH: ");
	a = get_stack_strs(strs, 3);
	t_stack *b = new_stack();
	int_eq(pop_push(a, b), 1);
	int_eq(a->top->num, 2);
	int_eq(b->top->num, 1);
	int_eq(pop_push(b, a), 1);
	int_eq(a->top->num, 1);
	int_eq((uintptr_t)b->top, 0);
	int_eq(pop_push(a, b), 1);
	int_eq(pop_push(a, b), 1);
	int_eq(a->top->num, 3);
	int_eq(b->top->num, 2);
	int_eq(pop_push(a, b), 1);
	int_eq((uintptr_t)a->top, 0);
	int_eq(b->top->num, 3);
	int_eq(pop_push(0, 0), 0);
	int_eq(pop_push(0, b), 0);
	printf("\n");
	pop_all(a);
	pop_all(b);
	free(a);
	free(b);

	// rotate_up
	printf("TEST ROTATE UP: ");
	a = get_stack_strs(strs, 3);

	rotate_up(a);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 1);

	rotate_up(a);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 2);

	rotate_up(a);
	int_eq(a->top->num, 1);
	int_eq(a->top->front->num, 2);
	int_eq(a->bot->num, 3);

	push(a, 4);
	int_eq(a->top->num, 4);
	int_eq(a->top->front->num, 1);
	int_eq(a->bot->back->num, 2);
	int_eq(a->bot->num, 3);

	rotate_up(a);
	int_eq(a->top->num, 1);
	int_eq(a->top->front->num, 2);
	int_eq(a->bot->back->num, 3);
	int_eq(a->bot->num, 4);
	pop(a);
	pop(a);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 4);

	rotate_up(a);
	int_eq(a->top->num, 4);
	int_eq(a->bot->num, 3);
	pop_all(a);
	printf("\n");
	free(a);

	// rotate_down
	printf("TEST ROTATE DOWN: ");
	a = get_stack_strs(strs, 3);

	rotate_down(a);
	int_eq(a->top->num, 3);
	int_eq(a->top->front->num, 1);
	int_eq(a->bot->num, 2);

	rotate_down(a);
	int_eq(a->top->num, 2);
	int_eq(a->top->front->num, 3);
	int_eq(a->bot->num, 1);

	rotate_down(a);
	int_eq(a->top->num, 1);
	int_eq(a->top->front->num, 2);
	int_eq(a->bot->num, 3);

	pop(a);
	rotate_down(a);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 2);

	rotate_down(a);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 3);

	push(a, 1);
	int_eq(a->top->num, 1);
	int_eq(a->top->front->num, 2);
	int_eq(a->bot->num, 3);
	int_eq((uintptr_t)a->bot->front, 0);

	rotate_down(a);
	int_eq(a->top->num, 3);
	int_eq(a->top->front->num, 1);
	int_eq(a->bot->num, 2);

	pop(a); pop(a);
	rotate_down(a);
	int_eq(a->top->num, 2);
	int_eq(a->bot->num, 2);
	pop(a);
	free(a);
	printf("\n");
}

void test_push_swap_utils(void)
{
	// is_int
	printf("-- TEST PUSH SWAP UTILS --\n");
	char *s;
	printf("TEST IS INT: ");
	for (long i = -1000000000; i <= 1000000000; i+=1013)
	{
		s = ft_itoa(i);
		if (!is_int(s))
		{
			free(s);
			printf("%s ", RED"FAIL"RESET);
			return ;
		}
		free(s);
	}
	printf("%s ", GREEN"PASS"RESET);

	int_eq(is_int("10000000000"), 0);
	int_eq(is_int("-10000000000"), 0);
	int_eq(is_int("2147483647"), 1);
	int_eq(is_int("-2147483648"), 1);
	int_eq(is_int("2147483646"), 1);
	int_eq(is_int("-2147483647"), 1);
	int_eq(is_int("2147483649"), 0);
	int_eq(is_int("-2147483649"), 0);

	printf("\n");

	// is_valid
	printf("TEST IS VALID: ");
	char *a[] = {"1", "2", "3", "4"};
	int_eq(is_valid(a, 4), 1);
	char *b[] = {"", "1"};
	int_eq(is_valid(b, 2), 0);
	char *c[] = {"11", "10", "-2147483648",  "2147483647"};
	int_eq(is_valid(c, 4), 1);
	char *d[] = {"11", "10", "-2147483648",  "2147483647", "2147483646"};
	int_eq(is_valid(d, 5), 1);
	char *e[] = {"11", "10", "-2147483648",  "2147483647", "2147483646", "11"};
	int_eq(is_valid(e, 6), 0);
	char *f[] = {"11", "10", "-2147483648",  "2147483647", "2147483646", "one"};
	int_eq(is_valid(f, 6), 0);
	printf("\n");
}

void	test_push_swap_ops(void)
{
	printf("-- TEST PUSH SWAP OPERATIONS ==\n");
	printf("MIXED: ");
	char *strs[] = {"1", "2", "3"};
	initialize_ps(strs, 3);
	t_ps_stack stack_a = A;
	t_ps_stack stack_b = B;
	t_stack *a = get_ps_stack(stack_a);
	t_stack *b = get_ps_stack(stack_b);

	int_eq(a->top->num, 1);
	int_eq(a->top->front->num, 2);
	int_eq(a->bot->num, 3);
	int_eq((uintptr_t)b->top, 0);

	p(B);
	p(B);
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 3);
	int_eq(b->top->num, 2);
	int_eq(b->bot->num, 1);

	uu();
	int_eq(a->top->num, 3);
	int_eq(a->bot->num, 3);
	int_eq(b->top->num, 1);
	int_eq(b->bot->num, 2);
	free_ps();
	printf("\n");
}

void	test_push_swap_algo(void)
{
	printf("-- TEST PUSH SWAP SORTING ALGORITHM --\n");
	printf("TEST FIND MIN INDEX: ");
	t_ps_stack a = A;
	//t_ps_stack b = B;
	char *strs[] = {"1", "2", "3"};
	initialize_ps(strs, 3);
	int_eq(find_min_index(a), 0);

	u(a);
	int_eq(find_min_index(a), 2);

	u(a);
	int_eq(find_min_index(a), 1);
	printf("\n");

	printf("TEST BSORT: ");
	int_eq(peek_at(a, 0), 3);
	int_eq(peek_at(a, 1), 1);
	int_eq(peek_at(a, 2), 2);
	bsort();
	int_eq(peek_at(a, 0), 1);
	int_eq(peek_at(a, 1), 2);
	int_eq(peek_at(a, 2), 3);
	free_ps();
	printf("\n");
}

int	main(void)
{
	//test_basic_stack_ops();
	//test_additional_stack_ops();
	//test_push_swap_utils();
	//test_push_swap_ops();
	test_push_swap_algo();
}
