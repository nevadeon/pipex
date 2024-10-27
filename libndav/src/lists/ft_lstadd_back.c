/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:28:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:18:49 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	if (*lst == NULL)
		*lst = new_node;
	else
		ft_lstlast(*lst)->next = new_node;
}
