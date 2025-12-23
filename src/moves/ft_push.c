/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:21:59 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 20:37:24 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_swap.h"

void	ft_push(t_lis **from, t_lis **to)
{
	t_lis	*tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from != NULL)
		(*from)->prev = NULL;
	tmp->next = *to;
	if (*to != NULL)
		(*to)->prev = tmp;
	tmp->prev = NULL;
	*to = tmp;
}

void	ft_pa(t_lis **stack_a, t_lis **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_lis **stack_a, t_lis **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
