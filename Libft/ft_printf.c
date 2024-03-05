/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 09:48:24 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/28 11:57:13 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_printf(va_list args, const char *format)
{
	int	counter;

	counter = 0;
	if (*format == '\0')
		return (-1);
	else if (*format == '%')
		counter += ft_putchar_i('%');
	else if (*format == 'c')
		counter += ft_putchar_i(va_arg(args, int));
	else if ((*format == 'd' ) | (*format == 'i'))
		counter += ft_putnb_i(va_arg(args, int));
	else if (*format == 's')
		counter += ft_putstr_i(va_arg(args, char *));
	else if (*format == 'u')
		counter = counter + ft_utoa(va_arg(args, unsigned int));
	else if ((*format == 'X') | (*format == 'x'))
		counter = counter + ft_ithex((va_arg(args, int)), format);
	else if (*format == 'p')
		counter += ft_pointhex(va_arg(args, unsigned long));
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		verification;

	counter = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			verification = ft_format_printf(args, format);
			if (verification > -1)
				counter = counter + verification;
			else
				return (-1);
		}
		else
			counter += ft_putchar_i(*format);
		format++;
	}
	va_end(args);
	return (counter);
}

// int main()
// {
// 	char *p = "string";
	// ft_printf("%c%c%d%c\n", 'a', 'b', 3, '%');
	// ft_printf("%c%c%d%s\n", 'a', 'b', 3, "bla");
	// ft_printf("ble%c%c%i%sbla%%%x\n", 'a', 'b', 120, "foo", 5151);
	// ft_printf("%%\n");
	// ft_printf("ble%c%c%i%sbla%%%X\n", 'a', 'b', 120, "foo", 5151);
	// printf("%%\n");
	// printf("%d\n", printf("hello"));
	// printf("%d\n", ft_printf("hello"));
	// int  original = printf("%\0 ujruiturtiyut");
	// int my_len = ft_printf("%\0 ujruiturtiyut");
	// printf("%d, %d", original, my_len);
	// int original = printf("%%%");
	// int my_len = ft_printf("%%%");
	// printf("this is original %d,this is my %d", original, my_len);
	// int original = printf("%p", NULL);
	// int my_len = ft_printf("%p", NULL);
	// printf("this is original %d,this is my %d", original, my_len);
	// int original = printf("%c\n", 0);
	// int my_len = ft_printf("%c\n", 0);
// 	printf("this is original %d,this is my %d", original, my_len);
// }