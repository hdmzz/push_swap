/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:40:40 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/07 13:24:15 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	list_len(t_node *lst)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = lst;
	while (lst->next != temp)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}
