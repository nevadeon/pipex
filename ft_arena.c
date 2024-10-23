/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:19:51 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/23 11:20:13 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arena(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void *ft_arena(size_t size)
{
	static void		*ptr = NULL;
	static size_t	pos = 0;

	if (!ptr)
	{
		ptr = (void *)malloc(ARENA_SIZE);
		if (!ptr)
			return (NULL);
	}
	if (pos + size > ARENA_SIZE)
	{
		free_arena(ptr);
		printf("mem error\n");
		exit(EXIT_FAILURE);
	}
	pos += size;
	return (ptr + pos - size);
}
