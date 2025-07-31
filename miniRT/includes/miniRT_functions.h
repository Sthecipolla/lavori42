/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:04 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

# include "miniRT_external.h"
# include "miniRT_enums.h"
# include "miniRT_structs.h"
# include "miniRT_math.h"

//
//		CLEANUP

//	Prototypes of functions in file cleanup.c
void		ft_cleanup(void *p);
void		ft_clean_scene(void *p, unsigned int i);
void		ft_clean_mlx(void *p);
void		ft_clean_render(void *p);
int			ft_handle_close(t_data *data);

//	Prototypes of functions in file expand_clean.c
void		free_camera(t_camera **camera);
void		free_ambient(t_ambient **ambient);
void		free_lights(t_light **light);
void		free_objects(t_object *object, unsigned int i);

//
//		ERRORS

//	Prototypes of functions in file error_management.c
int			ft_print_error(char *func, char *s, int ev);
void		ft_malloc_error(void *p, void (*free)(void *));

//
//		MATH_UTILS

//	Prototypes of functions in file rays.c
t_point3	ray_param_point(t_ray ray, double_t t);
t_ray		ray_init(t_point3 origin, t_vector3 dir);

//
//		COLORS

//	Prototypes of functions in file colors_management.c
void		ft_pixel_put(t_image *img, int x, int y, int color);
int			ft_get_pixel_color(t_image *img, int x, int y);

//	Prototypes of functions in file colors_utils1.c
int			ft_create_trgb(int transparency, int red, int green, int blue);
int			ft_get_transparency(int trgb);
int			ft_get_red(int trgb);
int			ft_get_green(int trgb);
int			ft_get_blue(int trgb);

//	Prototypes of functions in file colors_utils2.c
t_color		color_multiply(t_color c1, t_color c2);
t_color		color_add(t_color c1, t_color c2);
t_color		color_scale(t_color color, double_t scale);

//	Prototypes of functions in file colors_palettes.c
t_color		return_palette_object(t_object *obj);
t_color		return_palette_light(t_light *light);
t_color		return_palette_ambient(t_ambient *amb);

//
//		MLX

//	Prototypes of functions in file events_keyboard.c
int			ft_handle_keys(int keysym, t_data *data);

//	Prototypes of functions in file events_mouse.c
int			ft_handle_mouse(int button, int x, int y, t_data *data);

//	Prototypes of functions in file select_objs_lights.c
void		set_selected(int x, int y, t_data *data);
void		unset_selected(t_data *data);
void		set_ambient_selected(t_data *data);

//	Prototypes of functions in file update_render.c
void		ft_update_rendering_options(t_render *render, t_scene *scene);
void		ft_update_camera_settings(t_cam_sett *camera, t_scene *scene);
void		ft_update_vp(t_cam_sett *cam, t_img_sett *img_s, t_viewport *vp);

//	Prototypes of functions in file camera_rotation.c
void		camera_rotate(int keysym, t_data *data);

//	Prototypes of functions in file camera_translation.c
void		camera_translate(int keysym, t_data *data);

//	Prototypes of functions in file change_obj_properties.c
void		object_change(int keysym, t_data *data);

//	Prototypes of functions in file change_light_properties.c
void		light_change(int keysym, t_data *data);
void		ambient_change(int keysym, t_data *data);

//	Prototypes of functions in file object_rotation.c
void		object_rotate(int keysym, t_data *data);

//	Prototypes of functions in file object_translation.c
void		object_translate(int keysym, t_data *data);
void		light_translate(int keysym, t_data *data);

//
//		INIT

//	Prototypes of functions in file init_mlx.c
t_data		*ft_init_data(int argc, char **argv);
t_mlx		*ft_init_mlx(void);

//	Prototypes of functions in file init_render.c
t_render	*ft_init_rendering_options(t_scene *scene);

//	Prototypes of functions in file init_scene.c
t_scene		*ft_init_scene(void);

//	Prototypes of functions in file copy_scene.c
t_scene		*ft_copy_scene(t_scene *scene);

//	Prototypes of functions in file init_scene_obj.c
int			copy_objs(t_scene original, t_scene *copy);

//
//		PARSING

//

//
//		RENDER

//	Prototypes of functions in file render.c
void		ft_render(t_data *data);
void		null_farthest(t_object **o, t_light **l, t_hit l_rec, t_hit o_rec);

//	Prototypes of functions in file lighting.c
t_color		calc_light(t_scene *scene, t_hit *hit, t_ray ray, t_object *hit_o);

//	Prototypes of functions in file object_utils.c
t_color		get_object_color(t_object *object);
t_object	*find_hit_object(t_scene *scene, t_ray ray, t_hit *hit_record);

//	Prototypes of functions in file light_utils.c
t_light		*find_hit_light(t_scene *scene, t_ray ray, t_hit *record);

//	Prototypes of functions in file hit_anything.c
bool		hit_anything(t_scene *scene, t_ray ray, t_hit *record);
void		copy_hit_record(t_hit *origin, t_hit *dest);
bool		hit_acceptable_range(double_t t);

//	Prototypes of functions in file hit_<object_name>.c
bool		hit_sphere(t_point3	center, double_t r, t_ray ray, t_hit *record);
bool		hit_plane(t_point3 q, t_vector3 n, t_ray ray, t_hit *record);
bool		hit_cylinder(t_cylinder *cylinder, t_ray ray, t_hit *record);
bool		hit_cylinder_wall(t_cylinder *cylinder, t_ray ray, t_hit *record);
bool		hit_cylinder_basis(t_cylinder *cylinder, t_ray ray, t_hit *record);

//	Prototypes of functions in file 

//
//		MAIN

//	Prototypes of functions in file main.c
int			main(int argc, char **argv);

#endif
