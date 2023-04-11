/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:23:07 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/11 15:13:18 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*n_max(t_node *lst, int args_number)
{
	int		max;
	int		i;
	t_node	max_n;
	t_node	*max_node;

	max = lst->nb;
	max_node = &max_n;
	i = 0;
	while (i++ < args_number)
	{
		if (lst->nb > max)
		{
			max = lst->nb;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_node	*n_min(t_node *lst, int args_number, int index)
{
	int		min;
	int		i;
	t_node	*min_node;
	t_node	*max_node;

	while (lst->index != -1)
		lst = lst->next;
	min_node = lst;
	max_node = n_max(lst, args_number);
	if (min_node == max_node && index == args_number)
		return (max_node);
	min = lst->nb;
	i = 0;
	while (i++ < args_number)
	{
		if (lst->index == -1 && lst->nb < min)
		{
			min = lst->nb;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}

void	index_lst(t_node *lst, int args_number, int index)
{
	t_node	*min_node;

	while (index < args_number)
	{
		min_node = n_min(lst, args_number, index);
		min_node->index = index;
		index++;
	}
}

int	is_sorted(t_node *lst, int args_number)
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	if (args_number == 1)
		return (is_sorted);
	while (i < args_number - 1)
	{
		if (lst->nb > lst->next->nb)
			is_sorted = 0;
		lst = lst->next;
		i++;
	}
	lst = lst->next;
	return (is_sorted);
}
