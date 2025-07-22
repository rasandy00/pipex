/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:26:06 by andriamr          #+#    #+#             */
/*   Updated: 2025/05/29 10:19:19 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_condition(char str, va_list args)
{
	int	len;

	len = 0;
	if (str == 'd' || str == 'i')
		len = ft_putnbr_printf(va_arg(args, int));
	else if (str == 'u')
		len = ft_putnbr_printf2(va_arg(args, unsigned int));
	else if (str == 's')
		len = ft_putstr_printf(va_arg(args, const char *));
	else if (str == 'c')
		len = ft_putchar_printf(va_arg(args, int));
	else if (str == '%')
		len = ft_putchar_printf ('%');
	else if (str == 'x')
		len = hex_calcul_low(va_arg(args, unsigned int long));
	else if (str == 'X')
		len = hex_calcul_up(va_arg(args, unsigned int long));
	else if (str == 'p')
		len = hex_print(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start (args, str);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '\0')
				break ;
			len += print_condition(str[i++], args);
		}
		else
		{
			len += ft_putchar_printf (str[i]);
			i++;
		}
	}
	va_end (args);
	return (len);
}
