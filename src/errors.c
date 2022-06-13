/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:43 by ksura             #+#    #+#             */
/*   Updated: 2022/06/13 13:36:57 by ksura            ###   ########.fr       */
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
			exit(EXIT_FAILURE);
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
				//ft_printf("ERROR");
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			d++;
		}
		if (ft_isdigit(argv[d]))
			d++;
		else
		{
			push_swap->error = 1;
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
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
				//
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
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
			//ft_printf("ERROR");
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		c++;
	}
}
