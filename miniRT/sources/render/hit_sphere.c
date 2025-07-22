/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:18:08 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	sphere_set_normal(t_ray ray, t_hit *rec, t_point3 c, double_t r);
static void	set_record(t_hit *record, t_ray ray, double_t root);

/*


EXPLANATION
The ray which starts from O (the camera) and goes int hte direction dir is:
ray:		P(t) = O + t * dir
The sphere centered in C of radius r has equation:
sphere:		(C - P) • (C - P) = r^2
Replacing P(t) from the ray equation into the sphere equation, with some
calculations we obtain the quadratic equation below:
	t^2 dir • dir - 2t dir • (C - O) + (C - O) • (C - O) - r^2 = 0
In this equation
	a = dir • dir
	b = - 2 * dir • (C - O)
	c = (C - O) • (C - O) - r^2
And it is solved in t using the quadratic formula
	delta = b^2 - 4ac
	t = [-b ± sqrt(delta)] / 2a
See: https://en.wikipedia.org/wiki/Quadratic_formula
Since b has a -2 factor in it, we can use b = -2h, with h = dir • (C - O).
This simplifies the quadratic formula to
	delta = h^2 - ac
	t = [h ± sqrt(delta)] / a
And the simplified calculations for a, h, c are:
	a = |dir|^2
	h = dir • (C - O)
	c = |C - O|^2 - r^2
*/
bool	hit_sphere(t_point3	center, double_t r, t_ray ray, t_hit *record)
{
	t_vector3	oc;
	double_t	a;
	double_t	h;
	double_t	delta;
	double_t	root;

	oc = v3_diff(center, ray.origin);
	a = v3_module2(ray.dir);
	h = v3_dot_prod(ray.dir, oc);
	delta = (h * h) - (a * (v3_module2(oc) - (r * r)));
	if (delta < 0)
		return (FALSE);
	root = (h - sqrt(delta)) / a;
	if (hit_acceptable_range(root) == FALSE)
	{
		root = (h + sqrt(delta)) / a;
		if (hit_acceptable_range(root) == FALSE)
			return (FALSE);
	}
	set_record(record, ray, root);
	sphere_set_normal(ray, record, center, r);
	return (TRUE);
}

static void	sphere_set_normal(t_ray ray, t_hit *rec, t_point3 c, double_t r)
{
	t_vector3	outward_normal;

	if (rec == NULL)
		return ;
	outward_normal = v3_scalar_div(v3_diff(rec->point, c), r);
	if (v3_dot_prod(ray.dir, outward_normal) > 0.0)
	{
		rec->normal = v3_opposite(outward_normal);
		rec->front_face = FALSE;
	}
	else
	{
		rec->normal = outward_normal;
		rec->front_face = TRUE;
	}
}

static void	set_record(t_hit *record, t_ray ray, double_t root)
{
	if (record == NULL)
		return ;
	record->full = TRUE;
	record->t = root;
	record->point = ray_param_point(ray, root);
}
