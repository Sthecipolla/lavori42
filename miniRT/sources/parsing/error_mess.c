/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 21:58:53 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static char	*type_of_error(int ev)
{
	if (ev == ECOLORS)
		return ("Invalid color value");
	else if (ev == EDIAMET)
		return ("Invalid diameter value");
	else if (ev == ECENTER)
		return ("Invalid center coordinates");
	else if (ev == ECOORDI)
		return ("Invalid coordinates");
	else if (ev == ENORMAL)
		return ("Invalid or not normalized vector");
	else if (ev == ENOTEXI)
		return ("Non-existent type");
	else if (ev == ERATIO)
		return ("Invalid ratio value");
	else if (ev == EFOV)
		return ("Invalid field of view (FOV) value");
	else if (ev == EBRIGHT)
		return ("Invalid brightness value");
	else if (ev == EHEIGHT)
		return ("Invalid height value");
	else if (ev == EINVAFF)
		return (EINVAFF_MSG);
	else if (ev == ENUMARG)
		return (ENUMARG_MSG);
	return (GENERIC_MSG);
}

static char	*ft_strerror(int errnmb)
{
	if (errnmb == E2SMALL)
		return (E2SMALL_MSG);
	else if (errnmb == EEMPTYF)
		return (EEMPTYF_MSG);
	else if (errnmb == EINVALF)
		return (EINVALF_MSG);
	else if (errnmb == ENOAMB)
		return (ENOAMB_MSG);
	else if (errnmb == ENOCAM)
		return (ENOCAM_MSG);
	else if (errnmb == ENOLIT)
		return (ENOLIT_MSG);
	else if (errnmb >= 135 && errnmb <= 146)
		return (type_of_error(errnmb));
	else if (errnmb == EALRAMB)
		return (EALRAMB_MSG);
	else if (errnmb == EALRCAM)
		return (EALRCAM_MSG);
	else
		return (strerror(errnmb));
}

int	ft_err_pri(char *func, char *s, t_data *data, int line)
{
	int	ev;

	ev = data->errnmb;
	ft_dprintf(STDERR_FILENO, "Error\n");
	if (s == NULL)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", func, ft_strerror(ev));
	else if (ev >= 135 && ev <= 148)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s on line %d: %s\n", func, s, line, \
			ft_strerror(ev));
		ev = EINVAFF;
	}
	else
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", func, s, ft_strerror(ev));
	return (ev);
}
