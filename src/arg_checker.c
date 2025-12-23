/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:17:16 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 20:17:02 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	check_string(char *str)
{
	long long	num;

	if (!(*str))
		return (ERROR);
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str))
		return (ERROR);
	num = ft_atoll(str);
	if (num < INT_MIN || num > INT_MAX)
		return (ERROR);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (ERROR);
		str++;
	}
	return (SUCCESS);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (ft_err());
		if (check_string(argv[1]) == 0)
			return (STRING_CASE);
	}
	return (LIST_CASE);
}
