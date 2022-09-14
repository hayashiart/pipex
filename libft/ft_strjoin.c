/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:49:48 by slin              #+#    #+#             */
/*   Updated: 2021/11/27 03:28:14 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_init(char *newchaine, char const *str1, char const *str2)
{	
	unsigned int	size1;
	unsigned int	size2;
	unsigned int	size;
	unsigned int	i;

	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	size = size1 + size2;
	i = 0;
	while (i < size1)
	{
		newchaine[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		newchaine[size1 + i] = str2[i];
		i++;
	}
	newchaine[size] = '\0';
	return (newchaine);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	unsigned int	size;
	unsigned int	size1;
	unsigned int	size2;
	char			*newchaine;

	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	size = size1 + size2;
	newchaine = malloc(sizeof(char) * (size + 1));
	if (!newchaine)
		return (NULL);
	newchaine = ft_init(newchaine, str1, str2);
	return (newchaine);
}
