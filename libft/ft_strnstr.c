/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:05:57 by jepoujol          #+#    #+#             */
/*   Updated: 2018/12/05 11:23:29 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	int		i;
	size_t	j;

	i = -1;
	j = 0;
	if (n[0] == '\0')
		return ((char*)h);
	while (h[++i] && (i + j < len))
	{
		while (h[i + j] && h[i + j] == n[j] && (i + j < len))
			j++;
		if (n[j] == '\0')
			return ((char*)h + i);
		j = 0;
	}
	return (NULL);
}
