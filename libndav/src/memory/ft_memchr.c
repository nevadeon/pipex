/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:51 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:31:54 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	*ft_memchr(const void *s, t_byte b, size_t n)
{
	t_byte	*ptr;

	ptr = (t_byte *) s;
	while (n--)
	{
		if (*ptr == b)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
