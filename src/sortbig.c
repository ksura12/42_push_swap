/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:21:46 by ksura             #+#    #+#             */
/*   Updated: 2022/06/10 17:50:01 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void bringingbback(t_push_swap	*push_swap);
void sortchunk(t_push_swap	*push_swap);

void	pivot_to_b(t_push_swap	*push_swap)
{
	t_list	*pivot;

	pivot = ft_lstlast(push_swap->stack_a);
	while (push_swap->stack_a != pivot)
	{
		if (push_swap->stack_a->content < pivot->content)
			pb(push_swap);
		else
			ra(push_swap);
	}
	pb(push_swap);
	push_swap->stack_b->chunk = 1;
}

void	sortbig(t_push_swap	*push_swap)
{
	while (ft_lstsize(push_swap->stack_a) > 5)
	{
		pivot_to_b(push_swap);
		printing_stacks(push_swap);
	}
	if (ft_lstsize(push_swap->stack_a) == 2)
		two_args_a(push_swap);
	else if (ft_lstsize(push_swap->stack_a) == 3)
		three_args_a(push_swap);
	else if (ft_lstsize(push_swap->stack_a) == 4)
		four_args(push_swap);
	else if (ft_lstsize(push_swap->stack_a) == 5)
		five_args(push_swap);
	bringingbback(push_swap);
}

void bringingbback(t_push_swap	*push_swap)
{
	
	while (push_swap->stack_b)
	{
		pa(push_swap);
		sortchunk(push_swap);
	}
	
}

void sortchunk(t_push_swap	*push_swap)
{
	t_list	*temp;
	int		chunksize;
	t_list	*biggest;
	int		chunkpos;
	
	chunksize = 0;
	chunkpos = 0;
	temp = push_swap->stack_b;
	biggest = temp;
	ft_printf("vor while%i\n", chunkpos);
	while(push_swap->stack_b->chunk < 1 && push_swap->stack_b)
	{
		
		chunksize++;
		if(push_swap->stack_b->content >= biggest->content)
		{
			biggest = push_swap->stack_b;
			chunkpos = chunksize;
		}
		push_swap->stack_b = push_swap->stack_b->next;
		ft_printf("after while%i\n", chunkpos);
	}
	if (chunkpos-- == 1)
		pa(push_swap);
	else if (chunkpos >= 2)
	{
		while(chunkpos > 2)
		{
			rb(push_swap);
			chunkpos--;
		}
		sb(push_swap);
		pa(push_swap);
		chunkpos--;
	}
}