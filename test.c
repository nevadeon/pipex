/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/17 15:33:09 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define ARENA_SIZE 100000

void *ft_arena(size_t size, int free_b)
{
	static void		*ptr = NULL;
	static size_t	pos = 0;

	if (!ptr)
	{
		ptr = (void *)malloc(ARENA_SIZE);
		if (!ptr)
			return (NULL);
	}
	if (free_b == 1)
	{
		free(ptr);
		ptr = NULL;
		exit (0);
	}
	if (pos + size > ARENA_SIZE)
	{
		return (NULL);
	}
	pos += size;
	return (ptr + pos - size);
}

int main(void)
{
	char **tab;
	void **gc[10] = {0};
	tab = (char **)ft_arena(sizeof(char *) * 5, 0);
	gc[0] = (void *)tab;
	int i = 0;
	while (i < 5)
	{
		tab[i] = (char *)ft_arena(sizeof(char) * 2, 0);
		gc[i+1] = 	(void *)tab[i];
		tab[i][0] = 't';
		tab[i][1] = '\0';
		i++;
	}
	i = 0;
	// while (i < 5)
	// {
	// 	printf("%s\n", tab[i]);
	// 	i++;
	// }
	// i = 0;
	// while (gc[i] != NULL)
	// {
	// 	free(gc[i]);
	// 	gc[i] = NULL;
	// 	i++;
	// }
	ft_arena(0, 1);
	return (0);
}
