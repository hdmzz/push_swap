/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:17:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/15 14:08:59 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	insert_back(t_node **start, int nb)
{
	t_node	*last;
	t_node	*new;

	if (!(*start)->next && !(*start)->prev)
	{
		new = init_new(nb);
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

t_node	*init_list(int ac, char **av)
{
	int		i; 
	t_node	*lst_a;

	i = 1;
	lst_a = malloc(sizeof(t_node));
	if (!lst_a)
		return (NULL);
	lst_a->next = NULL;
	lst_a->prev = NULL;
	while (i < ac)
	{
		insert_back(&lst_a, ft_atoi(av[i]));
		i++;
	}
	index_lst(lst_a, ac - 1, 0);
	return (lst_a);
}

int	main(int ac, char **av)
{
	t_node	*lst_a;

	if (ac < 2)
		exit(EXIT_FAILURE);
	arg_validator(ac, av);
	lst_a = arg_parser(ac, av);
	is_duplicate(lst_a);
	index_lst(lst_a, list_len(lst_a), 0);
	printt_node(lst_a);
	ft_printf("\n");
	sort_lst(&lst_a);
	printt_node(lst_a);
	ft_printf("\n");
}
