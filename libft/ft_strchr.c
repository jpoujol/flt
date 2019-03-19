/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:51:56 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/09 15:32:06 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;

	i = 0;
	x = (char)c;
	while (s[i])
	{
		if (s[i] == x)
			return ((char*)s + i);
		i++;
	}
	if (x == '\0' && s[i] == '\0')
		return ((char*)s + i);
	return (NULL);
}
