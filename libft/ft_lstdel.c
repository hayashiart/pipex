/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:15:53 by slin              #+#    #+#             */
/*   Updated: 2022/04/12 20:15:55 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*tmp;

	if (!alst)
		return ;
	cursor = *alst;
	while (cursor)
	{
		tmp = cursor->next;
		del(cursor);
		free(cursor);
		cursor = tmp;
	}
	*alst = NULL;
}
