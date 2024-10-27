/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:53:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:40:46 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

static void	_recursive(int fd, long l)
{
	if (l >= 10)
		_recursive(fd, l / 10);
	ft_dputchar(fd, l % 10 + '0');
}

void	ft_dputnbr(int fd, int n)
{
	long	l;

	l = (long) n;
	if (l < 0)
	{
		ft_dputchar(fd, '-');
		l = -l;
	}
	_recursive(fd, l);
}
