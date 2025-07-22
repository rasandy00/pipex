/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:55:22 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/17 11:58:58 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	free_two(char **str)
{
	int	i;

	i = 0;
	while (*str[i])
	{
		free (str);
		i++;
	}
}

void	free_three(char ***str)
{
	int	i;

	i = 0;
	while (**str[i])
	{
		free_two(str[i]);
		i++;
	}
}