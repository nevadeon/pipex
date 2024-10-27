/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputulbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:02:52 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:41:03 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

static size_t	_recursive(int fd, t_ulong ul, char *base, size_t base_len)
{
	size_t	nb_printed;

	nb_printed = 0;
	if (ul >= base_len)
		nb_printed += _recursive(fd, ul / base_len, base, base_len);
	ft_dputchar(fd, base[ul % base_len]);
	return (nb_printed + 1);
}

size_t	ft_dputulbase(int fd, t_ulong ul, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	return (_recursive(fd, ul, base, base_len));
}
