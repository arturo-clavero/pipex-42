/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:39:20 by artclave          #+#    #+#             */
/*   Updated: 2024/01/16 19:02:46 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd_argv, char *envp_argv[])
{
	char	**cmd_arr;
	char	*cmd_path;
	char	**env;

	env = get_env_path(envp_argv);
	cmd_arr = get_cmd_array_for_exc(cmd_argv);
	cmd_path = get_cmd_path_for_exc(cmd_arr, env);
	execve(cmd_path, cmd_arr, env);
	perror(cmd_arr[0]);
	exit(CMD_ERR);
}

void	last_command(char *argv_cmd, char **argv_envp, int *fd_file)
{
	int	id;

	id = fork();
	if (id == -1)
		handle(FORK_ERR);
	if (id == 0)
	{
		if (dup2(fd_file[STDOUT_FILENO], STDOUT_FILENO) == -1)
			handle(DUP_ERR);
		close(fd_file[STDOUT_FILENO]);
		execute(argv_cmd, argv_envp);
	}
	else
		close(fd_file[STDOUT_FILENO]);
}

void	create_pipe(char *argv_cmd, char **argv_envp)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle(PIPE_ERR);
	id = fork();
	if (id == -1)
		handle(FORK_ERR);
	if (id == 0)
	{
		close(fd[STDIN_FILENO]);
		if (dup2(fd[STDOUT_FILENO], STDOUT_FILENO) == -1)
			handle(DUP_ERR);
		close(fd[1]);
		execute(argv_cmd, argv_envp);
	}
	else
	{
		close(fd[STDOUT_FILENO]);
		if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == -1)
			handle(DUP_ERR);
		close(fd[STDIN_FILENO]);
	}
}

int	main(int ac, char **av, char *envp[])
{
	int	i;
	int	fd_file[2];

	if (ac < 5)
		handle(AC_ERR);
	check_permissions_and_open(&(fd_file), av, ac);
	if (dup2(fd_file[0], STDIN_FILENO) == -1)
		handle(DUP_ERR);
	close(fd_file[STDIN_FILENO]);
	i = -1;
	while (++i < ac - 4)
		create_pipe(av[i + 2], envp);
	last_command(av[ac - 2], envp, fd_file);
	exit(SUCCESS);
}
