/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 15:53:24 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	apply_rarb(t_lis **a, t_lis **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && find_place_b(*b, c) > 0)
			ft_rr(a, b);
		while ((*a)->value != c)
			ft_ra(a);
		while (find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			ft_rr(a, b);
		while ((*b)->value != c)
			ft_rb(b);
		while (find_place_a(*a, c) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

int	apply_rrarrb(t_lis **a, t_lis **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && find_place_b(*b, c) > 0)
			ft_rrr(a, b);
		while ((*a)->value != c)
			ft_rra(a);
		while (find_place_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			ft_rrr(a, b);
		while ((*b)->value != c)
			ft_rrb(b);
		while (find_place_a(*a, c) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

int	apply_rrarb(t_lis **a, t_lis **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ft_rra(a);
		while (find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ft_rra(a);
		while ((*b)->value != c)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

int	apply_rarrb(t_lis **a, t_lis **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ft_ra(a);
		while (find_place_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ft_ra(a);
		while ((*b)->value != c)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}
