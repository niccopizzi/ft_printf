/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:34:22 by nicco             #+#    #+#             */
/*   Updated: 2024/09/03 17:04:04 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_type(char c)
{
	char	*types;
	int		i;

	i = 0;
	types = "cspdiuxX%";
	while (types[i] != 0)
	{
		if (c == types[i])
			return (1);
		i++;
	}
	return (0);
}

void	determine_type(char c, va_list *arg, int *printed_chars)
{
	if ((c == '%' || is_valid_type(c) == 0) && c != 0)
		*printed_chars += write(1, &c, 1);
	if (c == 'c' || c == 'i' || c == 'd')
		ft_print_cdi(arg, c, printed_chars);
	if (c == 's')
		ft_print_s(arg, printed_chars);
	if (c == 'u' || c == 'x' || c == 'X')
		ft_print_ux_xupper(arg, c, printed_chars);
	if (c == 'p')
		ft_print_p(arg, printed_chars);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		printed_chars;

	if (s == NULL || (s[0] == '%' && s[1] == 0))
		return (-1);
	printed_chars = 0;
	va_start(ap, s);
	print_string(s, &ap, &printed_chars);
	va_end(ap);
	return (printed_chars);
}
