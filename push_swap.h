/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:12:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/10 12:28:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}				t_node;

void	push(t_node **from, t_node **to);
void	insert_begin(t_node **start, int nb);
void	insert_back(t_node **start, int nb);
t_node	*init_new(int nb);
void	printt_node(t_node *start);
void	reverse_rotate(t_node	**first, char pile);
void	reverse(t_node **first, char pile);
void	delete_t_node(t_node **from);
void	swap(t_node **first, char pile);

int		list_len(t_node *lst);
int		is_sorted(t_node *lst, int args_number);

void	index_lst(t_node *lst, int nbr_of_args, int index);
void	error_handler(void);
void	is_duplicate(t_node *lst);

#endif
