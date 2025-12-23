/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:20:31 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 20:06:20 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	ft_err(void)
{
	write(2, ERR_MSG ,6);
	exit (ERROR);
	return (ERROR);
}

void	*ft_error_null(void)
{
	write(2, ERR_MSG ,6);
	exit (ERROR);
	return (NULL);
}
