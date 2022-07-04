/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:12:17 by ksura             #+#    #+#             */
/*   Updated: 2022/07/04 19:51:38 by ksura@student.42 ###   ########.fr       */
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
		push_swap = (t_push_swap *)ft_calloc(1, sizeof(t_push_swap));
		if (!push_swap)
			exit(1);
		input_errors(argv, push_swap);
		llist_filling(argv, push_swap);
		sorting(push_swap);
		freeing_llist(push_swap);
		free(push_swap);
		return (0);
	}
}

void	freeing_llist(t_push_swap	*push_swap)
{
	t_stack	*temp;

	while (push_swap->stack_a != NULL)
	{
		temp = push_swap->stack_a;
		push_swap->stack_a = push_swap->stack_a->next;
		free(temp);
	}
}

void	llist_filling(char	**argv, t_push_swap	*push_swap)
{
	t_stack	*stack_node;
	int		c;

	c = 1;
	while (argv[c])
	{
		stack_node = ft_stacknew(ft_atoi(argv[c]));
		ft_stackadd_back(&push_swap->stack_a, stack_node);
		c++;
	}
	push_swap->list_length = c;
}

// void	printing_stacks(t_push_swap	*push_swap)
// {
// 	t_stack	*a_stack;
// 	t_stack	*b_stack;
// 	int		count;

// 	a_stack = push_swap->stack_a;
// 	b_stack = push_swap->stack_b;
// 	count = 1;
// 	while (a_stack || b_stack)
// 	{
// 		if (a_stack && b_stack)
// 		{
// 			ft_printf("Node %i:	 Value:%d	pos:%d	index:%d	
// cost_a:%d	Value:%d	pos:%d	tar_pos:%d	cost_a:%d	
// cost_b:%d\n", count, a_stack->value, a_stack->pos, 
// a_stack->index, a_stack->cost_a, b_stack->value, b_stack->pos, 
// b_stack->tar_pos,
// b_stack->cost_a, b_stack->cost_b);
// 			a_stack = a_stack->next;
// 			b_stack = b_stack->next;
// 			count++;
// 		}
// 		else if (!a_stack && b_stack)
// 		{
// 			ft_printf("Node %i:	 Value:-	pos:-	index:-	cost_a:-
	// Value:%d		pos:%d	tar_pos:%d	cost_a:%d	cost_b:%d\n",
	//  count, b_stack->value, b_stack->pos,
//  b_stack->tar_pos, b_stack->cost_a, b_stack->cost_b);
// 			b_stack = b_stack->next;
// 			count++;
// 		}
// 		else if (a_stack && !b_stack)
// 		{
// 			ft_printf("Node %i:	 Value:%d	pos:%d	index:%d	
// cost_a:%d	Value:-		pos:-	
// tar_pos:-	cost_a:-	cost_b:-\n", count, a_stack->value,
//  a_stack->pos, a_stack->index, a_stack->cost_a);
// 			a_stack = a_stack->next;
// 			count++;
// 		}
// 	}
// 	ft_printf("	__	__\n");
// 	ft_printf("	A	B\n");
// }
