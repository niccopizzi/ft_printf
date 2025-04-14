/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:05:12 by npizzi            #+#    #+#             */
/*   Updated: 2024/04/13 18:13:16 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned long	i;
	char			*p;

	p = s;
	i = 0;
	d = c;
	while (i < n)
	{
		p[i] = d;
		i++;
	}
	return (s);
}
