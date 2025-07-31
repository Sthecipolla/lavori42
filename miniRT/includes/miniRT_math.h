/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:11 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 13:50:11 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_H
# define MINIRT_MATH_H

# include "miniRT_external.h"
# include "miniRT_enums.h"
# include "miniRT_structs.h"

typedef struct s_ray	t_ray;
typedef struct s_hit	t_hit;

struct s_ray
{
	t_point3	origin;
	t_vector3	dir;
};

struct s_hit
{
	bool		full;
	t_point3	point;
	t_vector3	normal;
	double_t	t;
	bool		front_face;
};

#endif