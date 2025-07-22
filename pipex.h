/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:52:43 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/17 16:35:46 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include "LIBFT/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <fcntl.h>

int			main(int ac, const char **av, const char **env);
char		**path(const char **env);
void		free_path(char **path);
void		ft_print_path(char **path);
char		*acces_checker(char **path, const char *cmd);
int			check_path(char **path, const char *cmd);
char		***take_cmd(const char **av);
char		**take_path(char ***cmd, const char **env);
void		free_three(char ***str);
void		free_two(char **str);
void		output(const char **av, char **path_all, char ***cmd);
void		input(const char **av, char **path_all, char ***cmd);

#endif