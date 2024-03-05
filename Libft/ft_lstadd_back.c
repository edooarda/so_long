/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 10:04:49 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/01 17:54:53 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst_head, t_list *new_node)
{
	t_list	*pointer_end;

	if (*lst_head || new_node)
	{
		if (*lst_head == NULL)
			*lst_head = new_node;
		else
		{
			pointer_end = ft_lstlast(*lst_head);
			pointer_end->next = new_node;
		}
		return ;
	}
}
