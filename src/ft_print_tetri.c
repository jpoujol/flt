/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:04:37 by jepoujol          #+#    #+#             */
/*   Updated: 2018/12/10 13:44:51 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_print_tetri(char ***tetri)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_putendl("---------- print tetri ----------");
	while (tetri[++i])
	{
		while (tetri[i][++j])
		{
			ft_putendl(tetri[i][j]);
		}
		ft_putendl("");
		j = -1;
	}
}
