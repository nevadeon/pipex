/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:10:52 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:35:07 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const t_byte	*s;
	t_byte			*d;

	if (n != 0 && (dest == src))
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	s = (const t_byte *)src;
	d = (t_byte *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
