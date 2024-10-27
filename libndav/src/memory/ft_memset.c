/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:59:33 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:33:11 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	*ft_memset(void *s, t_byte b, int n)
{
	t_byte	*ptr;

	ptr = (t_byte *)s;
	while (n--)
		*ptr++ = b;
	return (s);
}
