/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:44:33 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:18:02 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (*lst != NULL)
		new_node->next = *lst;
	*lst = new_node;
}
