/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:06:26 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:53:02 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while ((unsigned char) s[i] != (unsigned char) c && i)
		i--;
	if ((unsigned char) s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}
