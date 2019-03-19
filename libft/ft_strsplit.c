/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:51 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/15 15:02:01 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizetab(char const *s, char c)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cpt++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		cpt++;
	return (cpt);
}

static char		**ft_filltable(const char *s, char **str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			str[k] = ft_strsub(s, j, i - j);
			k++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	str[k] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s)
	{
		if (!(str = (char**)malloc(sizeof(char*) * (ft_sizetab(s, c) + 1))))
			return (NULL);
		return (ft_filltable(s, str, c));
	}
	return (NULL);
}
