/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:55:16 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 18:24:32 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rra(t_push_swap	*push_swap)
{
	t_list	*last;
	t_list	*seclast;

	last = push_swap->stack_a;
	seclast = NULL;
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	if (last && push_swap->stack_a != last)
	{
		seclast->next = NULL;
		last->next = push_swap->stack_a;
		push_swap->stack_a = last;
	}
}

void	rrb(t_push_swap	*push_swap)
{
	t_list	*last;
	t_list	*seclast;

	last = push_swap->stack_b;
	seclast = NULL;
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	if (last && push_swap->stack_a != last)
	{
		seclast->next = NULL;
		last->next = push_swap->stack_b;
		push_swap->stack_b = last;
	}
}

void	rrr(t_push_swap	*push_swap)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(push_swap->stack_a);
	last_b = ft_lstlast(push_swap->stack_b);
	if (last_a && last_b)
	{
		if (push_swap->stack_a != last_a)
		{
			if (push_swap->stack_b != last_b)
			{
				rra(push_swap);
				rrb(push_swap);
			}
		}
	}
}
