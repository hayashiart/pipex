/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:34:15 by slin              #+#    #+#             */
/*   Updated: 2021/11/26 19:45:54 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*strr;
	unsigned char	cr;
	size_t			i;

	i = 0;
	strr = (unsigned char *)str;
	cr = (unsigned char)c;
	while (i < n)
	{
		if (strr[i] == cr)
			return (strr + i);
		i++;
	}
	return (NULL);
}
