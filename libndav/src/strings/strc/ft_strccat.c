/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:08:51 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:45:24 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_strccat(char *dest, const char *src, char c, bool include_char)
{
	while (*dest)
		dest++;
	while (*src && *src != c)
		*dest++ = *src++;
	if (include_char == true && *src == c)
		*dest++ = *src++;
	*dest = '\0';
}
