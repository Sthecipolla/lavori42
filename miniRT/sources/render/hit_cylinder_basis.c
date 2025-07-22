/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_basis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:16:31 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	hit_base(t_cylinder *cyl, t_ray ray, t_hit *rec, double_t h);

bool	hit_cylinder_basis(t_cylinder *cylinder, t_ray ray, t_hit *record)
{
	double_t	half_h;
	t_hit		base1_rec;
	t_hit		base2_rec;
	bool		ret1;
	bool		ret2;

	base1_rec.full = FALSE;
	base2_rec.full = FALSE;
	half_h = cylinder->height / 2.0;
	ret1 = hit_base(cylinder, ray, &base1_rec, (-half_h));
	ret2 = hit_base(cylinder, ray, &base2_rec, half_h);
	if (ret1 == FALSE && ret2 == FALSE)
		return (FALSE);
	if (ret1 == TRUE && ret2 == FALSE)
		copy_hit_record(&base1_rec, record);
	else if (ret1 == FALSE && ret2 == TRUE)
		copy_hit_record(&base2_rec, record);
	else
	{
		if (base1_rec.t > base2_rec.t)
			copy_hit_record(&base2_rec, record);
		else
			copy_hit_record(&base1_rec, record);
	}
	return (TRUE);
}

/*
EXPLANATION
The base of a cylinder is a planar circle, perpendicular to the axis of the
cylinder. To find the intersection between a ray and that circle, I use the
already written function about finding the intersection between a ray and a
plane. That plane contains the base center and has the cylinder axis as its
normal. Then, if the intersection with the plane is within the circle, that
is a hit and this function returns TRUE, otherwise it returns FALSE.
*/
static bool	hit_base(t_cylinder *cyl, t_ray ray, t_hit *rec, double_t h)
{
	t_point3	base_center;

	base_center = v3_sum(cyl->center, v3_scalar_prod(h, cyl->axis));
	if (hit_plane(base_center, v3_unit_vector(cyl->axis), ray, rec) == FALSE)
		return (FALSE);
	if (v3_dist(base_center, rec->point) > (cyl->diameter / 2.0))
	{
		rec->full = FALSE;
		return (FALSE);
	}
	return (TRUE);
}
