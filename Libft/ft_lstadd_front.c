/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 10:05:48 by edribeir      #+#    #+#                 */
/*   Updated: 2023/11/03 10:05:53 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst_head, t_list *new_node)
{
	if (*lst_head == NULL)
	{
		*lst_head = new_node;
		return ;
	}
	if (new_node == NULL)
		return ;
	new_node->next = *lst_head;
	*lst_head = new_node;
}
