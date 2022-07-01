/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:30 by ksura             #+#    #+#             */
/*   Updated: 2022/06/29 12:41:29 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		pb_lowest(t_push_swap	*push_swap);
static int	find_lowest(t_push_swap	*push_swap);
void		five_args(t_push_swap	*push_swap);

void	five_args(t_push_swap	*push_swap)
{
	pb_lowest(push_swap);
	pb_lowest(push_swap);
	three_args_a(push_swap);
	pa(push_swap);
	pa(push_swap);
}

void	pb_lowest(t_push_swap	*push_swap)
{
	int	count;

	count = find_lowest(push_swap);
	while (count > 0 && count < ft_stacksize(push_swap->stack_a))
	{
		if (count <= (ft_stacksize(push_swap->stack_a) / 2))
		{
			ra(push_swap);
			count--;
		}
		else
		{
			rra(push_swap);
			count++;
		}
	}
	pb(push_swap);
}

static int	find_lowest(t_push_swap	*push_swap)
{
	t_stack		*lowest;
	t_stack		*temp;
	int			count;

	count = -1;
	lowest = (t_stack *)malloc(sizeof(t_stack));
	lowest->value = INT_MAX;
	temp = push_swap->stack_a;
	while (temp)
	{
		if (lowest->value >= temp->value)
		{
			lowest->value = temp->value;
			lowest->pos = count + 1;
		}
		temp = temp->next;
		count++;
	}
	count = lowest->pos;
	free (lowest);
	return (count);
}
