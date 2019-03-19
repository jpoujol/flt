/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:11:42 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/19 13:11:49 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int		res;
	int		neg;

	neg = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		neg = -1;
		nb *= -1;
	}
	res = nb;
	while (--power > 0)
		res = res * nb;
	return (res * neg);
}
