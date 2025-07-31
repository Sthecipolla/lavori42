/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_enums.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:49:40 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 13:51:36 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENUMS_H
# define MINIRT_ENUMS_H

//		Objects types
typedef enum e_obj_type		t_obj_type;
enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
};

//		Objects' color palette
typedef enum e_o_palette	t_o_palette;
enum e_o_palette
{
	O_DEFAULT,
	O_RED,
	O_BLUE,
	O_GREEN,
	O_YELLOW,
	O_PURPLE,
	O_ORANGE,
	O_PINK,
	O_TEAL,
	O_CYAN,
	O_MAGENTA,
	O_STOP,
};

//		Objects' color palette
typedef enum e_l_palette	t_l_palette;
enum e_l_palette
{
	L_DEFAULT,
	L_RED,
	L_BLUE,
	L_GREEN,
	L_WHITE,
	L_WARM_WHITE,
	L_COOL_WHITE,
	L_PURPLE,
	L_ORANGE,
	L_CYAN,
	L_MAGENTA,
	L_STOP,
};

#endif