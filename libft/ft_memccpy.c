/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:58:48 by jepoujol          #+#    #+#             */
/*   Updated: 2018/12/03 14:54:23 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	car;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	car = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if ((s1[i] = s2[i]) == car)
			return (s1 + i + 1);
	}
	return (NULL);
}
