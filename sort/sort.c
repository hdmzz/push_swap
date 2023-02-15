/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:39:13 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/15 13:51:20 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_lst(t_node **lst_a)
{
	if (list_len(*lst_a) <= 5)
		sort_lst_under_5(lst_a);
	//sort_big_lst(lst_a);
}
