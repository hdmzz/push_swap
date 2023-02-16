/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_under_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:12:24 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/16 21:29:53 by hdamitzi         ###   ########.fr       */
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
	int	case_lst;

	case_lst = case_of_3_lst(*lst_a);
	if (case_lst == 1)
		reverse_rotate_a(lst_a, 1);
	if (case_lst == 2)
		swap_a(lst_a, 1);
	if (case_lst == 3)
		rotate_a(lst_a, 1);
	if (case_lst == 4)
	{
		swap_a(lst_a, 1);
		reverse_rotate_a(lst_a, 1);
	}
	if (case_lst == 5)
	{
		rotate_a(lst_a, 1);
		swap_a(lst_a, 1);
		reverse_rotate_a(lst_a, 1);
	}
}

void	sort_lst_under_5(t_node **lst_a)
{
	if (list_len(*lst_a) == 2)
		sort_lst_2(lst_a);
	if (list_len(*lst_a) == 3)
		sort_lst_3(lst_a);
}
