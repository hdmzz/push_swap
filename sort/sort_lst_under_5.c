/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_under_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:12:24 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/13 12:50:03 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_lst_2(t_node *lst_a)
{
	if (lst_a->index > lst_a->next->index)
		return ;
}

void	sort_lst_under_5(t_node *lst_a)
{
	if (list_len(lst_a) == 2)
		sort_lst_2(lst_a);
}
