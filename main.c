/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:17:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/13 15:31:06 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
{void	push_a(t_node **from, t_node **to);
void	push_b(t_node **from, t_node **to);

void	reverse_rotate_a(t_node	**first, int print);
void	reverse_rotate_b(t_node	**first, int print);
void	rrr(t_node **lst_a, t_node **lst_b);

void	rotate_a(t_node **first, int print);
void	rotate_b(t_node **first, int print);
void	rr(t_node **lst_a, t_node **lst_b);

void	swap_a(t_node **first, int print);
void	swap_b(t_node **first, int print);
void	ss(t_node *first_a, t_node *first_b);
	t_node	*lst_a;
	t_node	*lst_b;

	lst_b = NULL;

	if (ac < 2)
		exit(EXIT_FAILURE);
	arg_validator(ac, av);
	lst_a = arg_parser(ac, av);
	is_duplicate(lst_a);
	index_lst(lst_a, list_len(lst_a), 0);
	printt_node(lst_a);
	push_b(&lst_a, &lst_b);
	ft_printf("\n");
	printt_node(lst_a);
}
