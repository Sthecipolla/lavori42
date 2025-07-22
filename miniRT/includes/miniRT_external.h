/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_external.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:00 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 13:50:00 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EXTERNAL_H
# define MINIRT_EXTERNAL_H

//	EXTERNAL FUNCTIONS
# include <stdio.h>					/*	printf, perror						*/
# include <stdlib.h>				/*	malloc, free, exit					*/
# include <unistd.h>				/*	write, read, close 					*/
# include <fcntl.h>					/*	open								*/
# include <string.h>				/*	strerror							*/

//	MATH FUNCTIONS
# include <math.h>

//	LIBFT FUNCTIONS
# include <libft.h>

//	MINILIBX FUNCTIONS
# include <mlx.h>

//	X11 macros
# include <X11/X.h>
# include <X11/keysym.h>

//	OTHER EXTERNAL ELEMENTS
# include <stdbool.h>				/*	bool data type						*/
# include <limits.h>				/*	integer limits						*/
# include <errno.h>					/*	errno variable and error messages	*/

//	LUIS HAMILTON :)

#endif