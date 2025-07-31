/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:47:09 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/04 11:44:10 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <unistd.h>

# define WIN_X 1500
# define WIN_Y 1000

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_mat
{
	int	**mat;
	int	x;
	int	y;

}			t_mat;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_mat		mat;
	double		angle_x;
	double		angle_y;
	int			zoom;
	int			offset_x;
	int			offset_y;
	int			win_x;
	int			win_y;
}				t_window;

// Struttura per gestire i dati dell'immagine
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_point_3
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
}	t_point_3;

typedef struct s_iter
{
	int	i;
	int	j;
}	t_iter;

typedef struct s_drawing_context
{
	t_mat		*mat;
	t_image		*img;
	t_window	*qwe;
	int			scale;
}				t_drawing_context;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}				t_line;

// Funzioni per la gestione dell'immagine
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

// Funzioni per la gestione della proiezione isometrica
void	iso_projection(int *x, int *y, int z, t_window *qwe);
void	parsing(t_mat *mat, char *file);

// Funzioni per l'algoritmo di Bresenham
void	calculate_dx_dy(t_point p1, t_point p2, int *dx, int *dy);
void	calculate_step(t_point p1, t_point p2, int *sx, int *sy);
void	calculate_error(int dx, int dy, int *err);

// Funzioni per disegnare punti e linee
void	draw_point(t_image *img, t_point p, int color);
void	draw_line(t_image *img, t_point p1, t_point p2, int color);
void	ft_start_point(t_point *p, int x, int y, int z);
void	ft_start_point2(t_point *p, t_iter iter, int scale, int z);
void	ft_start_point3(t_point *p, t_iter iter, int scale, int z);
void	ft_start_point4(t_point *p, t_iter iter, int scale, int z);
void	ft_set(t_point *p, int offset_x, int offset_y);
void	draw_current_point(t_drawing_context *ctx, t_point_3 *p1, t_iter iter);
void	draw_horizontal_l(t_drawing_context *ctx, t_point_3 *p1, t_iter iter);
void	draw_vertical_line(t_drawing_context *ctx, t_point_3 *p1, t_iter iter);
void	create_imagine(t_mat *mat, t_image img, t_window *qwe);
void	draw_map(t_mat *mat, t_image img, t_window *qwe);

// Funzioni per la gestione della mappa
int		mat_len(char **tmp);
int		ft_safe_fd(char *filename);
void	ft_check_nbr_col(char *filename);
int		*fun(char **tmp, int size);
void	print_mat(t_mat mat);
void	free_int_matrix(int **mat);
void	check_name(char *filename);
void	ft_check_nbr_col(char *filename);
int		close_window(void *param);
void	create_imagine(t_mat *mat, t_image img, t_window *qwe);
int		scale(t_window *qwe);
int		mouse_move(int x, int y, t_window *qwe);
int		key_press(int keycode, t_window *qwe);
int		handle_input(t_window *qwe);
int		close_window(void *param);
int		key_press(int keycode, t_window *qwe);
void	resize_window(t_window *qwe, int new_width, int new_height);

#endif
