/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_under_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:12:24 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/16 13:46:08 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_lst_2(t_node **lst_a)
{
	if ((*lst_a)->index > (*lst_a)->next->index)
		rotate_a(lst_a, 1);
}

static void	sort_lst_3(t_node **lst_a)
{
	int	case;

	case = 
}

void	sort_lst_under_5(t_node **lst_a)
{
	if (list_len(*lst_a) == 2)
		sort_lst_2(lst_a);
}
