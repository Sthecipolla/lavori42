/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:40 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:17:28 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*

*/
bool	hit_cylinder(t_cylinder *cylinder, t_ray ray, t_hit *record)
{
	t_hit	wall_rec;
	t_hit	base_rec;
	bool	ret_wall;
	bool	ret_base;

	wall_rec.full = FALSE;
	base_rec.full = FALSE;
	ret_wall = hit_cylinder_wall(cylinder, ray, &wall_rec);
	ret_base = hit_cylinder_basis(cylinder, ray, &base_rec);
	if (ret_wall == FALSE && ret_base == FALSE)
		return (FALSE);
	if (ret_wall == TRUE && ret_base == FALSE)
		copy_hit_record(&wall_rec, record);
	else if (ret_wall == FALSE && ret_base == TRUE)
		copy_hit_record(&base_rec, record);
	else
	{
		if (wall_rec.t > base_rec.t)
			copy_hit_record(&base_rec, record);
		else
			copy_hit_record(&wall_rec, record);
	}
	return (TRUE);
}
