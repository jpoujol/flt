/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:32:04 by jepoujol          #+#    #+#             */
/*   Updated: 2019/04/15 18:33:59 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			ft_gen_map(char ***map, size_t size)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(*map = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (0);
	(*map)[size] = NULL;
	while (++i < (int)size)
	{
		if (!((*map)[i] = ft_strnew(sizeof(char) * (size + 1))))
			return (0);
		while (++j < (int)size)
		{
			(*map)[i][j] = '.';
		}
		(*map)[i][j] = '\0';
		j = -1;
	}
	return (1);
}
