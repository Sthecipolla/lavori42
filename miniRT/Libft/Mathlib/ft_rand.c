/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:00:03 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/15 16:27:23 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

#define A		1664525UL
#define C		1013904223UL
#define M		4294967296UL

// Linear Congruential Generator standard
int	ft_rand(void)
{
	static unsigned long	seed;

	if (seed == 0)
		seed = 1;
	seed = (A * seed + C) % M;
	return (seed % ((unsigned long) RAND_MAX + 1UL));
}

// Versione di ft_rand che accetta l'impostazione del seed
int	ft_rand_with_seed(unsigned long new_seed, bool set_seed)
{
	static unsigned long	seed;

	if (seed == 0)
		seed = 1;
	if (set_seed == TRUE)
		seed = new_seed;
	seed = (A * seed + C) % M;
	return (seed % (RAND_MAX + 1UL));
}
