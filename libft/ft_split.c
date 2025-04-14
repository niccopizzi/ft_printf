/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:53:28 by nicco             #+#    #+#             */
/*   Updated: 2024/04/21 17:45:46 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != 0)
	{
		if ((s[i] != c && s[i + 1] == c))
			words++;
		if (s[i + 1] == 0 && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static void	copy_str(char *s1, char const *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
}

static int	ft_clear(char **list, int i, int len)
{
	list[i] = (char *)malloc(len + 1);
	if (list[i] == NULL)
	{
		while (i >= 0)
		{
			free(list[i]);
			i--;
		}
		free(list);
		return (-1);
	}
	return (0);
}

static int	make_split(char **list, char const *s, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			x = 0;
			while (s[i + x] != c && s[i + x] != 0)
				x++;
			if (ft_clear(list, y, x) == -1)
				return (-1);
			copy_str(list[y], s + i, x);
			y++;
			i += x;
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split_list;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	split_list = (char **)malloc(sizeof(char *) * (words + 1));
	if (split_list == NULL)
		return (NULL);
	if (make_split(split_list, s, c) == 0)
		split_list[words] = NULL;
	return (split_list);
}
