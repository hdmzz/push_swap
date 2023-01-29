/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:16:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/29 23:41:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_new(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = new;
	new->prev = new;
	return (new);
}

void	insert_begin(t_node **start, int nb)
{
	t_node	*last;
	t_node	*new;

	if (!(*start)->next && !(*start)->prev)
	{
		new = init_new(nb);
		(*start) = new;
		return ;
	}
	last = (*start)->prev;
	new = malloc(sizeof(t_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = (*start);
	new->prev = last;
	(*start)->prev = new;
	last->next = new;
	*start = new;
}

void	reverse_rotate(t_node	**first, char pile)
{
	(void)pile;
	(*first) = (*first)->prev;
}

void	reverse(t_node **first, char pile)
{
	(void)pile;
	(*first) = (*first)->next;
}

void	delete_t_node(t_node **from)
{
	if ((*from) == (*from)->next)
		(*from) = NULL;
	else
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		(*from) = (*from)->next;
	}
}
