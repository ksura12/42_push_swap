/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:12:17 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 17:43:36 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	error_handling(argv[c]);

// int	*push_swap(int *stack_a)
// {
// //check for errors (is_allnum, is_allint, )

	
// }

//ERROR Handling

// int	errorhandling(char *argv[int c])
// {
// 	if (argv[c][0] == ('+' || '-') && argv[c][1] )
// }
#include"stdio.h"
#include"stdlib.h"
#include"ctype.h"
#include <string.h>
#include "../header/push_swap.h"
 
void 	init_push_swap(t_push_swap	*push_swap);
void	llist_filling(char	**argv, t_push_swap	*push_swap);
void	printing_stacks(t_push_swap	*push_swap);
void	freeing_llist(t_push_swap	*push_swap);


// void *printing(int value);
 
int main(int argc, char **argv)
{

	t_push_swap	*push_swap;

	if (argc > 1)
	{
		push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
		if (!push_swap)
			exit(1);
		init_push_swap(push_swap);
		checkfordigit(argv, push_swap);
		checkfordubs(argv, push_swap);
		checkformaxandmin(argv, push_swap);
		llist_filling(argv, push_swap);
		printing_stacks(push_swap);
		sa(push_swap);
		printing_stacks(push_swap);
		// ra(push_swap);
		rra(push_swap);
		printing_stacks(push_swap);
		pb(push_swap);
		printing_stacks(push_swap);
		pb(push_swap);
		pb(push_swap);
		printing_stacks(push_swap);
		ss(push_swap);
		printing_stacks(push_swap);
		rr(push_swap);
		printing_stacks(push_swap);
		rrr(push_swap);
		printing_stacks(push_swap);
		pa(push_swap);
		printing_stacks(push_swap);
		
		// ft_lstiter(a_stack, printing(a_stack->content));
		freeing_llist(push_swap);
		free(push_swap);
		return (0);
	}
}

void 	init_push_swap(t_push_swap	*push_swap)
{
	push_swap->error = 0;
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
}

void	freeing_llist(t_push_swap	*push_swap)
{
	t_list	*temp;
	
	while (push_swap->stack_a != NULL)
	{
		temp = push_swap->stack_a;
		push_swap->stack_a = push_swap->stack_a->next;
		free(temp);
		//free(push_swap);
		
	}
}

void	llist_filling(char	**argv, t_push_swap	*push_swap)
{
	t_list *stack_node;
	int	c;

	c = 1;
	while(argv[c])
	{
		stack_node = ft_lstnew(ft_atoi(argv[c]));
		ft_lstadd_back(&push_swap->stack_a, stack_node);
		c++;
	}
	push_swap->list_length = c;
}

void	printing_stacks(t_push_swap	*push_swap)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		count;

	a_stack = push_swap->stack_a;
	b_stack = push_swap->stack_b;
	count = 1;
	while (a_stack || b_stack)
	{
		if(a_stack && b_stack)
		{
			ft_printf("Node %i:	 %d	%d\n",count, a_stack->content, b_stack->content);
			a_stack = a_stack->next;
			b_stack = b_stack->next;
			count++;
		}
		else if (!a_stack && b_stack)
		{
			ft_printf("Node %i:	 -	%d\n",count, b_stack->content);
			b_stack = b_stack->next;
			count++;
		}
		else if (a_stack && !b_stack)
		{
			ft_printf("Node %i:	 %d	-\n",count, a_stack->content);
			a_stack = a_stack->next;
			count++;
		}
		
	}
	ft_printf("	__	__\n");
	ft_printf("	A	B\n");
}


//Objectives


// sort Values of a in ascending order
// Use as less operations as possible
// operation-time doesn't matter that much
// writing access only to the first two values and the last of each stack
// reading acces to all values of the list



//Thoughts

/*
Fist Value in a:
1. lowest Value in a
1.1 move to b (if others are not in order)
1.1.1 highest Value in b
1.1.1.1 
1.1.2 lowest Value in b
1.1.3 inbetween
1.2 end when all in order and b empty
2. highest Value
3. inbetweeen ->
*/

//rules
/*
Stack a: ascending order
Stack b: decending order to push and have a accending

*/
//


//actions 

//sa (swap a): Swap the first 2 elements at the top of stack a.
//				Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// 				Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// 				Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// 				Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// 				The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// 				The first element becomes the last one.
// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// 				The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// 				The last element becomes the first one.
// rrr : rra and rrb at the same time.