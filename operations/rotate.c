/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:23:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/14 11:36:18 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_node **first, int print)
{
	(*first) = (*first)->next;
	if (print)
		ft_printf("ra\n");
}

void	rotate_b(t_node **first, int print)
{
	(*first) = (*first)->next;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **lst_a, t_node **lst_b)
{
	rotate_a(lst_a, 0);
	rotate_b(lst_b, 0);
	ft_printf("rr\n");
}
