/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:20:41 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/14 12:03:25 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_node	**first, int print)
{
	(*first) = (*first)->prev;
	if (print)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_node	**first, int print)
{
	(*first) = (*first)->prev;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **lst_a, t_node **lst_b)
{
	reverse_rotate_a(lst_a, 0);
	reverse_rotate_b(lst_b, 0);
	ft_printf("rrr");
}
