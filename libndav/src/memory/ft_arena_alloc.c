/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/11/05 16:21:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

static t_list	**_arena_head(void)
{
	static t_list	*arena_head = NULL;

	if (arena_head == NULL)
		arena_head = ft_lstnew(malloc(ARENA_BLOCK_SIZE));
	return (&arena_head);
}

static void	_del_block(void *block)
{
	if (block != NULL)
		free(block);
	block = NULL;
}

void	ft_free_arena(void)
{
	ft_lstclear(_arena_head(), _del_block);
}

void	*ft_arena_alloc(size_t size)
{
	t_list			**arena;
	size_t			block_size;
	static size_t	pos = 0;

	arena = _arena_head();
	if ((*arena) == NULL)
		return (NULL);
	block_size = ARENA_BLOCK_SIZE;
	if (pos + size > block_size)
	{
		while (size > block_size)
			block_size *= 2;
		ft_lstadd_front(arena, ft_lstnew(malloc(block_size)));
		if ((*arena) == NULL)
			return (NULL);
		pos = 0;
	}
	pos += size;
	return ((*arena)->content + pos - size);
}

// void	*ft_block(size_t size)
// {
// 	static char		block[ARENA_BLOCK_SIZE];
// 	static size_t	pos = 0;

// 	pos += size;
// 	return (block + pos - size);
// }

// int main(int argc, char const *argv[])
// {
// 	int i =0;
// 	char *string;

// 	while (i<30)
// 	{
// 		string = ft_arena_alloc(300);
// 		i++;
// 	}
// 	ft_free_arena();
// 	return 0;
// }
