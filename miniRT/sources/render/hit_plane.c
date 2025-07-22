/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:44 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:17:50 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	set_record_zero(t_hit *record, t_ray ray, t_vector3 n);
static void	set_record(t_hit *record, t_ray ray, t_vector3 n, double_t t);

/*


EXPLANATION
The ray which starts from O (the camera) and goes int hte direction dir is:
ray:		P(t) = O + t * dir
The plane which contains the point Q and has normal norm has equation:
plane:		norm • (P - Q) = 0
Replacing P(t) from the ray equation into the plane equation, with some
calculations we obtain the linear equation below:
	t = [norm • (Q - O)] / (norm • dir)
This equation has a real solution if (norm • dir) != 0. If it is 0, than either
the ray is part of the plane or it is parallel to the plane. So the solutions
for t can either be infinite or zero.
*/
bool	hit_plane(t_point3 q, t_vector3 n, t_ray ray, t_hit *record)
{
	t_vector3	qo;
	double_t	nxdir;
	double_t	t;

	nxdir = v3_dot_prod(n, ray.dir);
	qo = v3_diff(q, ray.origin);
	if (ft_are_double_equal(nxdir, 0.0, EPSILON9) == TRUE)
	{
		if (ft_are_double_equal(v3_dot_prod(n, qo), 0.0, EPSILON9) == TRUE)
			return (set_record_zero(record, ray, n), TRUE);
		return (FALSE);
	}
	t = v3_dot_prod(n, qo) / nxdir;
	if (hit_acceptable_range(t) == FALSE)
		return (FALSE);
	set_record(record, ray, n, t);
	return (TRUE);
}

static void	set_record_zero(t_hit *record, t_ray ray, t_vector3 n)
{
	if (record == NULL)
		return ;
	record->full = TRUE;
	record->t = 0;
	record->point = ray_param_point(ray, 0);
	record->normal = n;
	record->front_face = TRUE;
}

static void	set_record(t_hit *record, t_ray ray, t_vector3 n, double_t t)
{
	if (record == NULL)
		return ;
	record->full = TRUE;
	record->t = t;
	record->point = ray_param_point(ray, t);
	if (v3_dot_prod(ray.dir, n) > 0.0)
	{
		record->normal = v3_opposite(n);
		record->front_face = FALSE;
	}
	else
	{
		record->normal = n;
		record->front_face = TRUE;
	}
}
