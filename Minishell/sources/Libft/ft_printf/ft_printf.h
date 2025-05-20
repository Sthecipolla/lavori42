/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:51:58 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:47:21 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/original_libft.h"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define DEC_BASE "0123456789"
# define HEX_LOWERCASE_BASE "0123456789abcdef"
# define HEX_UPPERCASE_BASE	"0123456789ABCDEF"

# define ERROR -1

int	ft_printf(const char *str, ...);
int	ft_dprintf(int fd, const char *str, ...);

int	ft_put_char(int fd, char c);
int	ft_put_string(int fd, char *s);
int	ft_put_address(int fd, void *mem);
int	ft_put_int_base(int fd, int nbr, char *base);
int	ft_put_unsigned_int_base(int fd, unsigned int nbr, char *base);
int	ft_put_unsigned_long_base(int fd, size_t nbr, char *base);

#endif