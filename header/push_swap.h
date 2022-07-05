/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:13:31 by ksura             #+#    #+#             */
/*   Updated: 2022/07/05 10:20:53 by ksura@student.42 ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_push_swap;

typedef struct s_element
{
	int		value;
	int		position;
}	t_element;

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

/**
*@brief shifting last element of b to first position in stack b
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	rrb(t_push_swap	*push_swap);

/**
*@brief shifting last element of stack a&b to first position in each stack
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	rrr(t_push_swap	*push_swap);

/**
*@brief uses the fitting sorting fuction based on stacksize
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	sorting(t_push_swap	*push_swap);

/**
*@brief finds teh lowest value in stack a and pushes it to b
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	pb_lowest(t_push_swap	*push_swap);

/**
*@brief finds the pivot (middle value of stack a) and pushes every
* node which is smaler to b, rotates if the node is bigger than pivot
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	pivot_to_b(t_push_swap	*push_swap);

/**
*@brief prints the stackcontent with ft_printf()
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
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
void	two_args_a(t_push_swap	*push_swap);

/**
*@brief sorting exactly 3 Arguments
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	three_args_a(t_push_swap	*push_swap);

/**
*@brief sorting exactly 4 Arguments
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	four_args(t_push_swap	*push_swap);

/**
*@brief sorting exactly 5 Arguments
*
*@param push_swap: struct which includes head of stack a&b
*@return -
*/
void	five_args(t_push_swap	*push_swap);

/**
 *@brief indexing stack a from 1-stacksize
 *
 *@param stack_a Head if llist stack a
 *@return -
 */
void	find_index(t_stack *stack_a);

/**
 *@brief indexing stack a from 1-stacksize for choosing pivot
 *
 *@param stack_a Head if llist stack a
 *@return -
 */
void	find_pindex(t_stack *stack_a);

/**
 *@brief adding position identifieres to each node
 *
 *@param stack Head if llist stack
 *@return -
 */
void	find_pos(t_stack *stack);

/**
 *@brief adding the target position (position of 
 *the node in stack a with the closest index) to each node
 *
 *@param push_swap struct containing heads of llists a and b
 *@return -
 */
void	target_pos(t_push_swap *push_swap);

/**
 *@brief calculation the amount of movements needet to bring a node
 		up to the top on stack b
 *
 *@param push_swap struct containing heads of llists a and b
 *@return -
 */
void	calc_cost_b(t_push_swap *push_swap);

/**
 *@brief calculation the amount of movements needet to bring a node 
 		up to the top on stack a
 *
 *@param push_swap struct containing heads of llists a and b
 *@return -
 */
void	calc_cost_a(t_push_swap *push_swap);

/**
 *@brief building absolute value of the input int
 *
 *@param c	input integer
 *@return absolute integer
 */
int		abs(int c);

/**
 *@brief finding node with lowest absolut moving consts, moves it and pushes
 *
 *@param push_swap struct which holds heads of stack_a & b
 *@return -
 */
void	best_move(t_push_swap *push_swap);

/**
 *@brief  moves node with lowest costs to top and pushes
 *
 *@param push_swap struct which hold heads of stack_a and b
 *@param lowest_cost node which has lowest movement costs
 *@return -
 */
void	bringbback(t_push_swap *push_swap, t_stack *lowest_cost);

/**
 *@brief changes the orderof stack a, that the smalest number is on top
 *
 *@param push_swap struct which holds heads of stack_a & b
 *@return -
 */
void	ordering_a(t_push_swap *push_swap);
#endif
