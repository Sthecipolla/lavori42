/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:17:10 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:19:31 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_point3	ray_param_point(t_ray ray, double_t t)
{
	return (v3_sum(ray.origin, v3_scalar_prod(t, ray.dir)));
}

t_ray	ray_init(t_point3 origin, t_vector3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}
