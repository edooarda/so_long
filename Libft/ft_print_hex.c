/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 13:25:58 by edribeir      #+#    #+#                 */
/*   Updated: 2023/11/28 12:04:09 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_long(unsigned long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_ithex(unsigned int n, char const *format)
{
	char			*hex;
	unsigned int	len;
	char			*hex_base;

	if (*format == 'X')
		hex_base = "0123456789ABCDEF";
	else if (*format == 'x')
		hex_base = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar_i('0'));
	else
	{
		len = nb_long(n);
		hex = (char *)ft_calloc((len + 1), sizeof(char));
		while (n > 0)
		{
			len--;
			hex[len] = hex_base[n % 16];
			n = n / 16;
		}
		len = ft_putstr_i(hex);
		free(hex);
	}
	return (len);
}

int	ft_pointhex(unsigned long n)
{
	unsigned long	len_n;
	char			*str_phex;
	char			*hex;

	hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr_i("(nil)"));
	else
	{
		len_n = nb_long(n) + 2;
		str_phex = malloc((len_n + 1) * sizeof(char));
		if (str_phex == NULL)
			return (0);
		str_phex[0] = '0';
		str_phex[1] = 'x';
		str_phex[len_n] = '\0';
		while (n > 0)
		{
			str_phex[--len_n] = hex[n % 16];
			n = n / 16;
		}
		len_n = ft_putstr_i(str_phex);
		free(str_phex);
	}
	return (len_n);
}
