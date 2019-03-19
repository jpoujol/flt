/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:49:03 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 12:55:24 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_free_tetri(t_flt *flt)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (flt->tetri[++i])
	{
		while (flt->tetri[i][++j])
		{
			ft_strdel(&(flt->tetri[i][j]));
		}
		j = -1;
	}
}

void	ft_free_list(t_coor **begin_coor)
{
	t_coor	*current;
	t_coor	*next;

	current = *begin_coor;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	begin_coor = NULL;
}

void	ft_free_map(t_flt *flt)
{
	int		i;

	i = -1;
	while ((flt->map)[++i])
	{
		ft_strdel(&(flt->map)[i]);
	}
	free(flt->map);
}
