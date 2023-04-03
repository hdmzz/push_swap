/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:38:45 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/17 10:43:24 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printt_node(t_node *start)
{
	t_node	*current;

	current = start;
	while (current->next != start)
	{
		ft_printf("%d %d\n", current->nb, current->index);
		current = current->next;
	}
	ft_printf("%d %d\n", current->nb, current->index);
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
		i++;
	}
	if (lst)
		i++;
	return (i);
}
