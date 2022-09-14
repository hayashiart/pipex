/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:53:41 by slin              #+#    #+#             */
/*   Updated: 2021/11/26 19:52:38 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void	*str2, size_t n)
{
	unsigned char	*str1r;
	unsigned char	*str2r;
	size_t			i;

	i = 0;
	str1r = (unsigned char *)str1;
	str2r = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (str1r && str2r && i < n - 1 && str1r[i] == str2r[i])
		i++;
	return (str1r[i] - str2r[i]);
}
