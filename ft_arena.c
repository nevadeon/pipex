/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:19:51 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/24 16:35:31 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_arena(ssize_t size)
{
	static void		*ptr = NULL;
	static size_t	pos = 0;

	if (ptr == NULL)
	{
		ptr = (void *)malloc(ARENA_SIZE);
		if (ptr == NULL)
			return (NULL);
	}
	if (size < 0 && ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	if (pos + (size_t) size > ARENA_SIZE)
	{
		free(ptr);
		printf("mem error\n");
		exit(EXIT_FAILURE);
	}
	pos += (size_t) size;
	return (ptr + pos - (size_t) size);
}