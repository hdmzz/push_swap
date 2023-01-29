/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:12:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/29 23:46:20 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
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

int	list_len(t_node *lst);

#endif
