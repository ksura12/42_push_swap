/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:21:46 by ksura             #+#    #+#             */
/*   Updated: 2022/07/04 15:08:47 by ksura@student.42 ###   ########.fr       */
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
	int size;
	
	find_pindex(push_swap->stack_a);
	temp = push_swap->stack_a;
	while (temp != 0)
	{
		if (temp->pindex == ft_stacksize(push_swap->stack_a) / 2)
		{
			pivot = temp;
			break;
		}
		temp = temp->next;
	}
	c = 0;
	size = ft_stacksize(push_swap->stack_a);
	while (c <= size)
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
	find_index(push_swap->stack_a);
	while (ft_stacksize(push_swap->stack_a) > 5)
	{
		pivot_to_b(push_swap);
		// printing_stacks(push_swap);
		find_pos(push_swap->stack_a);
		find_pos(push_swap->stack_b);
		target_pos(push_swap);
		calc_cost_b(push_swap);
		// printing_stacks(push_swap);
	}
	if (ft_stacksize(push_swap->stack_a) == 2)
		two_args_a(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 3)
		three_args_a(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 4)
		four_args(push_swap);
	else if (ft_stacksize(push_swap->stack_a) == 5)
		five_args(push_swap);
	while (ft_stacksize(push_swap->stack_b) > 0)
	{
		find_pos(push_swap->stack_a);
		find_pos(push_swap->stack_b);
		target_pos(push_swap);
		calc_cost_b(push_swap);
		// printing_stacks(push_swap);
		best_move(push_swap);
		// printing_stacks(push_swap);	
	}
	ordering_a(push_swap);
	// printing_stacks(push_swap);
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

void find_pindex(t_stack *stack_a)
{
	t_stack *temp;
	t_stack *lowest;
	int index;
	int count;

	index = 1;
	temp = stack_a;
	while(temp)
	{
		temp->pindex = -1;
		temp = temp->next;
	}
	while (index <= ft_stacksize(stack_a))
	{
		count = 0;
		temp = stack_a;
		lowest = temp;
		while (temp != NULL)
		{
			if (temp->value < lowest->value && temp->pindex == -1)
				lowest = temp;
			else if (lowest->pindex != -1)
				lowest = temp;
			temp = temp->next;
			count++;
		}
		lowest->pindex = index;
		// ft_printf("pindex: %d	value: %d\n", lowest->pindex, lowest->value);
		index++;
	}
}

void	find_pos(t_stack	*stack)
{
	t_stack *temp;
	int pos;
	
	// ft_printf("neuerStack\n");
	pos = 0;
	temp = stack;
	while (temp)
	{
		temp->pos = pos;
		temp = temp->next;
		// ft_printf("pos: %d	value: %d\n", temp->pos, temp->value);
		pos++;
	}
}

void	target_pos(t_push_swap	*push_swap)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target;

	temp_b = push_swap->stack_b;
	
	while (temp_b)
	{
		temp_a = push_swap->stack_a;
		target = ft_calloc(1, sizeof(t_stack));
		target->index = INT_MAX;
		while (temp_a)
		{
			if (temp_a->index > temp_b->index && temp_a->index < target->index)
				target = temp_a;
			temp_a = temp_a->next;
		}
		temp_b->tar_pos = target->pos;
		temp_b = temp_b->next;
		// free(target);
	}
	
}

void	calc_cost_b(t_push_swap	*push_swap)
{
	t_stack	*temp_b;
	t_stack	*temp_a;
	
	temp_b = push_swap->stack_b;
	calc_cost_a(push_swap);
	while (temp_b)
	{
		if (temp_b->pos <= (ft_stacksize(push_swap->stack_b) / 2))
			temp_b->cost_b = temp_b->pos;
		else if (temp_b->pos > (ft_stacksize(push_swap->stack_b) / 2))
		{
			temp_b->cost_b = (temp_b->pos 
			-ft_stacksize(push_swap->stack_b));
		}
		temp_a = push_swap->stack_a;
		while (temp_a)
		{
			if (temp_a->pos == temp_b->tar_pos)
				temp_b->cost_a = temp_a->cost_a;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
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

void	bringbback(t_push_swap	*push_swap, t_stack *lowest_cost)
{
	while (lowest_cost->cost_a > 0 && lowest_cost->cost_b > 0)
	{
		rr(push_swap);
		lowest_cost->cost_a--;
		lowest_cost->cost_b--;
	}
		
	while (lowest_cost->cost_a < 0 && lowest_cost->cost_b < 0)
	{
		rrr(push_swap);
		lowest_cost->cost_a++;
		lowest_cost->cost_b++;
	}
	while (lowest_cost->cost_a > 0)
	{
		ra(push_swap);
		lowest_cost->cost_a--;
	}
		
	while (lowest_cost->cost_a < 0)
	{
		rra(push_swap);
		lowest_cost->cost_a++;
	}
	while (lowest_cost->cost_b > 0)
	{
		rb(push_swap);
		lowest_cost->cost_b--;
	}
	while (lowest_cost->cost_b < 0)
	{
		rrb(push_swap);
		lowest_cost->cost_b++;
	}
	pa(push_swap);
}

	void best_move(t_push_swap *push_swap)
{
	int total_cost;
	t_stack	*lowest_cost;
	t_stack	*temp_b;
	
	temp_b = push_swap->stack_b;
	total_cost = INT_MAX;
	while(temp_b)
	{
		if (total_cost > (abs(temp_b->cost_a) + abs(temp_b->cost_b)))
		{
			total_cost = abs(temp_b->cost_a) + abs(temp_b->cost_b);
			lowest_cost = temp_b;
		}
		temp_b = temp_b->next;
	}
	// ft_printf("VALUE of lowest: %d\n", lowest_cost->value);
	bringbback(push_swap, lowest_cost);
}

int	abs(int c)
{
	if (c < 0)
		return (c* -1);
	else
		return (c);
}

void	ordering_a(t_push_swap	*push_swap)
{
	int		count;
	t_stack	*temp;
	
	count = 0;
	temp = push_swap->stack_a;
	while (temp && temp->index != 1)
	{
		count++;
		temp = temp->next;
	}
	if (count > ft_stacksize(push_swap->stack_a) / 2)
	{
		while(count < (ft_stacksize(push_swap->stack_a)))
		{
			rra(push_swap);
			count++;
		}
	}
	else
	{
		while (count-- > 0)
			ra(push_swap);
	}
}