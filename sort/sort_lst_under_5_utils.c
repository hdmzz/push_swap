/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_under_5_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:45 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/20 20:58:31 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	case_of_3_lst(t_node *lst_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = lst_a;
	second = lst_a->next;
	last = lst_a->prev;
	if (second->index > first->index && first->index > last->index)
		return (1);
	if (first->index > second->index && last->index > first->index)
		return (2);
	if (first->index > second->index && last->index > second->index)
		return (3);
	if (first->index > second->index && last->index < second->index)
		return (4);
	if (first->index < second->index && last->index < second->index)
		return (5);
	return (0);
}

int	choose_sens(t_node *lst_a, t_node *min)
{
	int		i;
	int		j;
	t_node	*start;

	i = 0;
	j = 0;
	start = lst_a;
	while (lst_a->index != min->index && i++ < list_len(lst_a))
		lst_a = lst_a->next;
	lst_a = start;
	while (lst_a->index != min->index && j++ < list_len(lst_a))
		lst_a = lst_a->prev;
	if (i == j || i < j)
		return (1);
	if (i > j)
		return (2);
	return (0);
}

t_node	*find_min(t_node **lst)
{
	int		min;
	int		len;
	t_node	*min_node;

	min = (*lst)->index;
	len = list_len(*lst);
	min_node = *lst;
	while (len--)
	{
		if ((*lst)->index < min)
		{
			min = (*lst)->index;
			min_node = *lst;
		}
		*lst = (*lst)->next;
	}
	return (min_node);
}
