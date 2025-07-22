/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_images.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:50:08 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 13:50:08 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_IMAGES_H
# define MINIRT_IMAGES_H

# include "miniRT_external.h"
# include "miniRT_structs.h"
# include <libft.h>

//	Abbreviations
typedef unsigned int		t_uint;

//	Struct that defines an image
typedef struct s_image
{
	void		*image;			/*	Pointer to image				*/
	char		*addr;			/*	Pointer to a single byte		*/
	int			bpp;			/*	Bits per pixel					*/
	int			line_len;		/*	Length in memory of a line		*/
	int			endian;			/*	Endianess yes or no				*/
}				t_image;

//	Struct to contain the fractal
typedef struct s_mlx
{
	//			Variables related to the image
	char		*name;			/*	Title of the window				*/
	void		*mlx_session;	/*	Session with the X11 server		*/
	void		*mlx_window;	/*	Pointer to the window			*/
	t_image		img;			/*	Actual image of the fractal		*/
}				t_mlx;

//	Window properties
# define HEIGHT				720
# define WIDTH				1280
# define WIDTH_MAX			15360
# define HEIGHT_MAX			15360
# define WINDOW_TITLE	"Best miniRT ever!"

#endif
