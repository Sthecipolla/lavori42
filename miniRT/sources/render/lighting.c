/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:58 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

// Evita self-shadowing
#define SHADOW_BIAS 0.001
#define KD			1.0
#define KS			0.8
#define N_SPECULAR	32.0

// Coefficient of linear attenuation for diffuse lighting
#define CLAD		0.1
// Coefficient of quadratic attenuation for diffuse lighting
#define CQAD		0.0001
// Coefficient of linear attenuation for specular lighting
#define CLAS		0.01
// Coefficient of quadratic attenuation for specular lighting
#define CQAS		0.0001

static t_color	calc_ambient_light(t_ambient *ambient, t_color obj_color);
static t_color	calc_diffuse_light(t_lighting l, t_hit *hit, t_color obj_color);
static t_color	calc_spec_light(t_lighting l, t_hit *h, double_t n, t_color oc);
static bool		is_in_shadow(t_scene *scene, t_lighting l, t_hit *hit);

/*
DESCRIPTION
Calcola l'illuminazione completa per un punto colpito da un raggio.
Implementa il modello di illuminazione di Phong con:
- Luce ambientale diffusa
- Luce diffusa con ombre
*/
t_color	calc_light(t_scene *scene, t_hit *hit, t_ray ray, t_object *hit_o)
{
	t_color		color;
	t_uint		i;
	t_lighting	l;
	t_color		obj_color;

	obj_color = get_object_color(hit_o);
	color = (t_color){0, 0, 0, 0};
	color = color_add(color, calc_ambient_light(scene->ambient, obj_color));
	i = 0;
	while (i < scene->num_lights)
	{
		l.light = &scene->lights[i];
		l.l_dist = v3_dist(hit->point, l.light->point);
		l.l_dir = v3_unit_vector(v3_diff(l.light->point, hit->point));
		if (is_in_shadow(scene, l, hit) == FALSE)
		{
			l.c_dir = v3_unit_vector(v3_opposite(ray.dir));
			color = color_add(color, calc_diffuse_light(l, hit, obj_color));
			if (hit_o->type != PLANE)
				color = color_add(color, \
					calc_spec_light(l, hit, N_SPECULAR, obj_color));
		}
		i++;
	}
	return (color);
}

/*
DESCRIPTION
Calcola il contributo della luce ambientale.
La luce ambientale è uniforme e arriva da tutte le direzioni.
*/
static t_color	calc_ambient_light(t_ambient *ambient, t_color obj_color)
{
	t_color		ambient_color;
	double_t	ka[3];

	ka[0] = ((double_t) ambient->color.red / 255.0);
	ka[1] = ((double_t) ambient->color.green / 255.0);
	ka[2] = ((double_t) ambient->color.blue / 255.0);
	ambient_color.red = (t_chan) \
		fmin(255.0, obj_color.red * ka[0] * ambient->ratio);
	ambient_color.green = (t_chan) \
		fmin(255.0, obj_color.green * ka[1] * ambient->ratio);
	ambient_color.blue = (t_chan) \
		fmin(255.0, obj_color.blue * ka[2] * ambient->ratio);
	ambient_color.transparency = obj_color.transparency;
	return (ambient_color);
}

/*
DESCRIPTION
Calcola il contributo della luce diffusa usando la legge di Lambert.
L'intensità è proporzionale al coseno dell'angolo tra normale e direzione luce.
*/
static t_color	calc_diffuse_light(t_lighting l, t_hit *hit, t_color obj_color)
{
	double_t	attenuation;
	double_t	intensity;
	double_t	dot_prod;
	t_color		color;

	dot_prod = v3_dot_prod(hit->normal, l.l_dir);
	if (dot_prod < 0.0)
		return ((t_color){0, 0, 0, 0});
	attenuation = 1.0 / (1.0 + CLAD * l.l_dist + CQAD * l.l_dist * l.l_dist);
	intensity = l.light->ratio * attenuation * dot_prod;
	color.red = (t_chan) fmin(255.0, KD * obj_color.red * \
		(l.light->color.red / 255.0) * intensity);
	color.green = (t_chan) fmin(255.0, KD * obj_color.green * \
		(l.light->color.green / 255.0) * intensity);
	color.blue = (t_chan) fmin(255.0, KD * obj_color.blue * \
		(l.light->color.blue / 255.0) * intensity);
	color.transparency = obj_color.transparency;
	return (color);
}

static t_color	calc_spec_light(t_lighting l, t_hit *h, double_t n, t_color oc)
{
	t_vector3	refl;
	double_t	attenuation;
	double_t	intensity;
	double_t	tmp;
	t_color		color;

	tmp = v3_dot_prod(l.l_dir, h->normal);
	if (tmp < 0.0)
		return ((t_color){0, 0, 0, 0});
	refl = v3_diff(v3_scalar_prod(2.0 * tmp, h->normal), l.l_dir);
	attenuation = 1.0 / (1.0 + CLAS * l.l_dist + CQAS * l.l_dist * l.l_dist);
	tmp = v3_dot_prod(refl, l.c_dir);
	if (tmp < 0.0)
		return ((t_color){0, 0, 0, 0});
	intensity = l.light->ratio * attenuation * \
		pow(tmp, n);
	color.red = (t_chan) fmin(255.0, KS * oc.red * \
		(l.light->color.red / 255.0) * intensity);
	color.green = (t_chan) fmin(255.0, KS * oc.green * \
		(l.light->color.green / 255.0) * intensity);
	color.blue = (t_chan) fmin(255.0, KS * oc.blue * \
		(l.light->color.blue / 255.0) * intensity);
	color.transparency = oc.transparency;
	return (color);
}

/*
DESCRIPTION
This function verifies if a point (hit_point) is in shadow from a light source
(situated at light_pos). It shoots a ray from the hit_point to light_pos: if it
hits another objects, the hit_point is in shadow.
The ray origin is not precisely hit_point, but a point on the ray itself at a
distance of 0.001 from hit_point in the direction of the lght. This avoids the
self-shadowing, a phonomenon where the ray hits the same objects from which it
started and so hit_point results in shadow even if it is not. Self-shadowing is
due to precision issues between floating point numbers.
If you want to see the self-shadowing with your own eyes, just set the macro
SHADOW_BIAS at the beginning of this file to 0.
*/
static bool	is_in_shadow(t_scene *scene, t_lighting l, t_hit *hit)
{
	t_ray		shadow_ray;
	t_hit		shadow_hit;

	shadow_ray.dir = l.l_dir;
	shadow_ray.origin = v3_sum(hit->point, \
		v3_scalar_prod(SHADOW_BIAS, hit->normal));
	shadow_hit.full = FALSE;
	if (hit_anything(scene, shadow_ray, &shadow_hit) == TRUE)
	{
		if (shadow_hit.t < l.l_dist - SHADOW_BIAS)
			return (TRUE);
	}
	return (FALSE);
}
