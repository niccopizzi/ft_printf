/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:07:52 by nicco             #+#    #+#             */
/*   Updated: 2024/04/16 19:45:21 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned long	i;
	unsigned long	x;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < n && big[i] != 0)
	{
		x = 0;
		if (big[i] == little[x])
		{
			while (big[i + x] == little[x] && (i + x < n))
			{
				if (little[x + 1] == 0)
					return ((char *)big + i);
				x++;
			}
		}
		i++;
	}
	return (0);
}
