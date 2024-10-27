/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:11:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 00:40:03 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

static size_t	_dprintarg(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_dputchar(fd, (unsigned char) va_arg(args, int)));
	else if (c == 's')
		return (ft_dputstr(fd, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_dputptr(fd, va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_dputlbase(fd, (long) va_arg(args, int), DEC));
	else if (c == 'u')
		return (ft_dputulbase(fd, (t_ulong) va_arg(args, t_uint), DEC));
	else if (c == 'x')
		return (ft_dputulbase(fd, (t_ulong) va_arg(args, t_uint), HEXA_LOW));
	else if (c == 'X')
		return (ft_dputulbase(fd, (t_ulong) va_arg(args, t_uint), HEXA_UPP));
	else if (c == '%')
		return (ft_dputchar(fd, '%'));
	return (0);
}

size_t	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	size_t	nb_printed;

	nb_printed = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
			nb_printed += _dprintarg(fd, *(++format), args);
		else
			nb_printed += ft_dputchar(fd, *format);
		format++;
	}
	va_end(args);
	return (nb_printed);
}
