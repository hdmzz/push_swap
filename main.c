/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:17:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/29 16:25:34 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	ft_free_node(t_node **lst)
{
	t_node	*temp;
	t_node	*last;

	temp = NULL;
	last = NULL;
	last = (*lst)->prev;
	temp = *lst;
	while (temp != last)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	free(last);
}

void	insert_back(t_node **start, int nb)
{
	t_node	*last;
	t_node	*new;

	if (!(*start))
	{
		new = init_new(nb);
		free(*start);
		(*start) = new;
		return ;
	}
	last = (*start)->prev;
	new = init_new(nb);
	last->next = new;
	new->prev = last;
	new->next = (*start);
	(*start)->prev = new;
}

int	main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	arg_validator(ac, av);
	lst_a = arg_parser(ac, av);
	lst_b->next = NULL;
	lst_b->prev = NULL;
	is_duplicate(lst_a);
	index_lst(lst_a, list_len(lst_a), 0);
	sort_lst(&lst_a, &lst_b);
	ft_free_node(&lst_a);
	exit(EXIT_SUCCESS);
}
