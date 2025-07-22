/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:03:44 by andriamr          #+#    #+#             */
/*   Updated: 2025/05/28 16:11:54 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_putnbr_printf(int nbr)
{
	long	nb;
	int		i;

	nb = nbr;
	i = ft_count_nbr(nb);
	if (nb == -2147483648)
	{
		ft_putstr_printf("-2147483648");
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar ('-');
		ft_putnbr_printf(-nb);
	}
	else if (nb >= 0 && nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr_printf (nb / 10);
		ft_putnbr_printf (nb % 10);
	}
	return (i);
}

int	ft_putnbr_printf3(long long nbr)
{
	long long	i;

	i = 0;
	if (nbr < 0)
		i = 11;
	if (nbr >= 0 && nbr < 10)
		ft_putchar(nbr + 48);
	else if (nbr >= 10)
	{
		ft_putnbr_printf (nbr / 10);
		ft_putnbr_printf (nbr % 10);
	}
	return (i);
}

int	ft_putnbr_printf2(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i = ft_putnbr_printf2(nbr / 10);
	}
	i += ft_putchar_printf((nbr % 10) + '0');
	return (i);
}
