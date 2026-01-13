/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:59:03 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 18:02:14 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

static void	sort_2_elements(t_lis **list)
{
	if ((*list)->value > (*list)->next->value)
		ft_sa(list);
}

static void	sort_3_elements(t_lis **list)
{
	int	first;
	int	second;
	int	third;

	first = (*list)->value;
	second = (*list)->next->value;
	third = (*list)->next->next->value;
	if (first > second && second < third && first < third)
		ft_sa(list);
	else if (first > second && second > third)
	{
		ft_sa(list);
		ft_rra(list);
	}
	else if (first > second && second < third && first > third)
		ft_ra(list);
	else if (first < second && second > third && first < third)
	{
		ft_sa(list);
		ft_ra(list);
	}
	else if (first < second && second > third && first > third)
		ft_rra(list);
}

static void	sort_5_elements(t_lis **list)
{
	t_lis	*stack_b;

	stack_b = NULL;
	while (list_size(*list) > 3)
	{
		if ((*list)->index == 0 || (*list)->index == 1)
			ft_pb(list, &stack_b);
		else
			ft_ra(list);
	}
	sort_3_elements(list);
	if (stack_b && stack_b->index == 1)
		ft_sb(&stack_b);
	while (stack_b)
		ft_pa(list, &stack_b);
}

void	sort_small_list(t_lis **list)
{
	int	size;

	size = list_size(*list);
	if (size == 2)
		sort_2_elements(list);
	else if (size == 3)
		sort_3_elements(list);
	else if (size > 3 && size <= 5)
		sort_5_elements(list);
}
