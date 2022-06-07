/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:12:17 by ksura             #+#    #+#             */
/*   Updated: 2022/06/07 09:10:15 by ksura            ###   ########.fr       */
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
 #include"/Users/ksura/Documents/ksura_code/PUSHSWAP/42rep/libftprintf/header/libftprintf.h"
 #include"/Users/ksura/Documents/ksura_code/PUSHSWAP/42rep/header/push_swap.h"
 
void 	init_push_swap(t_push_swap	*push_swap);
void	checkfordigit(char **argv, t_push_swap	*push_swap);
void	checkfordubs(char **argv, t_push_swap	*push_swap);
 
int main(int argc, char **argv)
{
	// int count;
	
	// if (error_handling(argv[count]))

	// if (argc == 1)
	// 	return (1);
	
	t_push_swap	*push_swap;
	
	if (argc > 1)
	{
		push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
		if (!push_swap)
			exit(1);
		init_push_swap(push_swap);
	}
	checkfordigit(argv, push_swap);
	checkfordubs(argv, push_swap);
	checkformaxandmin(argv, push_swap);
	if (push_swap > 0)
		printf("Error\n");

	return (0);
}

void 	init_push_swap(t_push_swap	*push_swap)
{
	push_swap->error = 0;
}

void	checkfordigit(char **argv, t_push_swap	*push_swap)
{
	int c;
	int inti;
	int d;
	
	c = 1;
	while (argv[c])
	{
		d = 0;
		while(argv[c][d])
		{
			if (argv[c][d] == '+' || argv[c][d] == '-')
				{
					if (!isdigit(argv[c][d + 1]))
					{
						push_swap->error = 1;
						return;
					}
					d++;
				}
			if (isdigit(argv[c][d]))
			{
				printf ("%c", argv[c][d]);
				d++;
			}
			else
			{
				push_swap->error = 1;
				return ;
			}
		}
		c++;
		printf ("\n");
	}	
}

void	checkfordubs(char **argv, t_push_swap	*push_swap)
{
	int c;
	int j;

	c = 1;
	j = 1;
	while(argv[c + 1])
	{
		j = c + 1;
		while (argv[j])
		{
			if (atoi(argv[c]) == atoi(argv[j]))
			{
			push_swap->error = 2;
				return;
			}
			else
				j++;
		}
		c++;
	}
}

void	checkformaxandmin(char	**argv, t_push_swap	*push_swap)
{
	int c;

	c = 1;
	while (argv[c])
	{
		if(atol(argv[c] > INT_MAX || argv[c] < INT_MIN))
		{
			push_swap->error = 3;
			return;
		}
		c++;
	}
}

int	*llist_filling(char	**argv, t_push_swap	*push_swap)
{
	
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