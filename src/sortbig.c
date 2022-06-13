/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:21:46 by ksura             #+#    #+#             */
/*   Updated: 2022/06/13 18:15:55 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void bringingbback(t_push_swap	*push_swap);
void sortchunk(t_push_swap	*push_swap);

void	pivot_to_b(t_push_swap	*push_swap)
{
	t_list	*pivot;
	if (push_swap->stack_b)
		push_swap->stack_b->chunk = 1;
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
		//printing_stacks(push_swap);
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
		//ft_printf("bringin b back\n");
		// if (push_swap->stack_a->chunk == 1)
		// 	pa(push_swap);
		sortchunk(push_swap);
	}
	
}

void sortchunk(t_push_swap	*push_swap)
{
	t_list	*temp;
	int		chunksize;
	t_list	*biggest;
	int		chunkpos;
	int		counter;
	
	chunksize = 0;
	chunkpos = 0;
	temp = push_swap->stack_b;
	if (push_swap->stack_b == NULL)
		return ;
	biggest = temp;
	
	//printing_stacks(push_swap);
	
	while(temp)
	{
		chunksize++;
		if(temp->content >= biggest->content)
		{
			biggest = temp;
			chunkpos = chunksize;
		}
		temp = temp->next;
	}
	if (chunkpos == 1)
	{
		pa(push_swap);
	}
	else if (chunkpos >= 2)
	{
		counter = 0;
		while(chunkpos > 2)
		{
			rb(push_swap);
			counter++;
			chunkpos--;
		}
		sb(push_swap);
		pa(push_swap);
		while (counter > 0)
		{
			rrb(push_swap);
			counter--;
		}
	}
}