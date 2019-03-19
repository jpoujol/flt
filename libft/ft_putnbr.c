/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:05:27 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/15 15:39:27 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n > 2147483647 || n < -2147483648)
		return ;
	else if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n >= 0 && n < 10)
		ft_putchar(n % 10 + '0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return ;
	}
}
