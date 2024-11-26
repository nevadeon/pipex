/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/11/26 14:12:16 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error :");
	exit(EXIT_FAILURE);
}

void	print_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	check_args(argc, argv);
	open_files(&p, argc, argv);
	p.env_paths = parse_env_paths(envp);
	p.cmds = parse_cmds(argc, argv);
	p.cmd_count = argc - 3;
	executing(&p, envp);
	// int i = -1;
	// while (p.cmds[++i] != NULL)
	// {
	// 	print_string_tab(p.cmds[i]);
	// 	printf("-----------\n");
	// }
	// print_string_tab(p.env_paths);
	// printf("%s\n", p.cmds[p.cmd_count - 1][0]);
	return (0);
}
