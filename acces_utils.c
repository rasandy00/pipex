/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acces_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:39:23 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/17 14:04:33 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char  *acces_checker(char **path, const char *cmd)
{
	int	i;
	char *str;

	i = 0;
	str = NULL;
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, F_OK) == 0)
			return (free(str), path[i]);
		free(str);
		i++;
	}
	return (NULL);
}

int check_path(char **path, const char *cmd)
{
	int	i;
	char *str;

	i = 0;
	str = NULL;
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, F_OK) == 0)
			return (1);
		free(str);
		i++;
	}
	return (0);
}
	