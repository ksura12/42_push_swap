/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ruling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:10:48 by ksura             #+#    #+#             */
/*   Updated: 2022/06/08 19:32:51 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sorting(t_push_swap	*push_swap)
{
	int size;

	size = ft_lstsize(push_swap->stack_a);
	if (size == 1)
		exit(EXIT_SUCCESS);
	if (size = 2)
		two_args(push_swap);
	
}

void	two_args(t_push_swap	*push_swap)
{
	t_list	*temp;
	
	temp = push_swap->stack_a;
	if (temp->content > temp->next->content)
		sa(push_swap);
}