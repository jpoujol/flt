/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:02:10 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 15:35:29 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_removetetri(t_flt *flt, t_coor *coor)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (flt->map[++i])
	{
		while (flt->map[i][++j])
		{
			if (flt->map[i][j] == coor->c)
			{
				flt->map[i][j] = '.';
			}
		}
		j = -1;
	}
}

int				solve(t_flt *flt, t_coor **begin_coor, t_coor *coor)
{
	int		map_size;

	map_size = 2;
	if (ft_gen_map(&(flt->map), map_size) == 0)
		return (FALSE);
	while (recursion(flt, coor, map_size) == FALSE)
	{
		ft_free_map(flt);
		map_size++;
		if (ft_gen_map(&flt->map, map_size) == 0)
			return (0);
	}
	return (0);
}

t_bool			recursion(t_flt *flt, t_coor *coor, int map_size)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	if (!coor)
		return (TRUE);
	while (flt->map[row])
	{
		while (flt->map[row][col])
		{
			if (ft_ispace(flt, coor, row, col) == 1)
			{
				ft_placetetri(&flt->map, row, col, coor);
				if (recursion(flt, coor->next, map_size) == TRUE)
					return (TRUE);
				else
					ft_removetetri(flt, coor);
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (FALSE);
}
