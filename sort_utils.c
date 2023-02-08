/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:23:07 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/08 08:30:25 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *lst, int args_number)
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < args_number)
	{
		if (lst->nb > lst->next->nb)
			is_sorted = 0;
		lst = lst->next;
		i++;
	}
	lst = lst->next;
	return (is_sorted);
}
