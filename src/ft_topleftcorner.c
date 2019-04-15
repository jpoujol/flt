/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topleftcorner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:10:35 by jepoujol          #+#    #+#             */
/*   Updated: 2019/04/09 10:58:39 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_movetop(char **tetri, char c, int coory)
{
	int			i;
	int			j;

	j = -1;
	i = -1;
	if (!(coory == 0))
	{
		while (tetri[++i])
		{
			while (tetri[i][++j])
			{
				if (tetri[i][j] == c && coory != 0)
				{
					tetri[i - coory][j] = tetri[i][j];
					tetri[i][j] = '.';
				}
			}
			j = -1;
		}
	}
}

static void		ft_movetetri(char **tetri, char c, int coorx, int coory)
{
	int			i;
	int			j;

	j = -1;
	i = -1;
	ft_movetop(tetri, c, coory);
	if (!(coory == 0 && coorx == 0))
	{
		while (tetri[++i])
		{
			while (tetri[i][++j])
			{
				if (tetri[i][j] == c && coorx != 0)
				{
					tetri[i][j - coorx] = tetri[i][j];
					tetri[i][j] = '.';
				}
			}
			j = -1;
		}
	}
}

static int		ft_get_coorx(char **tetri, char c)
{
	int			i;
	int			j;
	int			coorx;

	i = -1;
	j = -1;
	coorx = 4;
	while (tetri[++i])
	{
		while (tetri[i][++j])
		{
			if (tetri[i][j] == c && j < coorx)
				coorx = j;
		}
		j = -1;
	}
	return (coorx);
}

static int		ft_get_coory(char **tetri, char c)
{
	int			i;
	int			j;
	int			coory;

	i = -1;
	j = -1;
	coory = 4;
	while (tetri[++i])
	{
		while (tetri[i][++j])
		{
			if (tetri[i][j] == c && i < coory)
				coory = i;
		}
		j = -1;
	}
	return (coory);
}

void			ft_topleftcorner(char ****tetri)
{
	int			i;
	int			coorx;
	int			coory;

	i = -1;
	while ((*tetri)[++i])
	{
		coorx = ft_get_coorx((*tetri)[i], 'A' + i);
		coory = ft_get_coory((*tetri)[i], 'A' + i);
		ft_movetetri((*tetri)[i], 'A' + i, coorx, coory);
	}
}
