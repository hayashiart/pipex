/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:01:42 by slin              #+#    #+#             */
/*   Updated: 2021/11/27 00:36:14 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_charset(char const c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *charset)
{
	char	*newstr;
	int		debutchar;
	int		endchar;

	debutchar = 0;
	endchar = ft_strlen(str) - 1;
	while (is_in_charset(str[debutchar], charset) && str[debutchar])
		debutchar++;
	while (is_in_charset(str[endchar], charset) && endchar >= 0)
		endchar--;
	newstr = ft_substr(str, debutchar, endchar - debutchar + 1);
	return (newstr);
}
