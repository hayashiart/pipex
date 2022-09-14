/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:45:10 by slin              #+#    #+#             */
/*   Updated: 2021/11/26 23:29:44 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstr)
		return (NULL);
	while (i < size)
	{
		newstr[i] = f(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
