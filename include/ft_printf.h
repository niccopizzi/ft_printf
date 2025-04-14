/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:55:41 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/03 16:57:34 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		is_valid_type(char c);
int		ft_printf(const char *s, ...);
void	determine_type(char c, va_list *arg, int *printed_chars);
void	ft_print_ux_xupper(va_list *ap, char mode, int *printed_chars);
void	ft_print_p(va_list *ap, int *printed_chars);
void	ft_print_s(va_list *ap, int *printed_chars);
void	ft_print_cdi(va_list *ap, char mode, int *printed_chars);
void	print_string(const char *s, va_list *ap, int *printed_chars);
#endif
