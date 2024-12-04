/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:01:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/04 12:00:15 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*error_mesage[] = {\
		[OK] = "The impossible happened", \
		[E_FORK] = "Erreur fork:", \
		[E_PIPE] = "Erreur pipe:"
	};

	return (error_mesage[error_code]);
}

void	ft_error(t_error error_code)
{
	perror(get_error_message(error_code));
	exit(errno);
}
