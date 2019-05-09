/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:47:19 by jepoujol          #+#    #+#             */
/*   Updated: 2019/05/09 17:22:05 by jepoujol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 4096

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>

typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;

typedef struct		s_flt
{
	char	***tetri;
	char	*buf;
	char	**map;
	int		i;
	int		j;
}					t_flt;

typedef struct		s_coor
{
	char	c;
	int		coor[4][2];
	void	*next;
}					t_coor;

int					ft_nbtetri(char *str);
int					ft_nbdiese_valide(char *str);
int					ft_getnblink(char *str);
int					ft_checkfile(char *str);
int					ft_ispace(t_flt *flt, t_coor *coor, int row, int col);
t_bool				recursion(t_flt *flt, t_coor *coor, int size);
void				ft_resolve(t_flt *flt, t_coor *coor);
void				ft_print_tetri(char ***tetri);
void				ft_print_map(char **map);
void				ft_print_coor(t_coor **begin_coor);
void				ft_topleftcorner(char ****tetri);
void				ft_free_map(t_flt *flt);
void				ft_free_list(t_coor **begin_coor);
void				ft_free_tetri(t_flt *flt);
void				ft_placetetri(char ***map, int i, int j, t_coor *coor);
char				***ft_parsing(char *str);
int					ft_gen_map(char ***map, size_t size);

t_flt				*fillit(t_flt *flt);
t_coor				*ft_init_coor(t_flt *flt);

#endif
