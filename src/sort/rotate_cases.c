/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 15:53:24 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	case_rrarb_a(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = list_size(a) - find_place_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}

int	case_rarrb_a(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = list_size(b) - find_index(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

int	case_rrarrb_a(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = list_size(a) - find_place_a(a, c);
	if ((i < (list_size(b) - find_index(b, c))) && find_index(b, c))
		i = list_size(b) - find_index(b, c);
	return (i);
}

int	case_rarb_a(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	case_rarrb(t_lis *a, t_lis *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = list_size(b) - find_place_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
