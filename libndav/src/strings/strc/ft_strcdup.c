/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:10:40 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:45:21 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

char	*ft_strcdup(const char *str, char c, bool include_char)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strclen(str, c, include_char);
	copy = (char *) malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}
