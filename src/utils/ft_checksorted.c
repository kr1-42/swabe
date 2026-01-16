/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:13:31 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/15 16:14:02 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	ft_checksorted(t_lis *stack)
{
	t_lis	*current;

	if (!stack)
		return (FALSE);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (ERROR);
		current = current->next;
	}
	return (SUCCESS);
}
