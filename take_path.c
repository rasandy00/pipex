/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:52:25 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/17 11:53:53 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "pipex.h"
#include <stdlib.h>

char	**path(const char **env)
{
	int		i;
	int		j;
	char	**dest;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	dest = ft_split(env[i] + 5, ':');
	j = 0;
	while (dest[j])
	{
		tmp = dest[j];
		dest[j] = ft_strjoin(dest[j], "/");
		free (tmp);
		j++;
	}
	return (dest);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free (path);
}

void	ft_print_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		ft_printf("%s\n", path[i]);
		i++;
	}
}


char	**take_path(char ***cmd, const char **env)
{
	char	**path_all;

	path_all =malloc(sizeof(char*) * 3);
	if (!path_all)
		return (NULL);
	path_all[0] = acces_checker(path(env), cmd[0][0]);
	path_all[1] = acces_checker(path(env), cmd[1][0]);
	path_all[2] = 0;
	path_all[0] = ft_strjoin(path_all[0], cmd[0][0]);
	path_all[1] = ft_strjoin(path_all[1], cmd[1][0]);
	return (path_all);
}

char	***take_cmd(const char **av)
{
	char	***cmd_all;

	cmd_all = malloc(sizeof(char***) * 3);
	if (!cmd_all)
		return (NULL);
	cmd_all[0] = ft_split(av[2], ' ');
	cmd_all[1] = ft_split(av[3], ' ');
	cmd_all[2] = 0;
	return (cmd_all);
}
