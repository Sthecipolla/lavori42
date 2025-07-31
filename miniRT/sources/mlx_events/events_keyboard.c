/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:39 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:13:47 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	handle_rotations(int keysym, t_data *data);
static void	handle_translations(int keysym, t_data *data);
static void	handle_scene_reset(t_data *data);
static void	handle_translations(int keysym, t_data *data);
static void	handle_change_properties(int keysym, t_data *data);

/*
PARAMETERS
keysym:	keycode of the pressed key on the keyboard
data:	struct which contains all the information about the image to render

DESCRIPTION
This function is called by mlx_hook when a key on the keyboard is pressed.
It handles the keys below:
-	ESC:		it closes the program
-	TO BE ADDED
This function also prints on the STDIN the keycode of the pressed key.
If the pressed key has a purposee, the correspondent function is called and the
image is then re-rendered to see the modifications.

RETURN VALUE
This function returns EXIT_SUCCESS = 0 if the pressed key has a purpose and
re-renders the image, it returns EXIT_FAILURE = 1 if it has no purpose.
*/
int	ft_handle_keys(int keysym, t_data *data)
{
	printf("Pressed key\t0x%04x\n", keysym);
	if (keysym == XK_Escape)
		ft_handle_close(data);
	else if (keysym == XK_Up || keysym == XK_Down || \
				keysym == XK_Left || keysym == XK_Right)
		handle_rotations(keysym, data);
	else if (keysym == XK_w || keysym == XK_a || keysym == XK_s || \
				keysym == XK_d || keysym == XK_Shift_L || keysym == XK_space)
		handle_translations(keysym, data);
	else if (keysym == XK_BackSpace)
		handle_scene_reset(data);
	else if (keysym == XK_1 || keysym == XK_2 || \
			keysym == XK_3 || keysym == XK_4 || keysym == XK_c)
		handle_change_properties(keysym, data);
	else if (keysym == XK_l)
		set_ambient_selected(data);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	handle_rotations(int keysym, t_data *data)
{
	if (data->sel_obj == NULL)
		camera_rotate(keysym, data);
	else
		object_rotate(keysym, data);
}

static void	handle_translations(int keysym, t_data *data)
{
	if (data->sel_obj == NULL && data->sel_light == NULL)
		camera_translate(keysym, data);
	else if (data->sel_obj != NULL)
		object_translate(keysym, data);
	else
		light_translate(keysym, data);
}

static void	handle_change_properties(int keysym, t_data *data)
{
	if (data->sel_obj == NULL && data->sel_light == NULL && \
			data->sel_amb == FALSE)
		ft_printf("Nothing selected\n");
	else if (data->sel_obj != NULL)
		object_change(keysym, data);
	else if (data->sel_light != NULL)
		light_change(keysym, data);
	else if (data->sel_amb == TRUE)
		ambient_change(keysym, data);
}

static void	handle_scene_reset(t_data *data)
{
	unset_selected(data);
	ft_clean_scene(data->scene, data->scene->num_objects);
	data->scene = ft_copy_scene(data->scene_bck);
	if (data->scene == NULL)
		return (ft_cleanup(data), exit(errno));
	ft_update_rendering_options(data->render, data->scene);
	ft_render(data);
}
