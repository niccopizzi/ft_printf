/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:37 by nicco             #+#    #+#             */
/*   Updated: 2024/04/16 20:09:05 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long		i;
	const unsigned char	*str;
	unsigned char		to_find;

	str = s;
	i = 0;
	to_find = c;
	while (i < n)
	{
		if (str[i] == to_find)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
