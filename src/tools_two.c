/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:37:46 by nicco             #+#    #+#             */
/*   Updated: 2024/09/03 11:12:20 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(va_list *ap, int *printed_chars)
{
	char	*s;
	int		i;

	s = va_arg(*ap, char *);
	i = 0;
	if (s == NULL)
		*printed_chars += write(1, "(null)", 6);
	else
	{
		while (s[i] != 0)
		{
			*printed_chars += write(1, &s[i], 1);
			i++;
		}
	}
}

void	print_nbr(int n, int *printed_chars)
{
	int	b;

	if (n == -2147483648)
		*printed_chars += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			*printed_chars += write(1, "-", 1);
			n = n * -1;
		}
		if (n < 10)
		{
			b = n + 48;
			*printed_chars += write(1, &b, 1);
		}
		else
		{
			print_nbr(n / 10, printed_chars);
			print_nbr(n % 10, printed_chars);
		}
	}
}

void	ft_print_cdi(va_list *ap, char mode, int *printed_chars)
{
	int	b;

	b = va_arg(*ap, int);
	if (mode == 'c')
		*printed_chars += write(1, &b, 1);
	if (mode == 'd' || mode == 'i')
		print_nbr(b, printed_chars);
}

void	print_string(const char *s, va_list *ap, int *printed_chars)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != '%')
		{
			*printed_chars += write(1, &s[i], 1);
			i++;
		}
		else
		{
			if (is_valid_type(s[i + 1]) == 0)
				*printed_chars += write(1, "%", 1);
			determine_type(s[i + 1], ap, printed_chars);
			if (s[i + 1] == 0)
				break ;
			i += 2;
		}
	}
}
