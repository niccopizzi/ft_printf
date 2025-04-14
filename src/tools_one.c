/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:37:54 by nicco             #+#    #+#             */
/*   Updated: 2024/04/30 20:55:33 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_base(unsigned long n, char *base, unsigned int base_len,
		int *printed_chars)
{
	if (n < base_len)
		*printed_chars += write(1, &base[n], 1);
	else
	{
		ft_print_nbr_base(n / base_len, base, base_len, printed_chars);
		ft_print_nbr_base(n % base_len, base, base_len, printed_chars);
	}
}

void	ft_print_ux_xupper(va_list *ap, char mode, int *printed_chars)
{
	unsigned int	x;

	x = va_arg(*ap, unsigned int);
	if (mode == 'x')
		ft_print_nbr_base(x, "0123456789abcdef", 16, printed_chars);
	if (mode == 'X')
		ft_print_nbr_base(x, "0123456789ABCDEF", 16, printed_chars);
	if (mode == 'u')
		ft_print_nbr_base(x, "0123456789", 10, printed_chars);
}

void	ft_print_p(va_list *ap, int *printed_chars)
{
	unsigned long	x;

	x = va_arg(*ap, unsigned long);
	if (x == 0)
		*printed_chars += write(1, "(nil)", 5);
	else
	{
		*printed_chars += write(1, "0x", 2);
		ft_print_nbr_base(x, "0123456789abcdef", 16, printed_chars);
	}
}
