/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:24:49 by slin              #+#    #+#             */
/*   Updated: 2022/04/12 21:10:00 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_element;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst != NULL)
	{
		last_element = ft_lstlast(*alst);
		last_element->next = new;
	}
	else
		*alst = new;
}
