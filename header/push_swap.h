/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:13:31 by ksura             #+#    #+#             */
/*   Updated: 2022/06/10 16:51:41 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/header/libftprintf.h"

typedef struct s_push_swap
{
	int		error;
	int		list_length;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_push_swap;

typedef struct s_element
{
	int		value;
	int		position;
}	t_element;

/**
*@brief inot existing function
*
*@param 
*@return 
*/
int		*push_swap(int *stack_a);

/**
*@brief checks the arguments for non digits, max/mins and duplicates
*
*@param argv: argumentlist
*@param push_swap: struct which includes error_messages
*@return -
*/
void	input_errors(char **argv, t_push_swap	*push_swap);

/**
*@brief pushes first elememnt of stack a to stack b
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	pb(t_push_swap	*push_swap);

/**
*@brief pushes first elememnt of stack b to stack a
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	pa(t_push_swap	*push_swap);

/**
*@brief swaps first two elememnts of stack a
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	sa(t_push_swap *push_swap);

/**
*@brief swaps first two elememnts of stack b
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	sb(t_push_swap *push_swap);

/**
*@brief swaps first two elememnts of stack a & b
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	ss(t_push_swap *push_swap);

/**
*@brief shifting first element of a to last position in stack a
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	ra(t_push_swap	*push_swap);

/**
*@brief shifting first element of b to last position in stack b
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	rb(t_push_swap	*push_swap);

/**
*@brief shifting first element of a&b to last position in each stack
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	rr(t_push_swap	*push_swap);

/**
*@brief shifting last element of a to first position in stack a
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	rra(t_push_swap	*push_swap);

void	rrb(t_push_swap	*push_swap);

void	rrr(t_push_swap	*push_swap);

void	sorting(t_push_swap	*push_swap);

void	three_args_a(t_push_swap	*push_swap);

void	pb_lowest(t_push_swap	*push_swap);

void	five_args(t_push_swap	*push_swap);
void	pivot_to_b(t_push_swap	*push_swap);
void	printing_stacks(t_push_swap	*push_swap);

/**
*@brief sorting if more than 5 Arguments
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	sortbig(t_push_swap	*push_swap);

/**
*@brief sorting exactly 2 Arguments
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void		two_args_a(t_push_swap	*push_swap);

/**
*@brief sorting exactly 4 Arguments
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void		four_args(t_push_swap	*push_swap);
#endif
