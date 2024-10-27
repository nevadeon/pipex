/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:25:12 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:40:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

size_t	ft_dputptr(int fd, void *p)
{
	if (p == NULL)
		return (ft_dputstr(fd, "(nil)"));
	ft_dputstr(fd, "0x");
	return (ft_dputulbase(fd, (size_t) p, HEXA_LOW) + 2);
}
