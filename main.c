/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:28:36 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/17 16:44:38 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int ac, const char **av, const char **env)
{
	char	**path_all;
	char	***cmd;
	int		status;
	pid_t	pid;

	if (ac != 5)
		return (0);
	cmd = take_cmd(av);
	path_all = take_path(cmd, env);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
		output(av, path_all, cmd);
	else 
	{
		wait(&status);
		ft_printf("\n parent\n");
		execve(path_all[1], cmd[1], NULL);
	}
	return (0);
}

void output(const char **av, char **path_all, char ***cmd)
{
	int	fd_out;

	fd_out = open(av[4], O_CREAT | O_WRONLY | 0644);
	if (fd_out < 0)
		return ;
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(path_all[0], cmd[0], NULL);
}

void input(const char **av, char **path_all, char ***cmd)
{
	int fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in < 0)
		return ;
	dup2(fd_in, STDIN_FILENO);
	close (fd_in);
	execve(path_all[1], cmd[1], NULL);
}
