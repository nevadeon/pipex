/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:18:27 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:50:19 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*joined_o;

	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	joined_o = joined;
	while (*s1 != '\0')
		*joined++ = *s1++;
	while (*s2 != '\0')
		*joined++ = *s2++;
	*joined = '\0';
	return (joined_o);
}
