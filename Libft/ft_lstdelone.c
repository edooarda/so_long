/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 10:06:32 by edribeir      #+#    #+#                 */
/*   Updated: 2023/11/03 10:06:33 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst_node, void (*del)(void *))
{
	if (lst_node == NULL || del == NULL)
		return ;
	del(lst_node->content);
	free(lst_node);
}
