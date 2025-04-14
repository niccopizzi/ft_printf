/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:08:52 by npizzi            #+#    #+#             */
/*   Updated: 2024/04/21 17:50:48 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*cpy_str(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*s1;
	const char		*s2;

	i = 0;
	s1 = dest;
	s2 = src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = dest;
	s2 = src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest && (src + n) >= dest)
	{
		while (n > 0)
		{
			s1[(n - 1)] = s2[(n - 1)];
			n--;
		}
	}
	else
		dest = cpy_str(dest, s2, n);
	return (dest);
}
