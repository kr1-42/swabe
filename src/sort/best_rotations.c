/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 15:53:24 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	rotate_type_ba(t_lis *a, t_lis *b)
{
	int		i;
	t_lis	*tmp;

	if (!a || !b)
		return (0);
	tmp = b;
	i = case_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->value))
			i = case_rarb_a(a, b, tmp->value);
		if (i > case_rrarrb_a(a, b, tmp->value))
			i = case_rrarrb_a(a, b, tmp->value);
		if (i > case_rarrb_a(a, b, tmp->value))
			i = case_rarrb_a(a, b, tmp->value);
		if (i > case_rrarb_a(a, b, tmp->value))
			i = case_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_lis *a, t_lis *b)
{
	int		i;
	t_lis	*tmp;

	if (!a || !b)
		return (0);
	tmp = a;
	i = case_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->value))
			i = case_rarb(a, b, tmp->value);
		if (i > case_rrarrb(a, b, tmp->value))
			i = case_rrarrb(a, b, tmp->value);
		if (i > case_rarrb(a, b, tmp->value))
			i = case_rarrb(a, b, tmp->value);
		if (i > case_rrarb(a, b, tmp->value))
			i = case_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
