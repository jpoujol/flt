/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:09:16 by jepoujol          #+#    #+#             */
/*   Updated: 2019/05/09 14:44:57 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static t_coor	*ft_fillcoor(char **tetri, t_coor **begin_coor, char c)
{
	int		i;
	int		j;
	int		pt;
	t_coor	*coor;

	i = -1;
	j = -1;
	pt = 0;
	coor = *begin_coor;
	while (tetri[++i])
	{
		while (tetri[i][++j])
		{
			if (tetri[i][j] == c)
			{
				coor->coor[pt][0] = i;
				coor->coor[pt][1] = j;
				pt++;
			}
		}
		j = -1;
	}
	coor->c = c;
	return (coor);
}

t_coor			*ft_create_lst(char **tetri, char c)
{
	t_coor	*coor;

	if (!(coor = (t_coor*)ft_memalloc(sizeof(t_coor))))
		return ((t_coor*)NULL);
	coor = ft_fillcoor(tetri, &coor, c);
	coor->next = NULL;
	return (coor);
}

static void		ft_lstcoor_push_back(char **tetri, t_coor **begin_coor, char c)
{
	t_coor	*coor;
	t_coor	*ite;

	coor = ft_create_lst(tetri, c);
	if (!coor)
	{
		*begin_coor = ft_create_lst(tetri, c);
		return ;
	}
	ite = *begin_coor;
	while (ite->next)
		ite = ite->next;
	ite->next = coor;
}

t_coor			*ft_init_coor(t_flt *flt)
{
	t_coor	*coor;
	t_coor	**begin_coor;
	int		i;

	i = -1;
	coor = NULL;
	begin_coor = &coor;
	while (flt->tetri[++i])
	{
		if (!coor)
			coor = ft_create_lst(flt->tetri[i], 'A' + i);
		else
			ft_lstcoor_push_back(flt->tetri[i], begin_coor, 'A' + i);
	}
	return (*begin_coor);
}
