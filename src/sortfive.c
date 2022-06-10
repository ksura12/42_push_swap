/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:30 by ksura             #+#    #+#             */
/*   Updated: 2022/06/10 15:35:53 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pb_lowest(t_push_swap	*push_swap);
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
	while (count > 0 && count < ft_lstsize(push_swap->stack_a))
	{
		if (count <= (ft_lstsize(push_swap->stack_a) / 2))
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
	t_element	*lowest;
	t_list		*temp;
	int			count;

	count = -1;
	lowest = (t_element *)malloc(sizeof(t_element));
	lowest->value = INT_MAX;
	temp = push_swap->stack_a;
	while (temp)
	{
		if (lowest->value >= temp->content)
		{
			lowest->value = temp->content;
			lowest->position = count + 1;
		}
		temp = temp->next;
		count++;
	}
	count = lowest->position;
	free (lowest);
	return (count);
}
