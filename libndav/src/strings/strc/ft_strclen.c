/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:09:48 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:45:31 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

size_t	ft_strclen(const char *str, char c, bool include_char)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (include_char == true && str[i] == c)
		i++;
	return (i);
}
