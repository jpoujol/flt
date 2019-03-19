/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:37:35 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 15:24:13 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_print_coor(t_coor **begin_coor)
{
	t_coor	*coor;
	int		tetri;
	int		pt;

	coor = *begin_coor;
	tetri = 1;
	pt = 0;
	while (coor)
	{
		while (pt < 4)
		{
			ft_putnbr(coor->coor[pt][0]);
			ft_putnbr(coor->coor[pt][1]);
			pt++;
		}
		pt = 0;
		coor = coor->next;
		tetri++;
	}
}
