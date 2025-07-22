/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:51:15 by andriamr          #+#    #+#             */
/*   Updated: 2025/05/27 14:42:49 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
