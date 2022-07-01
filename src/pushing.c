/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:56:21 by ksura             #+#    #+#             */
/*   Updated: 2022/06/29 11:42:20 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pa(t_push_swap	*push_swap)
{
	t_stack	*to_push;

	if (push_swap->stack_b == NULL)
		return ;
	to_push = push_swap->stack_b;
	push_swap->stack_b = push_swap->stack_b->next;
	ft_stackadd_front(&push_swap->stack_a, to_push);
	ft_printf("pa\n");
}

void	pb(t_push_swap	*push_swap)
{
	t_stack	*to_push;

	if (push_swap->stack_a == NULL)
		return ;
	to_push = push_swap->stack_a;
	push_swap->stack_a = push_swap->stack_a->next;
	ft_stackadd_front(&push_swap->stack_b, to_push);
	ft_printf("pb\n");
}
