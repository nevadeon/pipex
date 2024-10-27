/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:32:18 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:30:40 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_byte	*ptr1;
	const t_byte	*ptr2;

	ptr1 = (const t_byte *)s1;
	ptr2 = (const t_byte *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
