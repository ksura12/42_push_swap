/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:27:05 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 14:03:47 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../header/push_swap.h"

static void	swap(int 	*a, int	*b);

void	sa(t_push_swap *push_swap)
{
	t_list	*temp;

	temp = push_swap->stack_a;
	if (temp != NULL && temp->next != NULL)
		swap(&temp->content, &temp->next->content);
}

void	sb(t_push_swap *push_swap)
{
	t_list	*temp;

	temp = push_swap->stack_b;
	if (temp != NULL && temp->next != NULL)
		swap(&temp->content, &temp->next->content);
}

void	ss(t_push_swap *push_swap)
{
	t_list	*temp_a;
	t_list	*temp_b;
	
	temp_a = push_swap->stack_a;
	temp_b = push_swap->stack_b;
	if(temp_a && temp_a->next && temp_b && temp_b->content)
	{
		sa(push_swap);
		sb(push_swap);
	}
	else
		return;
}

static void	swap(int 	*a, int	*b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}