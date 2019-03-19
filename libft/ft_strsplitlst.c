/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:41:17 by jepoujol          #+#    #+#             */
/*   Updated: 2018/11/19 16:58:30 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_elem(void *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return ((t_list*)NULL);
	list->content = content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}

static void		ft_list_push_back(t_list **begin_list, void *content,
	size_t content_size)
{
	t_list		*list;

	list = *begin_list;
	if (!list)
		list = ft_create_elem(content, content_size);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(content, content_size);
	}
}

static t_list	*ft_getlst(t_list **begin_lst, t_list *lst, char *str, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	begin_lst = &lst;
	while (str[i])
	{
		if (str[i] != c)
		{
			j = i;
			while (str[i] != c && str[i])
				i++;
			if (!lst)
				lst = ft_create_elem(ft_strsub(str, j, i - j), i - j);
			else
				ft_list_push_back(begin_lst, ft_strsub(str, j, i - j), i - j);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (lst);
}

t_list			*ft_strsplitlst(char *str, char c)
{
	t_list		*lst;
	t_list		**begin_lst;

	lst = NULL;
	begin_lst = &lst;
	return (ft_getlst(begin_lst, lst, str, c));
}
