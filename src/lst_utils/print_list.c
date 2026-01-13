/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:57:22 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 16:13:17 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

void	print_list(t_lis *list)
{
	t_lis	*current;

	current = list;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
