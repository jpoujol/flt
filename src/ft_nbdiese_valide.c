/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdiese_valide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:14:51 by jepoujol          #+#    #+#             */
/*   Updated: 2019/04/09 10:56:16 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_nbdiese_valide(char *str)
{
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (-1);
		if (str[i] == '#')
			cpt++;
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
			return (-1);
		if (str[i] == '\n' && str[i + 1] == '\n' && cpt == 4)
			cpt = 0;
		else if ((str[i] == '\n' && str[i + 1] == '\n' && cpt != 4)
				|| (str[i] == '\n' && str[i + 1] == '\0' && cpt != 4))
			return (-1);
	}
	return (1);
}
