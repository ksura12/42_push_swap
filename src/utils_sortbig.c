/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sortbig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:09:51 by ksura@student.42  #+#    #+#             */
/*   Updated: 2022/07/05 09:33:10 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ordering_a(t_push_swap	*push_swap)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = push_swap->stack_a;
	while (temp && temp->index != 1)
	{
		count++;
		temp = temp->next;
	}
	if (count > ft_stacksize(push_swap->stack_a) / 2)
	{
		while (count < (ft_stacksize(push_swap->stack_a)))
		{
			rra(push_swap);
			count++;
		}
	}
	else
	{
		while (count-- > 0)
			ra(push_swap);
	}
}

void	best_move(t_push_swap *push_swap)
{
	int		total_cost;
	t_stack	*lowest_cost;
	t_stack	*temp_b;

	temp_b = push_swap->stack_b;
	total_cost = INT_MAX;
	while (temp_b)
	{
		if (total_cost > (abs(temp_b->cost_a) + abs(temp_b->cost_b)))
		{
			total_cost = abs(temp_b->cost_a) + abs(temp_b->cost_b);
			lowest_cost = temp_b;
		}
		temp_b = temp_b->next;
	}
	bringbback(push_swap, lowest_cost);
}

int	abs(int c)
{
	if (c < 0)
		return (c * -1);
	else
		return (c);
}

void	calc_cost_b(t_push_swap	*push_swap)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_b = push_swap->stack_b;
	calc_cost_a(push_swap);
	while (temp_b)
	{
		if (temp_b->pos <= (ft_stacksize(push_swap->stack_b) / 2))
			temp_b->cost_b = temp_b->pos;
		else if (temp_b->pos > (ft_stacksize(push_swap->stack_b) / 2))
		{
			temp_b->cost_b = (temp_b->pos - ft_stacksize(push_swap->stack_b));
		}
		temp_a = push_swap->stack_a;
		while (temp_a)
		{
			if (temp_a->pos == temp_b->tar_pos)
				temp_b->cost_a = temp_a->cost_a;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

void	calc_cost_a(t_push_swap *push_swap)
{
	t_stack	*temp;

	temp = push_swap->stack_a;
	while (temp)
	{
		if (temp->pos <= (ft_stacksize(push_swap->stack_a) / 2))
			temp->cost_a = temp->pos;
		else if (temp->pos > (ft_stacksize(push_swap->stack_a) / 2))
		{
			temp->cost_a = (temp->pos - ft_stacksize(push_swap->stack_a));
		}
		temp = temp->next;
	}
}
