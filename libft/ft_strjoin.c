/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:35:55 by nicco             #+#    #+#             */
/*   Updated: 2024/04/17 20:29:11 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_copy(char *new_str, char const *s1, char const *s2)
{
	int	i;
	int	x;

	i = 0;
	while (s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != 0)
	{
		new_str[i + x] = s2[x];
		x++;
	}
	new_str[i + x] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		new_str = (char *)malloc(ft_strlen(s2) + 1);
		if (new_str == NULL)
			return (NULL);
		ft_strlcpy(new_str, s2, ft_strlen(s2) + 1);
		return (new_str);
	}
	if (s2 == NULL)
	{
		new_str = (char *)malloc(ft_strlen(s1) + 1);
		if (new_str == NULL)
			return (NULL);
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
		return (new_str);
	}
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	make_copy(new_str, s1, s2);
	return (new_str);
}
