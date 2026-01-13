/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:05:26 by chrilomb          #+#    #+#             */
/*   Updated: 2026/01/13 17:12:51 by chrilomb         ###   ########.fr       */
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

# define ERROR 1
# define ERR_MSG "Error\n"
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define STRING_CASE 0
# define LIST_CASE 1

typedef struct s_lis
{
	int				value;
	int				index;
	struct s_lis	*next;
	struct s_lis	*prev;
}	t_lis;

// lst utils
void	free_list(t_lis *head);
void	print_list(t_lis *list);
int		list_size(t_lis *list);

// parsing
t_lis	*handle_string_case(char *str);
t_lis	*handle_list_case(int argc, char **argv);

// sort
void	sort_small_list(t_lis **list);

// moves
void	ft_sa(t_lis **stack_a);
void	ft_sb(t_lis **stack_b);
void	ft_ss(t_lis **stack_a, t_lis **stack_b);
void	ft_pa(t_lis **stack_a, t_lis **stack_b);
void	ft_pb(t_lis **stack_a, t_lis **stack_b);
void	ft_ra(t_lis **stack_a);
void	ft_rb(t_lis **stack_b);
void	ft_rr(t_lis **stack_a, t_lis **stack_b);
void	ft_rra(t_lis **stack_a);
void	ft_rrb(t_lis **stack_b);
void	ft_rrr(t_lis **stack_a, t_lis **stack_b);

// utils
void	idx_list_values(t_lis *list);

int		has_duplicates(int *nums, int count);
int		ft_err(void);
int		check_args(int argc, char **argv);
int		check_string(char *str);
void	ft_free_split(char **split);
void	*ft_error_null(void);
t_lis	*handle_string_case(char *str);
t_lis	*create_list_from_array(int *nums, int count);
t_lis	*handle_list_case(int argc, char **argv);

#endif
