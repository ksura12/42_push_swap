/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:19:08 by ksura             #+#    #+#             */
/*   Updated: 2022/07/05 08:55:24 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ra(t_push_swap	*push_swap)
{
	t_stack	*last;
	t_stack	*head_a;

	last = ft_stacklast(push_swap->stack_a);
	head_a = push_swap->stack_a;
	if (head_a == NULL || head_a->next == NULL)
		return ;
	push_swap->stack_a = push_swap->stack_a->next;
	head_a->next = NULL;
	last->next = head_a;
	ft_printf("ra\n");
}

void	rb(t_push_swap	*push_swap)
{
	t_stack	*last;
	t_stack	*head_b;

	last = ft_stacklast(push_swap->stack_b);
	head_b = push_swap->stack_b;
	if (head_b == NULL || head_b->next == NULL)
		return ;
	push_swap->stack_b = push_swap->stack_b->next;
	head_b->next = NULL;
	last->next = head_b;
	ft_printf("rb\n");
}

void	rr(t_push_swap	*push_swap)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*last_a;
	t_stack	*last_b;

	head_a = push_swap->stack_a;
	head_b = push_swap->stack_b;
	last_a = ft_stacklast(push_swap->stack_a);
	last_b = ft_stacklast(push_swap->stack_b);
	if (!head_a || !head_a->next || !head_b
		|| !head_b->next || !last_a || !last_b)
		return ;
	else
	{
		push_swap->stack_a = push_swap->stack_a->next;
		head_a->next = NULL;
		last_a->next = head_a;
		push_swap->stack_b = push_swap->stack_b->next;
		head_b->next = NULL;
		last_b->next = head_b;
		ft_printf("rr\n");
	}
}
