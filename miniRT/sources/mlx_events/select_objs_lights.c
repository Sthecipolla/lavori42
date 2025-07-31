/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_objs_lights.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:54 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:14:20 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	print_selected_object(t_data *data);

void	set_selected(int x, int y, t_data *data)
{
	t_ray		ray;
	t_vector3	ray_dir;
	t_vector3	tmp;
	t_hit		o_rec;
	t_hit		l_rec;

	data->sel_amb = FALSE;
	tmp = v3_sum(v3_scalar_prod(x, data->render->viewport->pixel_delta_u), \
		v3_scalar_prod(y, data->render->viewport->pixel_delta_v));
	ray_dir = v3_diff(v3_sum(data->render->viewport->pixel_00_location, tmp), \
		data->render->camera->lookfrom);
	ray = ray_init(data->render->camera->lookfrom, ray_dir);
	data->sel_obj = find_hit_object(data->scene, ray, &o_rec);
	data->sel_light = find_hit_light(data->scene, ray, &l_rec);
	if (data->sel_obj != NULL && data->sel_light != NULL)
		null_farthest(&data->sel_obj, &data->sel_light, l_rec, o_rec);
	if (data->sel_obj != NULL && o_rec.full == TRUE)
		print_selected_object(data);
	else if (data->sel_light != NULL && l_rec.full == TRUE)
		ft_printf("Selected light: \t\t\t(%p)\n", data->sel_light);
	else
		ft_printf("Nothing selected\n");
}

static void	print_selected_object(t_data *data)
{
	ft_printf("Selected object: ");
	if (data->sel_obj->type == SPHERE)
		ft_printf("sphere\t\t(");
	else if (data->sel_obj->type == PLANE)
		ft_printf("plane\t\t(");
	else if (data->sel_obj->type == CYLINDER)
		ft_printf("cylinder\t(");
	ft_printf("%p)\n", data->sel_obj);
}

void	unset_selected(t_data *data)
{
	if (data->sel_obj != NULL)
	{
		ft_printf("Deselected object: ");
		if (data->sel_obj->type == SPHERE)
			ft_printf("sphere\t(");
		else if (data->sel_obj->type == PLANE)
			ft_printf("plane\t(");
		else if (data->sel_obj->type == CYLINDER)
			ft_printf("cylinder\t(");
		ft_printf("%p)\n", data->sel_obj);
	}
	else if (data->sel_light != NULL)
		ft_printf("Deselected light: \t\t(%p)\n", data->sel_light);
	else if (data->sel_amb == TRUE)
		ft_printf("Deselected ambient light\n");
	else
		ft_printf("Nothing to deselect\n");
	data->sel_obj = NULL;
	data->sel_light = NULL;
	data->sel_amb = FALSE;
}

void	set_ambient_selected(t_data *data)
{
	data->sel_amb = TRUE;
	data->sel_obj = NULL;
	data->sel_light = NULL;
	ft_printf("Ambient light selected\n");
}
