/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:45:26 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:34:37 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const t_byte	*s;
	t_byte			*d;

	if (n != 0 && (dest == src))
		return (dest);
	s = (const t_byte *)src;
	d = (t_byte *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
