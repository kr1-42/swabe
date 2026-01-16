/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:06:01 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/16 18:20:00 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

static int	ft_small_check(t_lis **stack_a, t_lis **stack_b, int size)
{
	if (size <= 5)
	{
		if (size == 1)
			return (CASE_ONE_ARG);
		if (size == 2)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				ft_sa(stack_a);
		}
		if (size == 3)
			ft_sort_three(stack_a);
		if (size == 4)
			ft_sort_four(stack_a, stack_b);
		if (size == 5)
		{
			ft_sort_five(stack_a, stack_b);
		}
		return (SMALL_SORT);
	}
	return (BIG_SORT);
}

int	main(int argc, char **argv)
{
	t_lis	*list;
	t_lis	*list_b;

	for (
		int i = 1; i < 64; i++
	){
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
	}
	if (check_args(argc, argv) == STRING_CASE)
		list = handle_string_case(argv[1]);
	else
		list = handle_list_case(argc, argv);
	idx_list_values(list);
	if (ft_small_check(&list, &list_b, list_size(list)) == SMALL_SORT)
		return (/*print_list(list)*/ free_list(list), SUCCESS);
	// else
	// 	sort_large_list(&list);
	//print_list(list);
	free_list(list);
	return (SUCCESS);
}
