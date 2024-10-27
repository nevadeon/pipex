/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:41:45 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 11:23:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

char	*ft_itoa(int n)
{
	char	*output;
	long	n_long;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	n_long = (long) n * ((n >= 0) * 2 - 1);
	len = n < 0;
	while (n_long > 0)
	{
		n_long /= 10;
		len++;
	}
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	output[len--] = '\0';
	output[0] = '-';
	n_long = (long) n * ((n >= 0) * 2 - 1);
	while (n_long > 0)
	{
		output[len--] = (n_long % 10 + '0');
		n_long /= 10;
	}
	return (output);
}
