/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:17:16 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 12:45:06 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_placetetri(char ***map, int i, int j, t_coor *coor)
{
	int		pt;

	pt = 0;
	while (pt < 4)
	{
		map[0][i + coor->coor[pt][0]][j + coor->coor[pt][1]] = coor->c;
		pt++;
	}
}
