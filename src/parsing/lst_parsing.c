/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:49:22 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 21:42:42 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

static int	args_need_split(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	count_all_tokens(int argc, char **argv)
{
	int	i;
	int	j;
	int	total;

	total = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (!argv[i][j])
				break ;
			total++;
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
		}
		i++;
	}
	return (total);
}

static int	fill_nums_direct(int *nums, int argc, char **argv)
{
	int	arg_i;
	int	num_i;

	arg_i = 1;
	num_i = 0;
	while (arg_i < argc)
	{
		if (check_string(argv[arg_i]) == ERROR)
			return (-1);
		nums[num_i++] = ft_atoi(argv[arg_i]);
		arg_i++;
	}
	return (num_i);
}

static int	fill_nums_split(int *nums, int argc, char **argv)
{
	int		arg_i;
	int		num_i;
	int		j;
	char	**mtx;

	arg_i = 1;
	num_i = 0;
	while (arg_i < argc)
	{
		mtx = ft_split(argv[arg_i], ' ');
		if (!mtx)
			return (-1);
		j = 0;
		while (mtx[j])
		{
			if (check_string(mtx[j]) == ERROR)
				return (ft_free_split(mtx), -1);
			nums[num_i++] = ft_atoi(mtx[j++]);
		}
		ft_free_split(mtx);
		arg_i++;
	}
	return (num_i);
}

t_lis	*handle_list_case(int argc, char **argv)
{
	int		*nums;
	int		num_i;
	int		need_split;
	int		total;
	t_lis	*list;

	need_split = args_need_split(argc, argv);
	total = argc - 1;
	if (need_split == TRUE)
		total = count_all_tokens(argc, argv);
	if (total <= 0)
		return (ft_error_null());
	nums = (int *)malloc(sizeof(int) * total);
	if (!nums)
		return (ft_error_null());
	if (need_split == TRUE)
		num_i = fill_nums_split(nums, argc, argv);
	else
		num_i = fill_nums_direct(nums, argc, argv);
	if (num_i < 0 || has_duplicates(nums, num_i) == ERROR)
		return (free(nums), ft_error_null());
	list = create_list_from_array(nums, num_i);
	free(nums);
	return (list);
}
