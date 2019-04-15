/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:05:52 by jepoujol          #+#    #+#             */
/*   Updated: 2019/04/09 10:49:52 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		ft_tetri_valide(char *str)
{
	int		i;
	int		nblink;
	char	*getnblink;

	i = -1;
	nblink = 0;
	while (str[++i])
	{
		if (i % 21 == 0)
		{
			getnblink = ft_strsub(str + i, 0, 20);
			nblink = ft_getnblink(getnblink);
			ft_strdel(&getnblink);
		}
		if (!(nblink == 6) && !(nblink == 8))
			return (-1);
	}
	return (1);
}

static int		ft_tetri_is_square2(char *str, int *i, int *cptx, int *cpty)
{
	if (str[*i] == '\n' && str[*i + 1] == '\0')
	{
		if (*cpty != 3)
			return (-1);
	}
	if (str[*i] == '\n' && str[*i + 1] == '\n')
	{
		if (*cptx != 4 && *cpty != 3)
			return (-1);
		*cpty = 0;
		*cptx = 0;
		*i += 2;
	}
	else if (str[*i] == '\n')
	{
		if (*cptx != 4)
			return (-1);
		*cptx = 0;
		(*cpty)++;
		(*i)++;
	}
	(*cptx)++;
	return (1);
}

static int		ft_tetri_is_square(char *str)
{
	int		i;
	int		cptx;
	int		cpty;

	cptx = 0;
	cpty = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_tetri_is_square2(str, &i, &cptx, &cpty) == -1)
			return (-1);
	}
	return (1);
}

int				ft_checkfile(char *str)
{
	if (ft_strlen(str) == 0)
		return (-1);
	if (ft_nbdiese_valide(str) == -1)
		return (-1);
	if (ft_nbtetri(str) > 26)
		return (-1);
	if (ft_tetri_valide(str) == -1)
		return (-1);
	if (ft_tetri_is_square(str) == -1)
		return (-1);
	return (1);
}
