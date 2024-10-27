/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:23 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:19:45 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL && del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
