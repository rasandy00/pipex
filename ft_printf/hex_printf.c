/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:22:59 by andriamr          #+#    #+#             */
/*   Updated: 2025/05/28 17:19:22 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_calcul_low(unsigned int hex)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (hex >= 16)
		i += hex_calcul_low(hex / 16);
	i++;
	ft_putchar(base[hex % 16]);
	return (i);
}

int	hex_calcul_up(unsigned int hex)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (hex >= 16)
		i += hex_calcul_up(hex / 16);
	i++;
	ft_putchar(base[hex % 16]);
	return (i);
}

static int	hex_calcul_low_long(unsigned long int hex)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (hex >= 16)
		i += hex_calcul_low_long(hex / 16);
	i++;
	ft_putchar_printf(base[hex % 16]);
	return (i);
}

int	hex_print(void *hex)
{
	unsigned long int	i;
	int					len;

	if (!hex)
		return (ft_putstr_printf("(nil)"));
	i = (unsigned long int)hex;
	ft_putchar('0');
	ft_putchar('x');
	len = hex_calcul_low_long(i) + 2;
	return (len);
}
