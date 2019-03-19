/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnblink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:47:29 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 15:31:48 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		ft_countlink(char *str, int i)
{
	int		nblink;

	nblink = 0;
	if (str[i + 1] && str[i + 1] == '#')
		nblink++;
	if (str[i - 1] && str[i - 1] == '#')
		nblink++;
	if (str[i + 5] && str[i + 5] == '#')
		nblink++;
	if (str[i - 5] && str[i - 5] == '#')
		nblink++;
	return (nblink);
}

int				ft_getnblink(char *str)
{
	int		i;
	int		nblink;

	i = 0;
	nblink = 0;
	while (str[i])
	{
		if (str[i] == '#')
			nblink = nblink + ft_countlink(str, i);
		i++;
	}
	return (nblink);
}
