/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:18:08 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 15:30:19 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_change_letter(char **str)
{
	int		i;
	char	c;

	i = -1;
	c = 'A';
	while ((*str)[++i])
	{
		if ((*str)[i] == '#')
			(*str)[i] = c;
		if ((*str)[i] == '\n' && (*str)[i + 1] == '\n')
			c++;
	}
}

static char		***ft_memtab(int nbtetri)
{
	int		i;
	char	***tetri;

	i = -1;
	if ((!(tetri = (char***)ft_memalloc(sizeof(char**) * (nbtetri + 1)))))
		return (NULL);
	tetri[nbtetri] = NULL;
	return (tetri);
}

char			***ft_parsing(char *str)
{
	int		i;
	char	***tetri;
	char	*strsubbed;

	ft_change_letter(&str);
	i = -1;
	tetri = ft_memtab(ft_nbtetri(str));
	while (++i < ft_nbtetri(str))
	{
		strsubbed = ft_strsub(str, i * 21, 21);
		if (!(tetri[i] = ft_strsplit(strsubbed, '\n')))
			return (NULL);
		ft_strdel(&strsubbed);
	}
	return (tetri);
}
