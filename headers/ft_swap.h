/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:05:26 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/19 16:04:16 by chrilomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SWAP_H
# define FT_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# include "../my_libft/headers/libft.h"
# include "../my_libft/headers/ft_printf.h"

# define ERR_MSG "Error\n"
# define ERROR 1
# define CASE_ONE_ARG 1
# define SMALL_SORT 1
# define TRUE 1
# define LIST_CASE 1
# define BIG_SORT 0
# define SUCCESS 0
# define FALSE 0
# define STRING_CASE 0

typedef struct s_lis
{
	int				value;
	int				index;
	struct s_lis	*next;
	struct s_lis	*prev;
}	t_lis;

// lst utils
/**
 * @brief Free the entire list.
 * @param head Head of the list to free.
 */
void	free_list(t_lis *head);
/**
 * @brief Print list values (debug helper).
 * @param list Head of the list to print.
 */
void	print_list(t_lis *list);
/**
 * @brief Get the number of nodes in the list.
 * @param list Head of the list.
 * @return Count of nodes.
 */
int		list_size(t_lis *list);

// parsing
/**
 * @brief Parse a single string of numbers into a list.
 * @param str Input string.
 * @return New list or NULL on failure.
 */
t_lis	*handle_string_case(char *str);
/**
 * @brief Parse argv numbers into a list.
 * @param argc Argument count.
 * @param argv Argument values.
 * @return New list or NULL on failure.
 */
t_lis	*handle_list_case(int argc, char **argv);

// small sort
/**
 * @brief Push the smallest value from A to B (size 5 path).
 * @param stack_a Stack A.
 */
void	push_smallest_to_b(t_lis **stack_a);
/**
 * @brief Push the smallest value from A to B (size 4 path).
 * @param stack_a Stack A.
 */
void	push_smallest_to_b_4(t_lis **stack_a);
/**
 * @brief Sort 5 elements using stack B.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_sort_five(t_lis **stack_a, t_lis **stack_b);
/**
 * @brief Sort 4 elements using stack B.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_sort_four(t_lis **stack_a, t_lis **stack_b);
/**
 * @brief Sort 3 elements in stack A.
 * @param stack_a Stack A.
 */
void	ft_sort_three(t_lis **stack_a);

// large sort
/**
 * @brief Sort lists larger than 5 elements.
 * @param stack_a Stack A.
 */
void	sort_large_list(t_lis **stack_a);
// moves
/**
 * @brief Swap the top two of stack A.
 * @param stack_a Stack A.
 */
void	ft_sa(t_lis **stack_a);
/**
 * @brief Swap the top two of stack B.
 * @param stack_b Stack B.
 */
void	ft_sb(t_lis **stack_b);
/**
 * @brief Swap the top two of both stacks.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_ss(t_lis **stack_a, t_lis **stack_b);
/**
 * @brief Push the top of B onto A.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_pa(t_lis **stack_a, t_lis **stack_b);
/**
 * @brief Push the top of A onto B.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_pb(t_lis **stack_a, t_lis **stack_b);
/**
 * @brief Rotate stack A up.
 * @param stack_a Stack A.
 */
void	ft_ra(t_lis **stack_a);
/**
 * @brief Rotate stack B up.
 * @param stack_b Stack B.
 */
void	ft_rb(t_lis **stack_b);
/**
 * @brief Rotate both stacks up.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_rr(t_lis **stack_a, t_lis **stack_b);
/**
 * @brief Reverse rotate stack A.
 * @param stack_a Stack A.
 */
void	ft_rra(t_lis **stack_a);
/**
 * @brief Reverse rotate stack B.
 * @param stack_b Stack B.
 */
void	ft_rrb(t_lis **stack_b);
/**
 * @brief Reverse rotate both stacks.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ft_rrr(t_lis **stack_a, t_lis **stack_b);

// large sort helpers
int		max_value(t_lis *stack);
int		min_value(t_lis *stack);
int		find_index(t_lis *a, int nbr);
int		find_place_a(t_lis *stack_a, int nbr_push);
int		find_place_b(t_lis *stack_b, int nbr_push);

int		case_rrarb_a(t_lis *a, t_lis *b, int c);
int		case_rarrb_a(t_lis *a, t_lis *b, int c);
int		case_rrarrb_a(t_lis *a, t_lis *b, int c);
int		case_rarb_a(t_lis *a, t_lis *b, int c);
int		case_rarrb(t_lis *a, t_lis *b, int c);
int		case_rrarb(t_lis *a, t_lis *b, int c);
int		case_rrarrb(t_lis *a, t_lis *b, int c);
int		case_rarb(t_lis *a, t_lis *b, int c);

int		rotate_type_ba(t_lis *a, t_lis *b);
int		rotate_type_ab(t_lis *a, t_lis *b);

int		apply_rarb(t_lis **a, t_lis **b, int c, char s);
int		apply_rrarrb(t_lis **a, t_lis **b, int c, char s);
int		apply_rrarb(t_lis **a, t_lis **b, int c, char s);
int		apply_rarrb(t_lis **a, t_lis **b, int c, char s);

// utils
/**
 * @brief Assign indices to list values.
 * @param list Head of the list.
 */
void	idx_list_values(t_lis *list);
/**
 * @brief Check if stack is sorted ascending.
 * @param stack Stack A.
 * @return 1 if sorted, 0 otherwise.
 */
int		ft_checksorted(t_lis *stack);
/**
 * @brief Check for duplicates in an array.
 * @param nums Array of integers.
 * @param count Number of elements.
 * @return 1 if duplicates exist, 0 otherwise.
 */
int		has_duplicates(int *nums, int count);
/**
 * @brief Print error message and return ERROR.
 * @return ERROR.
 */
int		ft_err(void);
/**
 * @brief Validate command line arguments.
 * @param argc Argument count.
 * @param argv Argument values.
 * @return 1 if valid, 0 otherwise.
 */
int		check_args(int argc, char **argv);
/**
 * @brief Validate a space-separated number string.
 * @param str Input string.
 * @return 1 if valid, 0 otherwise.
 */
int		check_string(char *str);
/**
 * @brief Free a NULL-terminated split array.
 * @param split Array to free.
 */
void	ft_free_split(char **split);
/**
 * @brief Print error message and return NULL.
 * @return NULL.
 */
void	*ft_error_null(void);
/**
 * @brief Parse a single string of numbers into a list.
 * @param str Input string.
 * @return New list or NULL on failure.
 */
t_lis	*handle_string_case(char *str);
/**
 * @brief Create a list from an integer array.
 * @param nums Array of integers.
 * @param count Number of elements.
 * @return New list or NULL on failure.
 */
t_lis	*create_list_from_array(int *nums, int count);
/**
 * @brief Parse argv numbers into a list.
 * @param argc Argument count.
 * @param argv Argument values.
 * @return New list or NULL on failure.
 */
t_lis	*handle_list_case(int argc, char **argv);

#endif
