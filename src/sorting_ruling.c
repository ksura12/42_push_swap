/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ruling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:10:48 by ksura             #+#    #+#             */
/*   Updated: 2022/06/09 20:51:20 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	two_args_a(t_push_swap	*push_swap);
static void	two_args_b(t_push_swap	*push_swap);
static void	three_args_a(t_push_swap	*push_swap);
// static void	three_args_b(t_push_swap	*push_swap);
static int	right_order_a(t_push_swap	*push_swap);
// static int	right_order_b(t_push_swap	*push_swap);
static void	four_args(t_push_swap	*push_swap);
static void	shifting(t_push_swap	*push_swap);
static void shift2(t_push_swap	*push_swap);
static void	backshifting(t_push_swap	*push_swap);
static void	five_args(t_push_swap	*push_swap);


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
}

static void	two_args_a(t_push_swap	*push_swap)
{
	t_list	*temp;

	temp = push_swap->stack_a;
	if (temp->content > temp->next->content)
		sa(push_swap);
	else
		return ;
}

static void	two_args_b(t_push_swap	*push_swap)
{
	t_list	*temp;

	temp = push_swap->stack_b;
	if (temp->content < temp->next->content)
		sb(push_swap);
	else
		return ;
}

static void	three_args_a(t_push_swap	*push_swap)
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

static void	four_args(t_push_swap	*push_swap)
{
	pb(push_swap);
	three_args_a(push_swap);
	shifting(push_swap);
	pa(push_swap);
	backshifting(push_swap);
}

static void	shifting(t_push_swap	*push_swap)
{
	t_list	*tempa;
	t_list	*tempb;

	tempa = push_swap->stack_a;
	tempb = push_swap->stack_b;
	if (tempb->content > ft_lstlast(tempa)->content)
		return ;
	else
		while (tempb->content > tempa->content)
		{
			ra(push_swap);
			tempa = push_swap->stack_a;
		}
			
}

static void	backshifting(t_push_swap	*push_swap)
{
	while (!right_order_a(push_swap))
		ra(push_swap);
}

static int	right_order_a(t_push_swap	*push_swap)
{
	t_list	*temp;
	t_list	*temp2;

	temp = push_swap->stack_a;
	temp2 = push_swap->stack_a->next;
	while (temp && temp2 && temp->content < temp2->content)
	{
		temp = temp2;
		temp2 = temp2->next;
	}
	if (temp == ft_lstlast(push_swap->stack_a) && !push_swap->stack_b)
		return (2);
	else if (temp == ft_lstlast(push_swap->stack_a))
		return (1);
	else
		return (0);
}

// static int	right_order_b(t_push_swap	*push_swap)
// {
// 	t_list	*temp;
// 	t_list	*temp2;

// 	temp = push_swap->stack_b;
// 	temp2 = push_swap->stack_b->next;
// 	while (temp && temp2 && temp->content > temp2->content)
// 	{
// 		temp = temp2;
// 		temp2 = temp2->next;
// 	}
// 	if (temp == ft_lstlast(push_swap->stack_b))
// 		return (1);
// 	else
// 		return (0);
// }

static void	five_args(t_push_swap	*push_swap)
{
	pb(push_swap);
	pb(push_swap);
	three_args_a(push_swap);
	two_args_b(push_swap);
	shift2(push_swap);
	ft_printf("%i\n", right_order_a(push_swap));
	
}

static void shift2(t_push_swap	*push_swap)
{
	while(right_order_a(push_swap) != 2)
	{
		if (push_swap->stack_b->content > ft_lstlast(push_swap->stack_b)->content)
		{
			pa(push_swap);
			ra (push_swap);
		}
		else if (push_swap->stack_b->content < push_swap->stack_a->content)
			pa(push_swap);
		else
			ra(push_swap);
	}
	
	
}

// void	quicksort(t_push_swap	*push_swap)
// {
// 	t_list	*pivot;

// 	pivot = ft_lstlast(push_swap->stack_a);
// 	while ()
// }