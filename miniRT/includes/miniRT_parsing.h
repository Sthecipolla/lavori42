/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:16 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "miniRT_external.h"
# include "miniRT_enums.h"
# include "miniRT_structs.h"

# define FAIL 3

//	Prototypes of functions in file ...

void		free_matrix(char **matrix);

char		*ft_safe_strjoin(char *s, char *s2, int frees);
char		*ft_add_char(char **str, char c);
int			skip_space(char *str, int i);
char		*remove_newline(char *str);

/*--------------------------------*/

int			ft_is_num(char *num, int skip);
int			ft_is_double(char *num);
int			ft_is_num_sign(char *num, int skip);
int			num_args(char **args, int num);
int			ft_err_pri(char *func, char *s, t_data *data, int line);
int			check_file(char *file, t_data *data);
int			check_value_norm_to_one(char **matrix, int skip);

/*--------------------------------*/

t_ambient	*ambient_light(char **coordinate, t_data *data);
t_camera	*camera(char **coordinate, t_data *data);
t_light		*light(char **coordinate, t_data *data);
t_sphere	*sphere(char **coordinate, t_data *data);
t_plane		*plane(char **coordinate, t_data *data, char **matr);
t_cylinder	*cylinder(char **coords, t_data *data, char **m, t_cylinder *cy);

/*--------------------------------*/

int			parse_scene(int argc, char **argv, t_data *data);
t_light		*add_light(t_light *light, t_data *data);
int			add_object(void *object, t_data *data, int typea);
t_ambient	*ambient_light(char **coordinate, t_data *data);
t_camera	*Camera(char **coordinate, t_data *data);
t_light		*Light(char **coordinate, t_data *data);
t_sphere	*Sphere(char **coordinate, t_data *data);
t_plane		*Plane(char **coordinate, t_data *data);
t_cylinder	*Cylinder(char **coordinate, t_data *data);

/*--------------------------------*/

void		print_scene_summary(t_scene *scene);
void		print_scene_debug(t_data *data);

/*--------------------------------*/

int			parse_scene(int argc, char **argv, t_data *data);

#endif