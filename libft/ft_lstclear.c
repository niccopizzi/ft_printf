/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:09:27 by npizzi            #+#    #+#             */
/*   Updated: 2024/04/23 18:47:13 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_delete;

	if (lst == NULL || *lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		to_delete = (*lst);
		*lst = (*lst)->next;
		del(to_delete->content);
		free(to_delete);
	}
	lst = NULL;
}
