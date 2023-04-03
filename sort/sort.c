/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:39:13 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/02 15:35:15 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_lst(t_node **lst_a, t_node **lst_b)
{
	if (is_sorted(*lst_a, list_len(*lst_a)))
		return ;
	if (list_len(*lst_a) <= 5)
		sort_lst_under_5(lst_a, lst_b);
	else
		sort_big_list(lst_a, lst_b);
}
