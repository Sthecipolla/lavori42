/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_print_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:01:21 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 15:07:45 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keep_filling_img(t_cr_image *str_img,void* session)
{
	str_img[5].img = mlx_xpm_file_to_image(session, "./img_folder/ene1.xpm",
	&str_img[5].width, &str_img[5].height);
	if (str_img[5].img == NULL)
		return (0);
	str_img[6].img = mlx_xpm_file_to_image(session, "./img_folder/ene2.xpm",
	&str_img[6].width, &str_img[6].height);
	if (str_img[6].img == NULL)
		return (1);
	return (0);

}
