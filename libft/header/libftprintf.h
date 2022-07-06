/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:21:39 by ksura             #+#    #+#             */
/*   Updated: 2022/07/05 10:26:11 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

//PRINTF
char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_hexlow(va_list list, char ca);
int		print_point(va_list	list);
int		print_str(va_list	list);
int		print_char(va_list	list);
int		print_num(va_list	list);
int		print_unum(va_list	list);
int		write_char(char c);
#endif