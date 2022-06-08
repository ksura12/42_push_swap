/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:56:21 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 18:21:10 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pa(t_push_swap	*push_swap)
{
	t_list	*to_push;

	if (push_swap->stack_b == NULL)
		return ;
	to_push = push_swap->stack_b;
	push_swap->stack_b = push_swap->stack_b->next;
	ft_lstadd_front(&push_swap->stack_a, to_push);
}

void	pb(t_push_swap	*push_swap)
{
	t_list	*to_push;

	if (push_swap->stack_a == NULL)
		return ;
	to_push = push_swap->stack_a;
	push_swap->stack_a = push_swap->stack_a->next;
	ft_lstadd_front(&push_swap->stack_b, to_push);
}
