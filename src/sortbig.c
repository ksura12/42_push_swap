/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:21:46 by ksura             #+#    #+#             */
/*   Updated: 2022/07/01 11:26:26 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	bringingbback(t_push_swap	*push_swap);
void	sortchunk(t_push_swap	*push_swap);

void	pivot_to_b(t_push_swap	*push_swap)
{
	t_stack	*pivot;
	t_stack	*temp;
	int c;
	
	while (temp != 0)
	{
		if (temp->index == ft_stacksize(push_swap->stack_a) / 2)
		{
			pivot = temp;
			break;
		}
		temp = temp->next;
	}
	c = 0;
	while (c <= ft_stacksize(push_swap->stack_a))
	{
		if (push_swap->stack_a->value <= pivot->value)
			pb(push_swap);
		else
			ra(push_swap);
		c++;
	}
}

void	sortbig(t_push_swap	*push_swap)
{
	// t_stack *temp;
	
	// temp = push_swap->stack_a;
	find_index(push_swap->stack_a);
	// while (temp)
	// {
	// 	ft_printf("%i-", temp->pos);
	// 	temp = temp->next;
	// }
	while (ft_stacksize(push_swap->stack_a) > 5)
	{
		pivot_to_b(push_swap);
		printing_stacks(push_swap);
	}
	if (ft_stacksize(push_swap->stack_a) == 2)
		two_args_a(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 3)
		three_args_a(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 4)
		four_args(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 5)
		five_args(push_swap);
	find_pos(push_swap->stack_a);
	find_pos(push_swap->stack_b);
	target_pos(push_swap);
	
	calc_cost_a(push_swap);
	calc_cost_b(push_swap);
	printing_stacks(push_swap);
	bringingbback(push_swap);
	printing_stacks(push_swap);
}

void bringingbback(t_push_swap	*push_swap)
{
	
	while (push_swap->stack_b)
	{
		sortchunk(push_swap);
	}
	
}

void sortchunk(t_push_swap	*push_swap)
{
	t_stack	*temp;
	int		chunksize;
	t_stack	*biggest;
	int		chunkpos;
	int		counter;
	
	chunksize = 0;
	chunkpos = 0;
	temp = push_swap->stack_b;
	if (push_swap->stack_b == NULL)
		return ;
	biggest = temp;
	while(temp)
	{
		chunksize++;
		if(temp->value >= biggest->value)
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

void	find_index(t_stack	*stack_a)
{
	t_stack	*temp;
	t_stack	*lowest;
	int		index;
	
	index = 1;
	while (index <= ft_stacksize(stack_a))
	{
		temp = stack_a;
		lowest = temp;
		while (temp != NULL)
		{
			if (temp->value <= lowest->value && temp->index == 0)
				lowest = temp;
			else if (lowest->index != 0)
				lowest = temp;
			temp = temp->next;
		}
		lowest->index = index;
		index++;
	}
}

void	find_pos(t_stack	*stack)
{
	t_stack *temp;
	int pos;
	
	pos = 0;
	temp = stack;
	while (temp)
	{
		temp->pos = pos;
		temp = temp->next;
		pos++;
	}
}

void	target_pos(t_push_swap	*push_swap)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = push_swap->stack_b;
	while (temp_b)
	{
		temp_a = push_swap->stack_a;
		while(temp_a)
		{
			if (temp_a->index == temp_b->index + 1)
				temp_b->tar_pos = temp_a->pos;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

void	calc_cost_b(t_push_swap	*push_swap)
{
	t_stack	*temp;
	
	temp = push_swap->stack_b;
	while (temp)
	{
		if (temp->pos <= (ft_stacksize(push_swap->stack_b) / 2))
			temp->cost_b = temp->pos;
		else if (temp->pos > (ft_stacksize(push_swap->stack_b) / 2))
		{
			temp->cost_b = (temp->pos 
			-ft_stacksize(push_swap->stack_b));
		}
		temp = temp->next;
	}
}

void	calc_cost_a(t_push_swap *push_swap)
{
	t_stack	*temp;

	temp = push_swap->stack_a;
	while (temp)
	{
		if (temp->pos <= (ft_stacksize(push_swap->stack_a) / 2))
			temp->cost_a = temp->pos;
		else if (temp->pos > (ft_stacksize(push_swap->stack_a) / 2))
		{
			temp->cost_a = (temp->pos - ft_stacksize(push_swap->stack_a));
		}
		temp = temp->next;
	}
}
void adding_cost