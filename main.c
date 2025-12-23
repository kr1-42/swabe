/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:06:01 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/23 13:28:22 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_swap.h"

static void	print_list(t_lis *list)
{
	t_lis	*current;

	current = list;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_lis	*list;
	if (check_args(argc, argv) == STRING_CASE)
		list = handle_string_case(argv[1]);
	else
		list = handle_list_case(argc, argv);
	print_list(list);
	free_list(list);
	return (0);
}
