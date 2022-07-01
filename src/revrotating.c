/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:55:16 by ksura             #+#    #+#             */
/*   Updated: 2022/06/29 12:30:54 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rra(t_push_swap	*push_swap)
{
	t_stack	*last;
	t_stack	*seclast;

	last = push_swap->stack_a;
	seclast = NULL;
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
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
	ft_printf("rra\n");
}

void	rrb(t_push_swap	*push_swap)
{
	t_stack	*last;
	t_stack	*seclast;

	last = push_swap->stack_b;
	seclast = NULL;
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
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
	ft_printf("rrb\n");
}

void	rrr(t_push_swap	*push_swap)
{
	t_stack	*last_a;
	t_stack	*last_b;
	t_stack *seclast_a;
	t_stack *seclast_b;

	last_a = ft_stacklast(push_swap->stack_a);
	last_b = ft_stacklast(push_swap->stack_b);
	seclast_a = NULL;
	seclast_b = NULL;
	if (!push_swap->stack_b || !push_swap->stack_b->next || !push_swap->stack_a 
	|| !push_swap->stack_a->next || !last_a || !last_b)
		return ;
	else
	{
		while (last_a->next != NULL)
		{
			seclast_a = last_a;
			last_a = last_a->next;
		}
		while (last_b->next != NULL)
		{
			seclast_b = last_b;
			last_b = last_b->next;
		}
		seclast_a->next = NULL;
		seclast_b->next = NULL;
		last_a->next = push_swap->stack_a;
		last_b->next = push_swap->stack_b;
		push_swap->stack_a = last_a;
		push_swap->stack_b = last_b;
		ft_printf("rrr\n");
	}
}
