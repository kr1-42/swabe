/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:03:37 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/16 18:08:51 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

void	push_smallest_to_b(t_lis **stack_a)
{
	t_lis	*current;
	int		smallest;
	int		position;
	int		index;

	current = *stack_a;
	smallest = current->value;
	position = 0;
	index = 0;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			position = index;
		}
		current = current->next;
		index++;
	}
	if (position <= 2)
		while (position-- > 0)
			ft_ra(stack_a);
	else
		while (position++ < 5)
			ft_rra(stack_a);
}

void	push_smallest_to_b_4(t_lis **stack_a)
{
	t_lis	*current;
	int		smallest;
	int		position;
	int		index;

	current = *stack_a;
	smallest = current->value;
	position = 0;
	index = 0;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			position = index;
		}
		current = current->next;
		index++;
	}
	if (position <= 2)
		while (position-- > 0)
			ft_ra(stack_a);
	else
		while (position++ < 4)
			ft_rra(stack_a);
}

void	ft_sort_five(t_lis **stack_a, t_lis **stack_b)
{
	push_smallest_to_b(stack_a);
	if (ft_checksorted(*stack_a) == SUCCESS)
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_four(t_lis **stack_a, t_lis **stack_b)
{
	push_smallest_to_b_4(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_three(t_lis **stack_a)
{
	int		a;
	int		b;
	int		c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b > c && a > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a > b && a > c && b < c)
		ft_ra(stack_a);
	else if (a > b && a < c)
		ft_sa(stack_a);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack_a);
}
