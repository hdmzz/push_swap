/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:16:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/26 14:20:51 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*init_new(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = new;
	new->prev = new;
	new->index = -1;
	return (new);
}

void	delete_t_node(t_node **from)
{
	if ((*from) == (*from)->next)
		(*from) = NULL;
	else if ((*from)->next && (*from)->prev)
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		(*from) = (*from)->next;
	}
}
