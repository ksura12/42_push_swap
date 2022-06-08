/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:19:08 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 18:20:36 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ra(t_push_swap	*push_swap)
{
	t_list	*last;
	t_list	*head_a;

	last = ft_lstlast(push_swap->stack_a);
	head_a = push_swap->stack_a;
	if (head_a == NULL || head_a->next == NULL)
		return ;
	push_swap->stack_a = push_swap->stack_a->next;
	head_a->next = NULL;
	last->next = head_a;
}

void	rb(t_push_swap	*push_swap)
{
	t_list	*last;
	t_list	*head_b;

	last = ft_lstlast(push_swap->stack_b);
	head_b = push_swap->stack_b;
	if (head_b == NULL || head_b->next == NULL)
		return ;
	push_swap->stack_b = push_swap->stack_b->next;
	head_b->next = NULL;
	last->next = head_b;
}

void	rr(t_push_swap	*push_swap)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = push_swap->stack_a;
	head_b = push_swap->stack_b;
	if ((!head_a || !head_a->next) && (!head_b || !head_b->next))
		return ;
	else
	{
		ra(push_swap);
		rb(push_swap);
	}
}
