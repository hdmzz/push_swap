/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:12:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/28 15:24:48 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct node
{
	int			nb;
	struct node	*next;
	struct node	*prev;
}				node;

void	push(node *to, node *from);
void	insert_begin(node **start, int nb);
void	insert_back(node **start, int nb);
node	*init_new(int nb);
void	printnode(node **start);
void	reverse_rotate(node	**first, char pile);
void	reverse(node **first, char pile);
void	delete_node(node *from);
void	swap(node **first, char pile);

# endif
