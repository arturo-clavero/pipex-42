/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:36:49 by artclave          #+#    #+#             */
/*   Updated: 2024/01/16 19:06:03 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle(int error)
{
	if (error == AC_ERR)
		perror("Not enough arguments\n");
	if (error == FILE1_ERR)
		perror("Invalid input file\n");
	if (error == FILE2_ERR)
		perror("Invalid output file\n");
	if (error == PIPE_ERR)
		perror("Error calling pipe\n");
	if (error == FORK_ERR)
		perror("Error calling fork\n");
	if (error == DUP_ERR)
		perror("Error calling dup\n");
	if (error == MALLOC_ERR)
		perror("Error calling malloc\n");
	exit(error);
}

void	check_permissions_and_open(int (*fd)[2], char **av, int ac)
{
	(*fd)[0] = open(av[1], O_RDONLY, 0444);
	if ((*fd)[0] == -1)
		handle(FILE1_ERR);
	(*fd)[1] = open(av[ac -1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if ((*fd)[1] == -1)
		handle(FILE2_ERR);
}

char	**get_env_path(char *envp_argv[])
{
	int		i;
	char	**result;

	i = -1;
	while (envp_argv[++i] != NULL)
	{
		if (ft_strncmp(envp_argv[i], "PATH=", 5) == 0)
		{
			result = ft_split(envp_argv[i] + 5, ':');
			if (!result)
				handle(MALLOC_ERR);
			return (result);
		}
	}
	perror("envp does not have a PATH= string\n");
	exit(ENV_ERR);
}

char	**get_cmd_array_for_exc(char *cmd_argv)
{
	char	**result;

	ft_streplace_char(&cmd_argv, '\'', ' ');
	ft_streplace_char(&cmd_argv, '"', ' ');
	result = ft_split(cmd_argv, ' ');
	if (!result)
		handle(MALLOC_ERR);
	return (result);
}

char	*get_cmd_path_for_exc(char **cmd_arr, char **env)
{
	char	*test_path;
	int		i;

	i = -1;
	while (env[++i] != NULL)
	{
		test_path = ft_strjoin(env[i], cmd_arr[0]);
		if (access(test_path, F_OK | X_OK) == 0)
			return (test_path);
		else
			free(test_path);
	}
	perror(cmd_arr[0]);
	exit(CMD_PATH_ERR);
}
