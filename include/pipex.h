/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:57:07 by artclave          #+#    #+#             */
/*   Updated: 2024/01/09 20:27:21 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define SUCCESS 0
# define AC_ERR 2
# define PIPE_ERR 3
# define FORK_ERR 4
# define DUP_ERR 5
# define ENV_ERR 6
# define MALLOC_ERR 7
# define FILE1_ERR 8
# define FILE2_ERR 9
# define CMD_ERR 126
# define CMD_PATH_ERR 127

int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_streplace_char(char **str, char old_char, char new_char);
int		ft_strchr(const char *s, char c);
char	**ft_split(char const *s, char c);

char	*get_cmd_path_for_exc(char **cmd_arr, char **env);
char	**get_cmd_array_for_exc(char *cmd_argv);
char	**get_env_path(char *envp_argv[]);
void	check_permissions_and_open(int (*fd)[2], char **av, int ac);
void	handle(int error);

void	execute(char *cmd_argv, char *envp_argv[]);
void	create_pipe(char *argv_cmd, char **argv_envp);
int		main(int ac, char **av, char *envp[]);

#endif
