/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbtetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:11:33 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 15:24:58 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_nbtetri(char *str)
{
	int		i;
	int		nbtetri;

	i = -1;
	nbtetri = 0;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			nbtetri++;
		if (str[i] == '\n' && str[i + 1] == '\0')
			nbtetri++;
	}
	return (nbtetri);
}
