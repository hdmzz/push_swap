/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:12:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/11 10:24:06 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/lib.h"

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}				t_node;

t_node	*n_min(t_node *lst, int args_number, int index);
t_node	*n_max(t_node *lst, int args_number);

void	insert_back(t_node **start, int nb);
t_node	*init_new(int nb);
void	printt_node(t_node *start);
void	delete_t_node(t_node **from);

void	push_a(t_node **from, t_node **to);
void	push_b(t_node **from, t_node **to);

void	reverse_rotate_a(t_node	**first, int print);
void	reverse_rotate_b(t_node	**first, int print);
void	rrr(t_node **lst_a, t_node **lst_b);

void	rotate_a(t_node **first, int print);
void	rotate_b(t_node **first, int print);
void	rr(t_node **lst_a, t_node **lst_b);

void	swap_a(t_node **first, int print);
void	swap_b(t_node **first, int print);
void	ss(t_node *first_a, t_node *first_b);

int		list_len(t_node *lst);
int		is_sorted(t_node *lst, int args_number);

void	index_lst(t_node *lst, int nbr_of_args, int index);
void	error_handler(void);
void	is_duplicate(t_node *lst);
t_node	*arg_parser(int ac, char **av);
void	arg_validator(int ac, char **av);

void	sort_lst(t_node **lst_a, t_node **lst_b);
void	sort_lst_under_5(t_node **lst_a, t_node **lst_b);
void	sort_big_list(t_node **lst_a, t_node **lst_b);

int		case_of_3_lst(t_node *lst_a);
int		choose_sens(t_node *lst_a, t_node *min);
t_node	*find_min(t_node **lst);

void	ft_free(char **tab);
void	ft_free_node(t_node **lst);

#endif
