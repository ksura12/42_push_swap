/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_sortbig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:35:13 by ksura@student.42  #+#    #+#             */
/*   Updated: 2022/07/05 11:38:11 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	moving_pivot(t_push_swap	*push_swap, t_stack	*pivot);
static void	bringbback2(t_push_swap	*push_swap, t_stack *lowest_cost);

void	pivot_to_b(t_push_swap	*push_swap)
{
	t_stack	*pivot;
	t_stack	*temp;

	find_pindex(push_swap->stack_a);
	temp = push_swap->stack_a;
	while (temp != 0)
	{
		if (temp->pindex == ft_stacksize(push_swap->stack_a) / 2)
		{
			pivot = temp;
			break ;
		}
		temp = temp->next;
	}
	moving_pivot(push_swap, pivot);
}

static void	moving_pivot(t_push_swap	*push_swap, t_stack	*pivot)
{
	int		c;
	int		size;

	c = 0;
	size = ft_stacksize(push_swap->stack_a);
	while (c <= size)
	{
		if (push_swap->stack_a->value <= pivot->value)
			pb(push_swap);
		else
			ra(push_swap);
		c++;
	}
}

void	bringbback(t_push_swap	*push_swap, t_stack *lowest_cost)
{
	while (lowest_cost->cost_a > 0 && lowest_cost->cost_b > 0)
	{
		rr(push_swap);
		lowest_cost->cost_a--;
		lowest_cost->cost_b--;
	}
	while (lowest_cost->cost_a < 0 && lowest_cost->cost_b < 0)
	{
		rrr(push_swap);
		lowest_cost->cost_a++;
		lowest_cost->cost_b++;
	}
	while (lowest_cost->cost_a > 0)
	{
		ra(push_swap);
		lowest_cost->cost_a--;
	}
	bringbback2(push_swap, lowest_cost);
}

static void	bringbback2(t_push_swap	*push_swap, t_stack *lowest_cost)
{
	while (lowest_cost->cost_a < 0)
	{
		rra(push_swap);
		lowest_cost->cost_a++;
	}
	while (lowest_cost->cost_b > 0)
	{
		rb(push_swap);
		lowest_cost->cost_b--;
	}
	while (lowest_cost->cost_b < 0)
	{
		rrb(push_swap);
		lowest_cost->cost_b++;
	}
	pa(push_swap);
}

void	target_pos(t_push_swap	*push_swap)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target;
	int		state;

	temp_b = push_swap->stack_b;
	while (temp_b)
	{
		temp_a = push_swap->stack_a;
		state = 1;
		while (temp_a)
		{
			if (temp_a->index > temp_b->index && state == 1)
			{
				target = temp_a;
				state = 0;
			}
			else if (temp_a->index > temp_b->index
				&& temp_a->index < target->index)
				target = temp_a;
			temp_a = temp_a->next;
		}
		temp_b->tar_pos = target->pos;
		temp_b = temp_b->next;
	}
}
