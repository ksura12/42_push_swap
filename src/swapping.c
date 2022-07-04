/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:27:05 by ksura             #+#    #+#             */
/*   Updated: 2022/07/04 15:03:31 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	swap(t_stack	*stack);

void	sa(t_push_swap *push_swap)
{
	t_stack	*temp;

	temp = push_swap->stack_a;
	if (temp != NULL && temp->next != NULL)
		swap(push_swap->stack_a);
	ft_printf("sa\n");
}

void	sb(t_push_swap *push_swap)
{
	t_stack	*temp;

	temp = push_swap->stack_b;
	if (temp != NULL && temp->next != NULL)
		swap(push_swap->stack_b);
	ft_printf("sb\n");
}

void	ss(t_push_swap *push_swap)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = push_swap->stack_a;
	temp_b = push_swap->stack_b;
	if (temp_a && temp_a->next && temp_b && temp_b->value)
	{
		sa(push_swap);
		sb(push_swap);
	}
	else
		return ;
}

static void	swap(t_stack	*stack)
{
	int	index;
	int	value;
	
	index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = index;
	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
}
