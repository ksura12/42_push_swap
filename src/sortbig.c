/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:21:46 by ksura             #+#    #+#             */
/*   Updated: 2022/07/05 10:56:42 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	pindex_core(t_stack *stack_a, int index);

void	sortbig(t_push_swap	*push_swap)
{
	find_index(push_swap->stack_a);
	while (ft_stacksize(push_swap->stack_a) > 5)
		pivot_to_b(push_swap);
	if (ft_stacksize(push_swap->stack_a) == 2)
		two_args_a(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 3)
		three_args_a(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 4)
		four_args(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 5)
		five_args(push_swap);
	while (ft_stacksize(push_swap->stack_b) > 0)
	{
		find_pos(push_swap->stack_a);
		find_pos(push_swap->stack_b);
		target_pos(push_swap);
		calc_cost_b(push_swap);
		best_move(push_swap);
	}
	ordering_a(push_swap);
}

void	find_index(t_stack	*stack_a)
{
	t_stack	*temp;
	t_stack	*lowest;
	int		index;

	index = 1;
	while (index <= ft_stacksize(stack_a))
	{
		temp = stack_a;
		lowest = temp;
		while (temp != NULL)
		{
			if (temp->value <= lowest->value && temp->index == 0)
				lowest = temp;
			else if (lowest->index != 0)
				lowest = temp;
			temp = temp->next;
		}
		lowest->index = index;
		index++;
	}
}

void	find_pindex(t_stack *stack_a)
{
	t_stack	*temp;
	int		index;

	index = 1;
	temp = stack_a;
	while (temp)
	{
		temp->pindex = -1;
		temp = temp->next;
	}
	while (index <= ft_stacksize(stack_a))
	{
		index = pindex_core(stack_a, index);
	}
}

static int	pindex_core(t_stack *stack_a, int index)
{
	t_stack	*temp;
	t_stack	*lowest;
	int		count;

	count = 0;
	temp = stack_a;
	lowest = temp;
	while (temp != NULL)
	{
		if (temp->value < lowest->value && temp->pindex == -1)
			lowest = temp;
		else if (lowest->pindex != -1)
			lowest = temp;
		temp = temp->next;
		count++;
	}
	lowest->pindex = index;
	index++;
	return (index);
}

void	find_pos(t_stack	*stack)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = stack;
	while (temp)
	{
		temp->pos = pos;
		temp = temp->next;
		pos++;
	}
}
