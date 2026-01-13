/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:09:26 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 16:10:16 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

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
