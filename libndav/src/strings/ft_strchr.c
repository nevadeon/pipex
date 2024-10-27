/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:58:14 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:48:11 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char) *s != (unsigned char) c && *s)
		s++;
	if ((unsigned char) *s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}
