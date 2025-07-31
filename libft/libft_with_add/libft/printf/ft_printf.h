/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:22:50 by lhima             #+#    #+#             */
/*   Updated: 2024/12/10 15:33:19 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>

int			ft_printf(const char *c, ...);
int			ft_putnbr_base(unsigned int nbr, char *base);
int			ft_addpo(unsigned long nbr);
int			ft_putchare_fd(char c, int fd);
int			ft_putstra_fd(char *s, int fd);
int			ft_putnbre_fd(int n, int fd, int len);
size_t		ft_strlen(const char *c);

#endif
