/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:15:40 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/15 11:04:03 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	car;
	char			*str;

	car = (unsigned char)c;
	str = (char*)b;
	while (len--)
		*str++ = car;
	return (b);
}
