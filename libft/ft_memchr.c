/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:52:53 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/08 15:36:14 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	car;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	car = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == car)
			return (str + i);
		i++;
	}
	return (NULL);
}
