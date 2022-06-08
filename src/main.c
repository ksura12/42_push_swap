/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:12:17 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 19:41:55 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"stdio.h"
#include"stdlib.h"
#include"ctype.h"
#include <string.h>
#include "../header/push_swap.h"

void	init_push_swap(t_push_swap	*push_swap);
void	llist_filling(char	**argv, t_push_swap	*push_swap);
void	printing_stacks(t_push_swap	*push_swap);
void	freeing_llist(t_push_swap	*push_swap);

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc > 1)
	{
		push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
		if (!push_swap)
			exit(1);
		init_push_swap(push_swap);
		input_errors(argv, push_swap);
		
		llist_filling(argv, push_swap);
		printing_stacks(push_swap);
		rrr(push_swap);
		printing_stacks(push_swap);
		// sa(push_swap);
		// printing_stacks(push_swap);
		// rra(push_swap);
		// printing_stacks(push_swap);
		// pb(push_swap);
		// printing_stacks(push_swap);
		// pb(push_swap);
		// pb(push_swap);
		// printing_stacks(push_swap);
		// ss(push_swap);
		// printing_stacks(push_swap);
		// rr(push_swap);
		// printing_stacks(push_swap);
		// rrr(push_swap);
		// printing_stacks(push_swap);
		// pa(push_swap);
		// printing_stacks(push_swap);
		freeing_llist(push_swap);
		free(push_swap);
		return (0);
	}
}

void	init_push_swap(t_push_swap	*push_swap)
{
	push_swap->error = 0;
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
}

void	freeing_llist(t_push_swap	*push_swap)
{
	t_list	*temp;

	while (push_swap->stack_a != NULL)
	{
		temp = push_swap->stack_a;
		push_swap->stack_a = push_swap->stack_a->next;
		free(temp);
	}
}

void	llist_filling(char	**argv, t_push_swap	*push_swap)
{
	t_list	*stack_node;
	int		c;

	c = 1;
	while (argv[c])
	{
		stack_node = ft_lstnew(ft_atoi(argv[c]));
		ft_lstadd_back(&push_swap->stack_a, stack_node);
		c++;
	}
	push_swap->list_length = c;
}

void	printing_stacks(t_push_swap	*push_swap)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		count;

	a_stack = push_swap->stack_a;
	b_stack = push_swap->stack_b;
	count = 1;
	while (a_stack || b_stack)
	{
		if (a_stack && b_stack)
		{
			ft_printf("Node %i:	 %d	%d\n", count, a_stack->content, b_stack->content);
			a_stack = a_stack->next;
			b_stack = b_stack->next;
			count++;
		}
		else if (!a_stack && b_stack)
		{
			ft_printf("Node %i:	 -	%d\n", count, b_stack->content);
			b_stack = b_stack->next;
			count++;
		}
		else if (a_stack && !b_stack)
		{
			ft_printf("Node %i:	 %d	-\n", count, a_stack->content);
			a_stack = a_stack->next;
			count++;
		}
	}
	ft_printf("	__	__\n");
	ft_printf("	A	B\n");
}

//Thoughts

/*
Fist Value in a:
1. lowest Value in a
1.1 move to b (if others are not in order)
1.1.1 highest Value in b
1.1.1.1 
1.1.2 lowest Value in b
1.1.3 inbetween
1.2 end when all in order and b empty
2. highest Value
3. inbetweeen ->
*/

//rules
/*
Stack a: ascending order
Stack b: decending order to push and have a accending

*/
//