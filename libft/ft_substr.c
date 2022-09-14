/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:00:27 by slin              #+#    #+#             */
/*   Updated: 2021/11/27 01:41:49 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*souschaine;
	size_t	i;
	int		taillestring;
	int		taille;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	taillestring = ft_strlen(s + start);
	if (len > (size_t)taillestring)
		taille = taillestring;
	else
		taille = len;
	souschaine = malloc(sizeof(char) * (taille + 1));
	if (!souschaine)
		return (NULL);
	while (i < len && s[start + i])
	{
		souschaine[i] = s[start + i];
		i++;
	}
	souschaine[i] = '\0';
	return (souschaine);
}
