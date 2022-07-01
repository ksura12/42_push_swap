/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:43 by ksura             #+#    #+#             */
/*   Updated: 2022/06/29 11:15:43 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/push_swap.h"

static void	core_checkfordigit(char *argv, t_push_swap	*push_swap);
static void	checkformaxandmin(char	**argv, t_push_swap	*push_swap);
static void	checkfordigit(char **argv, t_push_swap	*push_swap);
static void	checkfordubs(char **argv, t_push_swap	*push_swap);

void	input_errors(char **argv, t_push_swap	*push_swap)
{
	checkfordigit(argv, push_swap);
	checkfordubs(argv, push_swap);
	checkformaxandmin(argv, push_swap);
}

static void	checkfordigit(char **argv, t_push_swap	*push_swap)
{
	int	c;

	c = 1;
	while (argv[c])
	{
		core_checkfordigit(argv[c], push_swap);
		if (push_swap->error != 0)
		{
			ft_printf("ERROR");
			exit(0);
		}
		c++;
	}
}

static void	core_checkfordigit(char *argv, t_push_swap	*push_swap)
{
	int	d;

	d = 0;
	while (argv[d])
	{
		if (argv[d] == '+' || argv[d] == '-')
		{
			if (!ft_isdigit(argv[d + 1]))
			{
				push_swap->error = 1;
				write(2, "Error\n", 6);
				exit(0);
			}
			d++;
		}
		if (ft_isdigit(argv[d]))
			d++;
		else
		{
			push_swap->error = 1;
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

static void	checkfordubs(char **argv, t_push_swap	*push_swap)
{
	int	c;
	int	j;

	c = 1;
	j = 1;
	while (argv[c + 1])
	{
		j = c + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[c]) == ft_atoi(argv[j]))
			{
				push_swap->error = 2;
				write(2, "Error\n", 6);
				exit(0);
			}
			else
				j++;
		}
		c++;
	}
}

static void	checkformaxandmin(char	**argv, t_push_swap	*push_swap)
{
	int	c;

	c = 1;
	while (argv[c])
	{
		if (atol(argv[c]) > INT_MAX || atol(argv[c]) < INT_MIN)
		{
			push_swap->error = 3;
			write(2, "Error\n", 6);
			exit(0);
		}
		c++;
	}
}
