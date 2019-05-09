/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:44:52 by jepoujol          #+#    #+#             */
/*   Updated: 2019/05/09 15:05:36 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_flt	*fillit(t_flt *flt)
{
	t_coor	*coor;

	if (ft_checkfile(flt->buf) == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	flt->tetri = ft_parsing(flt->buf);
	ft_topleftcorner(&flt->tetri);
	coor = ft_init_coor(flt);
	ft_resolve(flt, coor);
	ft_free_list(&coor);
	ft_free_tetri(flt);
	return (flt);
}
