/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:46:04 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/15 16:26:55 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHLIB_H
# define MATHLIB_H

//	Libft headers
# include "../Libft/original_libft.h"
# include "../Personal-Libft/personal_libft.h"

//	System math library
# include <math.h>

//	Integers limits
# include <limits.h>

//	Boolean data type
# include <stdbool.h>

//	Define Pi
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

//	Abbreviations
typedef unsigned int		t_uint;
//typedef unsigned char	t_uchar;

//	Define small epsilons
# define EPSILON3	1e-3
# define EPSILON6	1e-6
# define EPSILON9	1e-9

//	Interations for ft_rand function
# define RAND_ITERS	1

//	Structure of a complex number
typedef struct s_complex
{
	double_t	real;
	double_t	imag;
}				t_complex;

//	Functions in file complex_operations1.c
t_complex	ft_c_init(double_t real, double_t imag);
t_complex	ft_c_conj(t_complex z);
double_t	ft_c_module2(t_complex z);
double_t	ft_c_module(t_complex z);
double_t	ft_c_argument(t_complex z);

//	Functions in file complex_operations2.c
t_complex	ft_c_sum(t_complex z1, t_complex z2);
t_complex	ft_c_difference(t_complex z1, t_complex z2);
t_complex	ft_c_multiplication(t_complex z1, t_complex z2);
t_complex	ft_c_reciprocal(t_complex z);
t_complex	ft_c_division(t_complex z1, t_complex z2);

//	Function in file complex_operations3.c
t_complex	ft_c_pow(t_complex z, int exp);

//	Structure of a 3D vector
struct s_vector3
{
	double_t	x;
	double_t	y;
	double_t	z;
};
typedef struct s_vector3	t_vector3;
typedef struct s_vector3	t_point3;

//	Functions in file vector3_operations1.c
t_vector3	v3_init(double_t x, double_t y, double_t z);
double_t	v3_module2(t_vector3 v);
double_t	v3_module(t_vector3 v);
t_vector3	v3_sum(t_vector3 v1, t_vector3 v2);
t_vector3	v3_diff(t_vector3 v1, t_vector3 v2);

//	Functions in file vector3_operations2.c
double_t	v3_dist2(t_point3 p1, t_point3 p2);
double_t	v3_dist(t_point3 p1, t_point3 p2);
t_vector3	v3_opposite(t_vector3 v);
t_vector3	v3_scalar_prod(double_t k, t_vector3 v);
t_vector3	v3_scalar_div(t_vector3 v, double_t t);

//	Functions in file vector3_operations3.c
t_vector3	v3_unit_vector(t_vector3 v);
double_t	v3_dot_prod(t_vector3 v1, t_vector3 v2);
t_vector3	v3_cross_prod(t_vector3 v1, t_vector3 v2);
double_t	v3_scalar_triple_prod(t_vector3 v1, t_vector3 v2, t_vector3 v3);
t_vector3	v3_vector_triple_prod(t_vector3 v1, t_vector3 v2, t_vector3 v3);

//	Functions in file vector3_operations4.c
t_vector3	v3_rotate_around_axis(t_vector3 v, t_vector3 axis, double_t theta);

//	Functions in file angles.c
double_t	normalize_degrees(double_t degrees);
double_t	normalize_radians(double_t radians);
double_t	deg_to_rad(double_t degrees);
double_t	rad_to_deg(double_t radians);

typedef struct s_scale
{
	double_t	min;
	double_t	max;
}				t_scale;

//	Other functions in their respective files
double_t	ft_scale(double_t num, t_scale old, t_scale new);
bool		ft_are_double_equal(double_t n1, double_t n2, double_t epsilon);
int			ft_rand(void);
int			ft_rand_with_seed(unsigned long new_seed, bool set_seed);

#endif