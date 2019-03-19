/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:55:55 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/09 15:30:13 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	x;

	i = 0;
	while (s[i])
		i++;
	x = (char)c;
	while (i >= 0)
	{
		if (s[i] == x)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}
