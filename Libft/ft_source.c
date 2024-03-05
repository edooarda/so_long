/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_source.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 10:31:39 by edribeir      #+#    #+#                 */
/*   Updated: 2023/11/29 11:50:05 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_i(int ch)
{
	if (write(1, &ch, 1) == -1)
		return (-1);
	else
		return (1);
}

int	ft_putstr_i(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_putnb_i(int n)
{
	char	*str_nb;
	int		len;

	str_nb = ft_itoa(n);
	if (!str_nb)
		return (-1);
	len = ft_putstr_i(str_nb);
	if (len == -1)
	{
		free(str_nb);
		return (-1);
	}
	free(str_nb);
	return (len);
}

static	int	nb_len(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_utoa(unsigned int nb)
{
	char			*str_number;
	unsigned int	len;
	unsigned int	str_len;

	len = nb_len(nb);
	str_number = malloc((len + 1) * sizeof(char));
	if (str_number == NULL)
		return (0);
	str_number[len] = '\0';
	if (nb == 0)
		str_number[0] = '0';
	while (nb > 0)
	{
		len--;
		str_number[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str_len = ft_putstr_i(str_number);
	free(str_number);
	return (str_len);
}
