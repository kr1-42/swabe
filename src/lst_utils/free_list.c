/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:04:58 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 16:15:41 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

void	free_list(t_lis *head)
{
	t_lis	*temp;
	t_lis	*current;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
