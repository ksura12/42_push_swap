/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:13:31 by ksura             #+#    #+#             */
/*   Updated: 2022/06/06 19:02:25 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN 2147483648

/**
*@brief assembles the whole line of a file to return with gnl
*
*@param rest remainding characters
*@return Pointer to location of teh line to return
*/
int	*push_swap(int *stack_a);


typedef struct s_push_swap
{
	int	error;
} t_push_swap;

#endif
