/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ruling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:10:48 by ksura             #+#    #+#             */
/*   Updated: 2022/06/13 10:23:17 by ksura            ###   ########.fr       */
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

	size = ft_lstsize(push_swap->stack_a);
	if (size == 1 || right_order_a(push_swap))
	{
		ft_printf("\n");
		exit(EXIT_SUCCESS);
	}
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
	t_list	*temp;

	temp = push_swap->stack_a;
	if (temp->content > temp->next->content)
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
	t_list	*temp;

	while (!right_order_a(push_swap))
	{
		temp = push_swap->stack_a;
		if (temp->content > temp->next->content)
		{
			if ((temp->content > ft_lstlast(temp)->content))
				ra(push_swap);
			else
				sa(push_swap);
		}
		else
			rra(push_swap);
	}
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
}

static int	right_order_a(t_push_swap	*push_swap)
{
	t_list	*temp;
	t_list	*temp2;
	int		ret;

	ret = 0;
	temp = push_swap->stack_a;
	temp2 = push_swap->stack_a->next;
	while (temp && temp2 && temp->content < temp2->content)
	{
		temp = temp2;
		temp2 = temp2->next;
	}
	if (temp == ft_lstlast(push_swap->stack_a) && !push_swap->stack_b)
		ret = 2;
	else if (temp == ft_lstlast(push_swap->stack_a))
		ret = 1;
	else
		ret = 0;
	return (ret);
}


