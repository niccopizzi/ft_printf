/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:42:44 by nicco             #+#    #+#             */
/*   Updated: 2024/04/21 17:34:50 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;
	unsigned long	tot_size;

	if (nmemb * size == 0)
	{
		array = malloc(0);
		return (array);
	}
	if (size > ULONG_MAX / nmemb)
		return (NULL);
	tot_size = size * nmemb;
	array = malloc(tot_size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, tot_size);
	return (array);
}
