/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:26:44 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:47:40 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_init_events(t_data *data);
static void	ft_init_data_to_null(t_data *data);

/*
PARAMETERS
argc:	argument counter
argv:	argument vector

DESCRIPTION
This function initialize the data structure, which will contain the scene to
render, the mlx stuff and the error number.

RETURN VALUE
Struct data which contains all the info of the program.
*/
t_data	*ft_init_data(int argc, char **argv)
{
	t_data	*data;
	int		exit_status;

	data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (ft_malloc_error(NULL, NULL), NULL);
	ft_init_data_to_null(data);
	parse_scene(argc, argv, data);
	if (data->errnmb != SUCCESS)
		return (exit_status = data->errnmb, ft_cleanup(data), \
			exit(exit_status), NULL);
	data->scene_bck = ft_copy_scene(data->scene);
	if (data->scene_bck == NULL)
		return (exit_status = data->errnmb, ft_cleanup(data), \
			exit(exit_status), NULL);
	data->render = ft_init_rendering_options(data->scene);
	if (data->render == NULL)
		return (exit_status = data->errnmb, ft_cleanup(data), \
			exit(exit_status), NULL);
	data->mlx = ft_init_mlx();
	if (data->mlx == NULL)
		return (exit_status = data->errnmb, ft_cleanup(data), \
			exit(exit_status), NULL);
	ft_init_events(data);
	return (data);
}

/*
PARAMETERS
None.

DESCRIPTION
This function initialize the mlx session, the window and the image for the
render.

RETURN VALUE
Struct mlx which contains all the info to display the image on the screen.

EXPLANATION
To show something on the screen using the mlx, I need to initialize 3 things: a
session with the X11 server (mlx_session), a window (mlx_window) and a image to
put into the window (img.image). The session is initialized with the mlx_init
function. The window is initialized with the mlx_new_window function, which
needs the previously opened session, width and heigth of the window, and a title 
(string) to show at the top of the window. The image is initialized using the
mlx_new_image function, which needs the previously opened session and width and 
heigth of the image. The image will contain the fractal and it will be put on
the window after the fractal is rendered. Data about the image is retrieved
using the mlx_get_data_addr function and saved in the img structure: img.addr
is a pointer to the first pixel of the image (an image is just a memory area)
and is returned by the function; img.bpp are the bits per pixel, img.line_len
is the length in bytes of a line (it can be longer than the width of the image
times the number of bytes per pixel because of data alignment and structure
padding), img.endian is set based on the endianess of the machine where the
program is compiled. More information can be found in the links below:
-	mlx: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
-	endianess: https://en.wikipedia.org/wiki/Endianness
At the end of the function all the value in the frac struct, the events hooks,
the color palette are initialized by the respective init functions.
*/
t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) ft_calloc(1, sizeof(t_mlx));
	if (mlx == NULL)
		return (ft_malloc_error(NULL, NULL), NULL);
	mlx->name = ft_strdup(WINDOW_TITLE);
	if (mlx->name == NULL)
		return (ft_malloc_error(mlx, free), NULL);
	mlx->mlx_session = mlx_init();
	if (mlx->mlx_session == NULL)
		return (free(mlx->name), ft_malloc_error(mlx, free), NULL);
	mlx->mlx_window = mlx_new_window(mlx->mlx_session, WIDTH, HEIGHT, \
		mlx->name);
	if (mlx->mlx_window == NULL)
		return (ft_malloc_error(mlx, ft_clean_mlx), NULL);
	mlx->img.image = mlx_new_image(mlx->mlx_session, WIDTH, HEIGHT);
	if (mlx->img.image == NULL)
		return (ft_malloc_error(mlx, ft_clean_mlx), NULL);
	mlx->img.addr = mlx_get_data_addr(mlx->img.image, &mlx->img.bpp, \
		&mlx->img.line_len, &mlx->img.endian);
	if (mlx->img.addr == NULL)
		return (ft_malloc_error(mlx, ft_clean_mlx), NULL);
	return (mlx);
}

/*
PARAMETERS
data:	struct which contains all the information of the program

DESCRIPTION
This function initialize the events hook of the program.

RETURN VALUE
None.

EXPLANATION
A event hook is something that listens to the events. The function mlx_hook
starts the hook, so the program starts listening to inputs. The input type is
described in the second parameter of mlx_hook: KeyPress listens to keyboard
inputs, ButtonPress listens to mouse input, DestroyNotify listens to the X
button situated at the top right of the window. Each event (input) has an accor-
ding mask: changing the mask gives more control on which inputs to accept or
reject. The masks set here are the default ones for the types of event chosen.
The fourth parameter of mlx_hook is the pointer to the function that will be
called when an event is detected. The fifth parameter of mlx_hook is the para-
meter that will be passed to the function pointed to by the pointer at the
fourth parameter of mlx_hook. The prototype of that function is different based
on the type of event, and it always has a void pointer as the last parameter,
which it will be populated by the fifth parameter of mlx_hook.
More information about the mlx events can be found in the documentation:
https://harm-smits.github.io/42docs/libs/minilibx/events.html
*/
static void	ft_init_events(t_data *data)
{
	mlx_hook(data->mlx->mlx_window, KeyPress, KeyPressMask, \
		ft_handle_keys, data);
	mlx_hook(data->mlx->mlx_window, ButtonPress, ButtonPressMask, \
		ft_handle_mouse, data);
	mlx_hook(data->mlx->mlx_window, DestroyNotify, StructureNotifyMask, \
		ft_handle_close, data);
}

static void	ft_init_data_to_null(t_data *data)
{
	if (data == NULL)
		return ;
	data->mlx = NULL;
	data->scene = NULL;
	data->scene_bck = NULL;
	data->render = NULL;
	data->sel_obj = NULL;
	data->sel_light = NULL;
	data->sel_amb = FALSE;
	data->errnmb = SUCCESS;
}
