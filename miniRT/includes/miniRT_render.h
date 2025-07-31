/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:20 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 13:50:20 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

# include "miniRT_external.h"
# include "miniRT_enums.h"
# include "miniRT_structs.h"
# include <libft.h>

//	Abbreviations
typedef unsigned int		t_uint;

typedef struct s_cam_sett	t_cam_sett;
struct s_cam_sett
{
	//	Camera center coordinates
	t_point3	lookfrom;
	//	Camera where it is pointing
	t_point3	lookat;
	//	Vertical vector starting from the camera
	t_vector3	vector_up;
	// Camera frame basis vectors
	t_vector3	u;
	t_vector3	v;
	t_vector3	w;
	//	Horizontal field of view
	double_t	hfov;
};

typedef struct s_img_sett	t_img_sett;
struct s_img_sett
{
	double_t	aspect_ratio;
	t_uint		img_width;
	t_uint		img_height;
	t_uint		samples_per_pixel;
	t_uint		max_depth;
};

typedef struct s_viewport	t_viewport;
struct s_viewport
{
	double_t	width;
	double_t	height;
	t_vector3	u;
	t_vector3	v;
	t_vector3	pixel_delta_u;
	t_vector3	pixel_delta_v;
	t_point3	up_left_corner;
	t_point3	pixel_00_location;
};

typedef struct s_render		t_render;
struct s_render
{
	t_cam_sett	*camera;
	t_img_sett	*img_settings;
	t_viewport	*viewport;
};

typedef struct s_cyl_wall	t_cyl_wall;
struct s_cyl_wall
{
	t_vector3	oc;
	double_t	dir_dot_ax;
	double_t	oc_dot_ax;
	t_vector3	x;
	t_vector3	y;
	double_t	a;
	double_t	b;
	double_t	c;
	double_t	delta;
	double_t	root;
	double_t	height_at_t;
};

# define SAMPLES_PER_PIXELS	10
# define MAX_DEPTH			10

#endif