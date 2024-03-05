/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 15:18:50 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 18:03:01 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t sizeitem)
{
	void	*dest;

	if (nitems != 0 && (nitems * sizeitem) / nitems != sizeitem)
		return (NULL);
	dest = (void *)malloc(nitems * sizeitem);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, nitems * sizeitem);
	return (dest);
}

// int main()
// {
//     unsigned int i = 0;
//     unsigned int nmemb = 3;
//     int *numbers
//     numbers =(int *)ft_calloc(nmemb, sizeof(int));
//     while(i < nmemb)
//     {
//         printf("%i", numbers[i]);
//         i++;
//     }
//     free(numbers); // to free calloc in the end of use
// }