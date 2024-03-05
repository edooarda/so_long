/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 09:47:11 by edribeir      #+#    #+#                 */
/*   Updated: 2024/01/24 15:12:14 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_utoa(unsigned int nb);
int	ft_ithex(unsigned int n, char const *format);
int	ft_pointhex(unsigned long n);
int	ft_putchar_i(int ch);
int	ft_putstr_i(char *s);
int	ft_putnb_i(int n);
int	ft_printf(const char *format, ...);

#endif