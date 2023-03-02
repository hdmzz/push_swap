/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_under_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:12:24 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/02 15:35:35 by hdamitzi         ###   ########.fr       */
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
	if (case_lst == 0)
		return ;
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

static void	sort_lst_4(t_node **lst_a, t_node **lst_b)
{
	int		sens;
	t_node	*min;

	min = find_min(lst_a);
	sens = choose_sens(*lst_a, min);
	if (sens == 1)
	{
		while ((*lst_a)->index != 0)
			rotate_a(lst_a, 1);
	}
	if (sens == 2)
	{
		while ((*lst_a)->index != 0)
			reverse_rotate_a(lst_a, 1);
	}
	if (is_sorted(*lst_a, list_len(*lst_a)))
		return ;
	push_b(lst_a, lst_b);
	sort_lst_3(lst_a);
	push_a(lst_b, lst_a);
}

static void	sort_lst_5(t_node **lst_a, t_node **lst_b)
{
	int		sens;
	int		index;
	t_node	*min;

	index = 0;
	min = NULL;
	while (index++ < 2)
	{
		min = find_min(lst_a);
		sens = choose_sens(*lst_a, min);
		if (sens == 3 || sens == 1)
			while ((*lst_a)->index != min->index)
				rotate_a(lst_a, 1);
		if (sens == 2)
			while ((*lst_a)->index != min->index)
				reverse_rotate_a(lst_a, 1);
		push_b(lst_a, lst_b);
	}
	sort_lst_3(lst_a);
	push_a(lst_b, lst_a);
	push_a(lst_b, lst_a);
}

void	sort_lst_under_5(t_node **lst_a, t_node **lst_b)
{
	int	len;

	len = list_len(*lst_a);
	if (len == 2)
		sort_lst_2(lst_a);
	if (len == 3)
		sort_lst_3(lst_a);
	if (len == 4)
		sort_lst_4(lst_a, lst_b);
	if (len == 5)
		sort_lst_5(lst_a, lst_b);
}
