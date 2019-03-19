/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:14 by jepoujol          #+#    #+#             */
/*   Updated: 2019/01/28 16:03:11 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int ac, char **av)
{
	t_flt	flt;
	int		ret;
	int		fd;

	if (ac != 2)
		ft_putendl("./fillit [file_name]");
	fd = open(av[1], O_RDONLY);
	flt.buf = ft_strnew((BUFF_SIZE + 1) * sizeof(char));
	if (fd < 0 || read(fd, flt.buf, 0) == -1)
		return (-1);
	while ((ret = read(fd, flt.buf, BUFF_SIZE)) > 0)
		flt.buf[ret] = 0;
	if (fillit(&flt) == NULL)
		return (0);
	ft_strdel(&flt.buf);
	ft_print_map(flt.map);
	flt.buf = NULL;
	close(fd);
	return (0);
}
