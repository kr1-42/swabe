/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cases_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 15:53:24 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	case_rrarb(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = list_size(a) - find_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

int	case_rrarrb(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = list_size(b) - find_place_b(b, c);
	if ((i < (list_size(a) - find_index(a, c))) && find_index(a, c))
		i = list_size(a) - find_index(a, c);
	return (i);
}

int	case_rarb(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}
