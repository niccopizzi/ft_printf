/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:38:57 by nicco             #+#    #+#             */
/*   Updated: 2024/04/17 21:22:21 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_num(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	copy_nbr(char *s, long int n, int *pos)
{
	char	digit;

	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		*pos = *pos + 1;
	}
	if (n < 10)
	{
		digit = n + 48;
		s[*pos] = digit;
		*pos = *pos + 1;
	}
	if (n >= 10)
	{
		copy_nbr(s, n / 10, pos);
		copy_nbr(s, n % 10, pos);
	}
}

char	*ft_itoa(int n)
{
	char		*itoa;
	int			pos;
	long int	i;

	i = n;
	pos = 0;
	itoa = (char *)malloc(len_num(i) + 1);
	if (itoa == NULL)
		return (NULL);
	copy_nbr(itoa, i, &pos);
	itoa[pos] = 0;
	return (itoa);
}
