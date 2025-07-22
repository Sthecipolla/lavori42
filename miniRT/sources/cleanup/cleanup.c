/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:00:13 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
PARAMETERS
data:	struct which contains all the information that needs to be freed

DESCRIPTION
This function frees the memory allocated for the program miniRT.

RETURN VALUE
None.
*/
void	ft_cleanup(void *p)
{
	t_data	*data;

	if (p == NULL)
		return ;
	data = (t_data *) p;
	ft_clean_mlx(data->mlx);
	ft_clean_scene(data->scene, data->scene->num_objects);
	if (data->scene_bck != NULL)
		ft_clean_scene(data->scene_bck, data->scene_bck->num_objects);
	ft_clean_render(data->render);
	free(data);
}

/*
PARAMETERS
scene:	struct which contains all the information about the rendered scene

DESCRIPTION
This function frees the memory allocated for the scene in miniRT.

RETURN VALUE
None.
*/
void	ft_clean_scene(void *p, unsigned int i)
{
	t_scene	*scene;

	if (p == NULL)
		return ;
	scene = (t_scene *) p;
	(void) scene;
	free_camera(&scene->camera);
	free_ambient(&scene->ambient);
	free_lights(&scene->lights);
	free_objects(scene->objects, i);
	free(scene);
}

/*
PARAMETERS
mlx:	struct which contains all the information about the image & window

DESCRIPTION
This function frees the memory allocated for the mlx stuff.

RETURN VALUE
None.

EXPLANATION
The functions mlx_destroy_image and mlx_destroy_window free the respective image
and window pointers, so this function must not clean them. On the contrary, the
function mlx_destroy_display does not free the session pointer, so it must be
freed in this function.
*/
void	ft_clean_mlx(void *p)
{
	t_mlx	*mlx;

	if (p == NULL)
		return ;
	mlx = (t_mlx *) p;
	if (mlx->img.image != NULL)
		mlx_destroy_image(mlx->mlx_session, mlx->img.image);
	if (mlx->mlx_window != NULL && mlx->mlx_session != NULL)
		mlx_destroy_window(mlx->mlx_session, mlx->mlx_window);
	if (mlx->mlx_session != NULL)
	{
		mlx_destroy_display(mlx->mlx_session);
		free(mlx->mlx_session);
	}
	if (mlx->name != NULL)
		free(mlx->name);
	free(mlx);
}

/*
ADD DESCRIPTION
*/
void	ft_clean_render(void *p)
{
	t_render	*render;

	if (p == NULL)
		return ;
	render = (t_render *) p;
	if (render->camera != NULL)
		free(render->camera);
	if (render->img_settings != NULL)
		free(render->img_settings);
	if (render->viewport != NULL)
		free(render->viewport);
	free(render);
}

/*
PARAMETERS
data:	struct which contains all the information that needs to be freed

DESCRIPTION
This function frees the memory allocated for the program with the function
ft_cleanup and then it exits the program successfully.
This function is called by mlx_hook when the X button at the top right of the
window or the ESC key is pressed.

RETURN VALUE
None.
*/
int	ft_handle_close(t_data *data)
{
	unsigned char	errnmb;

	errnmb = data->errnmb;
	ft_cleanup(data);
	exit(errnmb);
}
