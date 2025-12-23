/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrilomb <chrilomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:05:26 by chrilomb          #+#    #+#             */
/*   Updated: 2025/12/18 21:35:50 by chrilomb         ###   ########.fr       */
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

int		has_duplicates(int *nums, int count);
int		ft_err(void);
int		check_args(int argc, char **argv);
int		check_string(char *str);
void	ft_free_split(char **split);
void	free_list(t_lis *head);
void	*ft_error_null(void);
t_lis	*handle_string_case(char *str);
t_lis	*create_list_from_array(int *nums, int count);
t_lis	*handle_list_case(int argc, char **argv);

#endif
