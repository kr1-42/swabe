/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 16:04:16 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

static void	apply_best_move_ab(t_lis **a, t_lis **b)
{
	int		best;
	t_lis	*tmp;

	if (!*a)
		return ;
	if (!*b)
	{
		ft_pb(a, b);
		return ;
	}
	best = rotate_type_ab(*a, *b);
	tmp = *a;
	while (tmp)
	{
		if (best == case_rarb(*a, *b, tmp->value))
			return ((void)apply_rarb(a, b, tmp->value, 'a'));
		if (best == case_rrarrb(*a, *b, tmp->value))
			return ((void)apply_rrarrb(a, b, tmp->value, 'a'));
		if (best == case_rarrb(*a, *b, tmp->value))
			return ((void)apply_rarrb(a, b, tmp->value, 'a'));
		if (best == case_rrarb(*a, *b, tmp->value))
			return ((void)apply_rrarb(a, b, tmp->value, 'a'));
		tmp = tmp->next;
	}
}

static void	apply_best_move_ba(t_lis **a, t_lis **b)
{
	int		best;
	t_lis	*tmp;

	if (!*b)
		return ;
	best = rotate_type_ba(*a, *b);
	tmp = *b;
	while (tmp)
	{
		if (best == case_rarb_a(*a, *b, tmp->value))
			return ((void)apply_rarb(a, b, tmp->value, 'b'));
		if (best == case_rrarrb_a(*a, *b, tmp->value))
			return ((void)apply_rrarrb(a, b, tmp->value, 'b'));
		if (best == case_rarrb_a(*a, *b, tmp->value))
			return ((void)apply_rarrb(a, b, tmp->value, 'b'));
		if (best == case_rrarb_a(*a, *b, tmp->value))
			return ((void)apply_rrarb(a, b, tmp->value, 'b'));
		tmp = tmp->next;
	}
}

static void	final_rotate(t_lis **stack_a)
{
	int	min;
	int	pos;
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	min = min_value(*stack_a);
	pos = find_index(*stack_a, min);
	size = list_size(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ft_ra(stack_a);
	else
		while (pos++ < size)
			ft_rra(stack_a);
}

void	sort_large_list(t_lis **stack_a)
{
	t_lis	*stack_b;

	if (!stack_a || !*stack_a)
		return ;
	if (ft_checksorted(*stack_a) == SUCCESS)
		return ;
	stack_b = NULL;
	while (list_size(*stack_a) > 3 && ft_checksorted(*stack_a) == ERROR)
		apply_best_move_ab(stack_a, &stack_b);
	if (list_size(*stack_a) == 3)
		ft_sort_three(stack_a);
	while (stack_b)
		apply_best_move_ba(stack_a, &stack_b);
	final_rotate(stack_a);
}

