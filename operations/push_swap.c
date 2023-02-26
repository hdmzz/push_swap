/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:33:25 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/26 21:40:56 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_node **from, t_node **to)
{
	t_node	*save;
	t_node	*stock;

	if (!(*from))
		return ;
	save = (*from);
	delete_t_node(from);
	if ((*to)->next && (*to)->prev)
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
	ft_printf("pa\n");
}

void	push_b(t_node **from, t_node **to)
{
	t_node	*save;
	t_node	*stock;

	if (!(*from))
		return ;
	save = (*from);
	delete_t_node(from);
	if ((!(*to)) || (!(*to)->next && !(*to)->prev))
	{
		(*to) = save;
		(*to)->next = (*to);
		(*to)->prev = (*to);
	}
	else
	{
		stock = (*to)->prev;
		(*to)->prev = save;
		(*to)->prev->next = (*to);
		(*to)->prev->prev = stock;
		(*to)->prev->prev->next = save;
		(*to) = (*to)->prev;
	}
	ft_printf("pb\n");
}

void	swap_a(t_node **first, int print)
{
	t_node	*temp;
	t_node	*second;
	t_node	*last;

	temp = (*first);
	second = temp->next;
	last = temp->prev;
	(*first) = second;
	(*first)->prev = temp;
	temp->next = second->next;
	second->next = temp;
	second->prev = last;
	last->next = second;
	temp->next->prev = temp;
	temp->prev = second;
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_node **first, int print)
{
	t_node	*temp;
	t_node	*second;
	t_node	*last;

	temp = (*first);
	second = temp->next;
	last = temp->prev;
	(*first) = second;
	(*first)->prev = temp;
	temp->next = second->next;
	second->next = temp;
	second->prev = last;
	last->next = second;
	temp->next->prev = temp;
	temp->prev = second;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_node *first_a, t_node *first_b)
{
	swap_a(&first_a, 0);
	swap_b(&first_b, 0);
	ft_printf("ss\n");
}
