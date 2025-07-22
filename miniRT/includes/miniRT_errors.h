/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:49:52 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 22:22:25 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERRORS_H
# define MINIRT_ERRORS_H

//	Unix error codes
# include <errno.h>
# define SUCCESS		0		/*	Suckseed							*/
# define E2SMALL 		41		/*	Argument list too short				*/
# define EEMPTYF		58		/*	Empty file							*/
# define EINVALF		134		/*	Invalid file						*/

# define ECOLORS		135		/*	Invalid color						*/ 
# define EDIAMET		136		/*	Invalid diameter					*/
# define ECENTER		137		/*	Invalid center						*/
# define ECOORDI		138		/*	Invalid coordinates					*/
# define ENORMAL		139		/*	Invalid not normalized				*/
# define ENOTEXI		140		/*	Invalid not existing type			*/
# define ERATIO			141		/*	Invalid ratio						*/
# define EFOV			142		/*	Invalid FOV							*/
# define EBRIGHT		143		/*	Invalid brightness					*/
# define EINVAFF		144		/*	Invalid content of the file			*/
# define EHEIGHT		145		/*	Invalid height						*/
# define ENUMARG		146		/*	Incorrect number of arguments		*/
# define EALRAMB		147		/*	Ambient light already present		*/
# define EALRCAM		148		/*	Camera already present				*/

# define EMACROS		192		/*	Error in macro settings				*/
# define ENOAMB			193		/*	No ambient light in the input file	*/
# define ENOCAM			194		/*	No camera in the input file			*/
# define ENOLIT			195		/*	No lights in the input file			*/

//	Error messages
# define E2SMALL_MSG	"Argument list too short"
# define EEMPTYF_MSG	"Input file is empty"
# define EINVALF_MSG	"Invalid input file"
# define EINVAFF_MSG	"Invalid content of the file"

# define ENUMARG_MSG	"Incorrect number of arguments"
# define EALRAMB_MSG	"Ambient light already present"
# define EALRCAM_MSG	"Camera already present"
# define GENERIC_MSG	"Invalid content of the file"
# define EMACROS_MSG	"Error in macro settings"

# define ENOAMB_MSG		"No ambient light in the input file"
# define ENOCAM_MSG		"No camera in the input file"
# define ENOLIT_MSG		"No lights in the input file"

//--------------------------------------------------

#endif