/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:32:37 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/19 13:13:19 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 1)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int		ft_getpowersize(int n)
{
	int		size;

	if (n < 0)
	{
		size = ft_power(10, ft_itoa_size(n) - 2);
		if (n > -10)
			size = 1;
	}
	else
	{
		size = ft_power(10, ft_itoa_size(n) - 1);
		if (n < 10)
			size = 1;
	}
	return (size);
}

static char		*ft_fillitoa(char *str, int n)
{
	int		size;
	int		i;

	i = 0;
	if (n < 0)
	{
		size = ft_getpowersize(n);
		str[0] = '-';
		i++;
		n *= -1;
	}
	else
		size = ft_getpowersize(n);
	while (size >= 1)
	{
		str[i] = n / size + '0';
		n %= size;
		size /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		if (!(str = ft_memalloc(12)))
			return (NULL);
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (!(str = ft_memalloc(ft_itoa_size(n) + 1)))
		return (NULL);
	return (ft_fillitoa(str, n));
}
