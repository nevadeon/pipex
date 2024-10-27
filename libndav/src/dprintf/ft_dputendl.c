/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:15 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:40:37 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_dputendl(int fd, char *s)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	ft_dputchar(fd, '\n');
}
