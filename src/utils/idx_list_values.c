/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_list_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:11:07 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 17:11:51 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

void	idx_list_values(t_lis *list)
{
	t_lis	*current;
	int		index;

	current = list;
	index = 0;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}
