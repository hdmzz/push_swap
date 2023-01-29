/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:17:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/29 23:33:29 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_node	*lst;
	t_node	*lstb;
	int		i;

	lst = malloc(sizeof(t_node));
	lstb = malloc(sizeof(t_node));
	if (!lst)
		exit(EXIT_FAILURE);
	lst->next = NULL;
	lst->prev = NULL;
	lstb->next = NULL;
	lstb->prev = NULL;
	i = 0;
	while (i < 4)
	{
		insert_begin(&lst, i);
		i++;
	}
	while (i < 8)
	{
		insert_begin(&lstb, i);
		i++;
	}
	printt_node(lst);
	printf("\n");
	printt_node(lstb);
	ft_printf("\n");
	push(&lst, &lstb);
	printt_node(lstb);
	ft_printf("\n");
	printt_node(lst);
}
