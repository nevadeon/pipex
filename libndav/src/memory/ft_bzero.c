/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:45:26 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:35:31 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_bzero(void *s, size_t n)
{
	t_byte	*ptr;

	ptr = (t_byte *)s;
	while (n--)
		*ptr++ = (t_byte) '\0';
}
