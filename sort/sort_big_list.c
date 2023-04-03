/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:24:09 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/02 15:49:36 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	max_bits(t_node *lst)
{
	int		max_bits;
	t_node	*max;

	max_bits = 0;
	max = n_max(lst, list_len(lst));
	while ((max->index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_big_list(t_node **lst_a, t_node **lst_b)
{
	int	max_b;
	int	i;
	int	j;
	int	len;

	i = 0;
	max_b = max_bits(*lst_a);
	while (max_b--)
	{
		j = 0;
		len = list_len(*lst_a);
		while (j++ < len)
		{
			if (((*lst_a)->index >> i & 1) == 1)
				rotate_a(lst_a, 1);
			else
				push_b(lst_a, lst_b);
			if (is_sorted(*lst_a, list_len(*lst_a)))
				break ;
		}
		while (*lst_b)
			push_a(lst_b, lst_a);
		i++;
	}
}
