/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:35 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:16:35 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	calc_roots(t_cylinder *cylinder, t_ray ray, t_cyl_wall *tab);
static bool	check_height(t_cylinder *cyl, t_cyl_wall *tab);
static void	set_record(t_ray ray, t_hit *record, t_cyl_wall tab);
static void	set_normal(t_cylinder *cyl, t_ray ray, t_hit *rec, t_cyl_wall tab);

/*
EXPLANATION
The ray which starts from O (the camera) and goes int hte direction dir is:
ray:			P(t) = O + t * dir
The wall of the cylinder centered in C of axis ax has equation:
cylinder:		|(P - C) - [(P - C) • ax] ax|^2 = r^2
Replacing P(t) from the ray equation into the cylinder equation, with some
calculations we obtain the equation below:
	|t [dir - (dir • ax) ax] + [(O - C) - ((O - C) • ax) ax]|^2 = r^2
Calling x = [dir - (dir • ax) ax] and y = [(O - C) - ((O - C) • ax) ax], 
the equation above becomes:
	|t x + y|^2 = r^2
And with some other calculations we obtain the quadratic equation below:
	t^2 x • x + 2t x • y + y • y - r^2 = 0
In this equation
	a = x • x = |x|^2
	b = 2 * x • y
	c = y • y - r^2
And it is solved in t using the quadratic formula
	delta = b^2 - 4ac
	t = [-b ± sqrt(delta)] / 2a
See: https://en.wikipedia.org/wiki/Quadratic_formula
*/
bool	hit_cylinder_wall(t_cylinder *cylinder, t_ray ray, t_hit *record)
{
	t_cyl_wall	tab;

	if (calc_roots(cylinder, ray, &tab) == FALSE)
		return (FALSE);
	set_record(ray, record, tab);
	set_normal(cylinder, ray, record, tab);
	return (TRUE);
}

static bool	calc_roots(t_cylinder *cylinder, t_ray ray, t_cyl_wall *tab)
{
	tab->oc = v3_diff(ray.origin, cylinder->center);
	tab->dir_dot_ax = v3_dot_prod(ray.dir, cylinder->axis);
	tab->oc_dot_ax = v3_dot_prod(tab->oc, cylinder->axis);
	tab->x = v3_diff(ray.dir, v3_scalar_prod(tab->dir_dot_ax, cylinder->axis));
	tab->y = v3_diff(tab->oc, v3_scalar_prod(tab->oc_dot_ax, cylinder->axis));
	tab->a = v3_module2(tab->x);
	tab->b = 2.0 * v3_dot_prod(tab->x, tab->y);
	tab->c = v3_module2(tab->y) - \
		((cylinder->diameter * cylinder->diameter) / 4.0);
	tab->delta = (tab->b * tab->b) - (4.0 * tab->a * tab->c);
	if (tab->delta < 0)
		return (FALSE);
	tab->root = ((-tab->b) - sqrt(tab->delta)) / (2.0 * tab->a);
	if (hit_acceptable_range(tab->root) == FALSE || \
			check_height(cylinder, tab) == FALSE)
	{
		tab->root = ((-tab->b) + sqrt(tab->delta)) / (2.0 * tab->a);
		if (hit_acceptable_range(tab->root) == FALSE || \
				check_height(cylinder, tab) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

static bool	check_height(t_cylinder *cyl, t_cyl_wall *tab)
{
	tab->height_at_t = tab->oc_dot_ax + tab->root * tab->dir_dot_ax;
	if (tab->height_at_t < (-cyl->height * 0.5) || \
			tab->height_at_t > cyl->height * 0.5)
		return (FALSE);
	return (TRUE);
}

static void	set_record(t_ray ray, t_hit *record, t_cyl_wall tab)
{
	if (record == NULL)
		return ;
	record->full = TRUE;
	record->t = tab.root;
	record->point = ray_param_point(ray, tab.root);
}

static void	set_normal(t_cylinder *cyl, t_ray ray, t_hit *rec, t_cyl_wall tab)
{
	t_vector3	outward_normal;
	t_point3	axis_p;

	if (rec == NULL)
		return ;
	axis_p = v3_sum(cyl->center, v3_scalar_prod(tab.height_at_t, cyl->axis));
	outward_normal = v3_unit_vector(v3_diff(rec->point, axis_p));
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
