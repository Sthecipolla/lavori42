/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personal_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:23:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/08 16:22:54 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONAL_LIBFT_H
# define PERSONAL_LIBFT_H

# include "../Libft/original_libft.h"

// Personal functions
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*ft_strmap(const char *s, int (*f)(int));
double	ft_atof(const char *nptr);
char	*ft_ltoa(long n);
void	ft_lstrmnode(t_list **lst, t_list *node_to_rm, void (*del)(void *));

#endif