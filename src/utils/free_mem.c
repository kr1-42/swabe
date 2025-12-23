/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:09:26 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 20:17:02 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

void	free_list(t_lis *head)
{
	t_lis	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
		{
			if (split[i] == NULL)
				break ;
			if (split[i])
				free(split[i]);
			i++;
		}
	}
	free(split);
	split = NULL;
}
