/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:31 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/10 13:39:50 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_double(t_node *lst)
{
	int		to_check;
	t_node	*last;
	
	to_check = lst->nb;
	last = lst->prev;
	lst = lst->next;
	while(lst != last)
	{
		if (to_check == lst->nb)
			return (1);
		lst = lst->next;
	}
	if (to_check == lst->nb)
		return (1);
	return (0);
}

void	is_duplicate(t_node *lst)
{
	t_node	*last;

	last = lst->prev;
	while (lst != last)
	{
		if (ft_find_double(lst))
			error_handler();
		lst = lst->next;
	}
}
