/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 15:00:21 by edribeir      #+#    #+#                 */
/*   Updated: 2023/11/22 14:49:04 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			count;

	nb = n;
	count = nb_size(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	while (nb > 0)
	{
		count--;
		str[count] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

// int main()
// {
//     // printf("%s\n", ft_itoa(-3251));
//     printf("%s\n", ft_itoa(1234));
//     // char *m = ft_itoa(number);
//     printf("%s\n", ft_itoa(INT_MAX));
//     // printf("%s", ft_itoa(INT_MIN));
//     printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(0));
//     // printf("%d\n", INT_MAX); //2147483647
//     // printf("%d", INT_MIN); // -2147483648
// }