/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:26 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H

# include "miniRT_external.h"
# include "miniRT_enums.h"
# include "miniRT_images.h"
# include "miniRT_render.h"
# include <libft.h>

//	Abbreviations
typedef unsigned int		t_uint;

//	Color channel in TRGB coloring system
//	(or https://en.wikipedia.org/wiki/Japanese_honorifics#Chan)
typedef unsigned char		t_chan;

//	Structs typedefs
typedef struct s_scene		t_scene;
typedef struct s_camera		t_camera;
typedef struct s_ambient	t_ambient;
typedef struct s_light		t_light;
typedef union u_obj_union	t_obj_union;
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_color		t_color;
typedef struct s_data		t_data;
typedef struct s_lighting	t_lighting;

//	RGB Color struct
struct s_color
{
	t_chan		transparency;
	t_chan		red;
	t_chan		green;
	t_chan		blue;
};

//	RGB Color struct taht avoids overflowing
//	Needed for calculations
struct s_dcolor
{
	double_t	transparency;
	double_t	red;
	double_t	green;
	double_t	blue;	
};

//	Camera struct
struct s_camera
{
	t_point3	point;
	t_vector3	dir;
	double_t	fov;
};

//	Ambient light struct
struct s_ambient
{
	double_t	ratio;
	t_color		color;
	t_color		def_color;
};

//	light struct
struct s_light
{
	t_point3	point;
	double_t	ratio;
	t_color		color;
	t_color		def_color;
};

//	Sphere struct
struct s_sphere
{
	t_point3	center;
	double_t	diameter;
	t_color		color;
};

//	Plane struct
struct s_plane
{
	t_point3	point;
	t_vector3	normal;
	t_color		color;
};

//	Cylinder struct
struct s_cylinder
{
	t_point3	center;
	t_vector3	axis;
	double_t	diameter;
	double_t	height;
	t_color		color;
};

//	Object union
union u_obj_union
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
};

//	Object struct
struct s_object
{
	t_obj_type	type;
	t_obj_union	*object;
	t_color		def_color;
};

//	Scene struct
struct s_scene
{
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*lights;
	t_uint		num_lights;
	t_object	*objects;
	t_uint		num_objects;
};

struct s_data
{
	t_mlx		*mlx;
	t_scene		*scene;
	t_scene		*scene_bck;
	t_render	*render;
	t_object	*sel_obj;
	t_light		*sel_light;
	bool		sel_amb;
	t_chan		errnmb;
};

/*
light:	information about the light
l_dir:	direction from the hit point to the light
l_dist:	distance between the hit point and the light
c_dir:	direction from the hit point to the camera
*/
struct s_lighting
{
	t_light		*light;
	t_vector3	l_dir;
	double_t	l_dist;
	t_vector3	c_dir;
};

#endif
