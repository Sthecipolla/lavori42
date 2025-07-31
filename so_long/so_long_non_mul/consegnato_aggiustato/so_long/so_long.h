/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:34:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 17:45:07 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx_int.h"
# include "./minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_image123
{
	int		height;
	int		width;
	void	*img;

}	t_cr_image;

typedef struct l_map
{
	void		*session;
	void		*window;
	char		**map;
	int			coins;
	int			tot_coins;
	t_cr_image	imgarr[8];

}	t_map;

int		main(int argn, char **argc);
int		check_border(char **map);
int		check_portal(char	**matrix);
int		check_player(char	**matrix);
int		check_coins(char	**matrix);
void	free_double_pointer(char **ptr);
int		ft_clean(t_map *s, int error);
char	**create_a_copy_map(char **map);
int		check_for_zero(char	**matrix);
void	set_all_z(char	**map, int x, int y);
int		ft_input(int key_sim, t_map *s);
void	create_map(t_map *app, char *file);
void	ft_img(t_map *prom);
int		len_col(char **map);
int		check_other_char(char **matrix);
int		fill_img(t_cr_image *str_img, void *session);
int		error_print(int error);
int		check_pos_player(char **matrix, int x);
int		keep_filling_img(t_cr_image *str_img, void *session);

#endif
