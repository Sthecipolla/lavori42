/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personal_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:23:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/09 14:45:50 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONAL_LIBFT_H
# define PERSONAL_LIBFT_H

# include "../Libft/original_libft.h"

# include <stdbool.h>

// Personal functions
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*ft_strmap(const char *s, int (*f)(int));
double	ft_atof(const char *nptr);
char	*ft_ltoa(long n);
void	ft_lstrmnode(t_list **lst, t_list *node_to_rm, void (*del)(void *));
void	free_char_matrix2(void *p);
void	free_char_matrix3(void *p);
char	**ft_split_alt(char const *s, char *dels);

#endif