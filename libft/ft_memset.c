/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:50:25 by slin              #+#    #+#             */
/*   Updated: 2021/11/26 19:29:57 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*newstr;

	i = 0;
	newstr = (unsigned char *)str;
	while (i < n)
	{
		newstr[i] = (unsigned char)c;
		i++;
	}
	str = newstr;
	return (str);
}
