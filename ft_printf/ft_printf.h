/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:25:53 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/23 09:26:15 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(const char c);
int		ft_printf(const char *str, ...);
int		ft_putchar_printf(int c);
int		ft_putstr_printf(const char *str);
int		ft_putnbr_printf(int nb);
int		ft_putnbr_printf2(unsigned int nbr);
int		hex_calcul_low(unsigned int hex);
int		hex_calcul_up(unsigned int hex);
int		hex_print(void *hex);
int		print_condition(char str, va_list args);

#endif
