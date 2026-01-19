/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 15:53:24 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

static int	list_last_value(t_lis *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

int	find_index(t_lis *a, int nbr)
{
	int	i;

	i = 0;
	while (a && a->value != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	find_place_b(t_lis *stack_b, int nbr_push)
{
	int		i;
	t_lis	*tmp;

	if (!stack_b || !stack_b->next)
		return (0);
	i = 1;
	if (nbr_push > stack_b->value && nbr_push < list_last_value(stack_b))
		i = 0;
	else if (nbr_push > max_value(stack_b) || nbr_push < min_value(stack_b))
		i = find_index(stack_b, max_value(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < nbr_push || tmp->value > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_lis *stack_a, int nbr_push)
{
	int		i;
	t_lis	*tmp;

	if (!stack_a || !stack_a->next)
		return (0);
	i = 1;
	if (nbr_push < stack_a->value && nbr_push > list_last_value(stack_a))
		i = 0;
	else if (nbr_push > max_value(stack_a) || nbr_push < min_value(stack_a))
		i = find_index(stack_a, min_value(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > nbr_push || tmp->value < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
