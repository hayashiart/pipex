/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:25:17 by slin              #+#    #+#             */
/*   Updated: 2022/04/12 18:25:19 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void*))
{
	t_list	*cursor;
	t_list	*to_del;

	cursor = *alst;
	while (cursor)
	{
		to_del = cursor;
		cursor = cursor -> next;
		ft_lstdelone(to_del, del);
	}
	*alst = NULL;
}
