/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:43 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:05:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	zoom(t_data *data, double_t zoom_factor);

/*
-	Button1 (left click):			select object
-	Button2 (scroll wheel click):	nothing
-	Button3 (right click):			deselect object
-	Button4 (scroll wheel up):		zoom
-	Button5 (scroll wheel down):	dezoom
*/
int	ft_handle_mouse(int button, int x, int y, t_data *data)
{
	printf("Pressed button\t%6d\tat x=%d y=%d\n", button, x, y);
	if (button == Button1)
		set_selected(x, y, data);
	else if (button == Button3)
		unset_selected(data);
	else if (button == Button5)
		zoom(data, 1.10);
	else if (button == Button4)
		zoom(data, 0.90);
	else
		return (EXIT_FAILURE);
	if (button == Button4 || button == Button5)
		ft_render(data);
	return (EXIT_SUCCESS);
}

static void	zoom(t_data *data, double_t zoom_factor)
{
	double_t	current_fov;
	double_t	new_fov;
	double_t	tan_half_fov;

	current_fov = data->scene->camera->fov;
	tan_half_fov = tan(deg_to_rad(current_fov / 2.0)) * zoom_factor;
	new_fov = rad_to_deg(2.0 * atan(tan_half_fov));
	if (new_fov <= 1.0)
		new_fov = 1.0;
	else if (new_fov >= 179.0)
		new_fov = 179.0;
	data->scene->camera->fov = new_fov;
	printf("New camera FOV: %.2f\n", new_fov);
	data->render->camera->hfov = data->scene->camera->fov;
	ft_update_vp(data->render->camera, data->render->img_settings, \
		data->render->viewport);
}
