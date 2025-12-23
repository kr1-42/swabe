/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:31:28 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 20:08:23 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap.h"

static char	**split_and_validate(char *str)
{
	char	**tokens;
	int		i;

	tokens = ft_split(str, ' ');
	if (!tokens)
		return (ft_error_null());
	i = 0;
	while (tokens[i])
	{
		if (check_string(tokens[i]) == ERROR)
		{
			ft_free_split(tokens);
			return (NULL);
		}
		i++;
	}
	return (tokens);
}

static int	*parse_string_to_int_array(char *str, int *count)
{
	int		*nums;
	char	**tokens;
	int		i;

	tokens = split_and_validate(str);
	if (!tokens)
		return (ft_error_null());
	*count = 0;
	while (tokens[*count])
		(*count)++;
	nums = (int *)malloc(sizeof(int) * (*count));
	if (!nums)
		return (ft_free_split(tokens), ft_error_null());
	i = -1;
	while (++i < *count)
		nums[i] = ft_atoi(tokens[i]);
	ft_free_split(tokens);
	return (nums);
}

t_lis	*create_list_from_array(int *nums, int count)
{
	t_lis	*head;
	t_lis	*new_node;
	t_lis	*prev_node;
	int		i;

	head = NULL;
	prev_node = NULL;
	i = 0;
	while (i < count)
	{
		new_node = (t_lis *)malloc(sizeof(t_lis));
		if (!new_node)
			return (free_list(head), NULL);
		new_node->value = nums[i];
		new_node->index = i;
		new_node->next = NULL;
		new_node->prev = prev_node;
		if (prev_node)
			prev_node->next = new_node;
		else
			head = new_node;
		prev_node = new_node;
		i++;
	}
	return (head);
}

t_lis	*handle_string_case(char *str)
{
	t_lis	*list;
	int		*nums;
	int		count;

	nums = parse_string_to_int_array(str, &count);
	if (!nums)
		return (NULL);
	if (has_duplicates(nums, count))
		return (free(nums), ft_error_null());
	list = create_list_from_array(nums, count);
	free(nums);
	return (list);
}
