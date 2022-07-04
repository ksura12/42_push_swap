/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ruling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:10:48 by ksura             #+#    #+#             */
/*   Updated: 2022/07/04 15:36:43 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		two_args_a(t_push_swap	*push_swap);
void		three_args_a(t_push_swap	*push_swap);
static int	right_order_a(t_push_swap	*push_swap);
void		four_args(t_push_swap	*push_swap);

void	sorting(t_push_swap	*push_swap)
{
	int	size;

	size = ft_stacksize(push_swap->stack_a);
	if (size == 1 || (right_order_a(push_swap) == 2))
		return;
	else if (size == 2)
		two_args_a(push_swap);
	else if (size == 3)
		three_args_a(push_swap);
	else if (size == 4)
		four_args(push_swap);
	else if (size == 5)
		five_args(push_swap);
	else
	{
		sortbig(push_swap);
	}
		
}

void	two_args_a(t_push_swap	*push_swap)
{
	t_stack	*temp;

	temp = push_swap->stack_a;
	if (temp->value > temp->next->value)
		sa(push_swap);
	else
		return ;
}

// static void	two_args_b(t_push_swap	*push_swap)
// {
// 	t_list	*temp;

// 	temp = push_swap->stack_b;
// 	if (temp->content < temp->next->content)
// 		sb(push_swap);
// 	else
// 		return ;
// }

void	three_args_a(t_push_swap	*push_swap)
{
	t_stack	*temp;
	
	temp = push_swap->stack_a;
		while (right_order_a(push_swap) == 0)
		{
			temp = push_swap->stack_a;
			if (temp->value > temp->next->value)
			{
				if ((temp->value > ft_stacklast(temp)->value))
					ra(push_swap);
				else
					sa(push_swap);
			}
			else
				rra(push_swap);
		}
	// push_swap->stack_b->chunk = 1;
}

// static void	three_args_b(t_push_swap	*push_swap)
// {
// 	t_list	*temp;

// 	while (!right_order_b(push_swap))
// 	{
// 		temp = push_swap->stack_b;
// 		if (temp->content < temp->next->content)
// 		{
// 			if ((temp->content < ft_lstlast(temp)->content))
// 				rb(push_swap);
// 			else
// 				sb(push_swap);
// 		}
// 	}
// }

void	four_args(t_push_swap	*push_swap)
{
	if (right_order_a(push_swap))
		return ;
	pb_lowest(push_swap);
	three_args_a(push_swap);
	pa(push_swap);
	//push_swap->stack_b->chunk = 1;
}

static int	right_order_a(t_push_swap	*push_swap)
{
	t_stack	*temp;
	int		ret;

	ret = 0;
	temp = push_swap->stack_a;
	while (temp && temp->next && (temp->value < temp->next->value))
	{
		temp = temp->next;
	}
	if (temp == ft_stacklast(push_swap->stack_a) && !push_swap->stack_b)
	{
		ret = 2;
	}
		
	else if (temp == ft_stacklast(push_swap->stack_a))
	{
		ret = 1;
	}
		
	else
		ret = 0;
	return (ret);
}
