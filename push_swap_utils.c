/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:16:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/29 23:18:01 by hdamitzi         ###   ########.fr       */
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

void	insert_back(t_node **start, int nb)
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
	new = init_new(nb);
	new->prev = last;
	last->next = new;
	new->next = (*start);
	(*start)->prev = new;
}

void	printt_node(t_node *start)
{
	t_node	*last;
	t_node	*current;

	last = start->prev;
	current = start;
	while (current->next != start)
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
	ft_printf("%d\n", current->nb);
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

void	push(t_node **from, t_node **to)
{
	t_node	*save;
	t_node	*stock;

	if (!(*from))
		return ;
	save = (*from);
	delete_t_node(from);
	if (*to)
	{
		stock = (*to)->prev;
		(*to)->prev = save;
		(*to)->prev->next = (*to);
		(*to)->prev->prev = stock;
		(*to)->prev->prev->next = save;
		(*to) = (*to)->prev;
	}
	else
	{
		(*to) = save;
		(*to)->next = (*to);
		(*to)->prev = (*to);
	}
}

void	swap(t_node **first, char pile)
{
	t_node	*temp;
	t_node	*second;
	t_node	*last;

	(void)pile;
	temp = (*first);
	second = temp->next;
	last = temp->prev;
	(*first) = second;
	(*first)->prev = temp;
	temp->next = second->next;
	second->next = temp;
	second->prev = last;
	last->next = second;
}
