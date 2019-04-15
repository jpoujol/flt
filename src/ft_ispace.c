/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:25:52 by jepoujol          #+#    #+#             */
/*   Updated: 2019/04/09 10:59:39 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_ispace(t_flt *flt, t_coor *coor, int row, int col)
{
	int		pt;
	int		map_size;

	pt = 0;
	map_size = ft_strlen(flt->map[0]);
	while (pt < 4)
	{
		if (row + coor->coor[pt][0] >= map_size
			|| col + coor->coor[pt][1] >= map_size)
		{
			return (0);
		}
		if (flt->map[row + coor->coor[pt][0]][col + coor->coor[pt][1]] == '.')
		{
			pt++;
		}
		else
			return (0);
	}
	return (1);
}
