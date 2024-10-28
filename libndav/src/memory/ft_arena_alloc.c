/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/28 11:11:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

static t_list	*_arena_head(void)
{
	static t_list	*arena_head = NULL;

	if (arena_head == NULL)
		arena_head = ft_lstnew(malloc(ARENA_BLOCK_SIZE));
	return (arena_head);
}

static t_list	*_new_block(t_list *list, size_t size)
{
	ft_lstadd_back(&list, ft_lstnew(malloc(size)));
	return (list->next);
}

static void	_del_block(void *block)
{
	if (block != NULL)
		free(block);
	block = NULL;
}

void	ft_free_arena(void)
{
	t_list	*arena;

	arena = _arena_head();
	ft_lstclear(&arena, _del_block);
}

void	*ft_arena_alloc(size_t size)
{
	t_list			*arena_tail;
	size_t			block_size;
	static size_t	pos = 0;

	arena_tail = ft_lstlast(_arena_head());
	if (arena_tail == NULL)
		return (NULL);
	block_size = ARENA_BLOCK_SIZE;
	if (pos + size > block_size)
	{
		while (size > block_size)
			block_size *= 2;
		arena_tail = _new_block(arena_tail, size);
		if (arena_tail == NULL)
			return (NULL);
		pos = 0;
	}
	pos += size;
	return (arena_tail->content + pos - size);
}
