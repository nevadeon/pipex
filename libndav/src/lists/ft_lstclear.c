/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:39:33 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:15:03 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	node = *(lst);
	while (node != NULL)
	{
		del(node->content);
		temp = node->next;
		free(node);
		node = temp;
	}
	*lst = NULL;
}
