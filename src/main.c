/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:06:01 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 17:24:20 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

int	main(int argc, char **argv)
{
	t_lis	*list;

	if (check_args(argc, argv) == STRING_CASE)
		list = handle_string_case(argv[1]);
	else
		list = handle_list_case(argc, argv);
	idx_list_values(list);
	if (list_size(list) <= 5)
		sort_small_list(&list);
	// else
	// 	sort_large_list(&list);
	print_list(list);
	free_list(list);
	return (0);
}
