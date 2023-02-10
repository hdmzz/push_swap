/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:31 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/10 16:48:38 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_double(t_node *lst)
{
	int		to_check;
	t_node	*last;
	
	to_check = lst->nb;
	last = lst->prev;
	lst = lst->next;
	while(lst != last)
	{
		if (to_check == lst->nb)
			return (1);
		lst = lst->next;
	}
	if (to_check == lst->nb)
		return (1);
	return (0);
}

void	is_duplicate(t_node *lst)
{
	t_node	*last;

	last = lst->prev;
	while (lst != last)
	{
		if (ft_find_double(lst))
			error_handler();
		lst = lst->next;
	}
}

void	only_digit(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		if (!ft_isdigitstr(tab[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

void	check_args(int ac, char **av)
{
	char	**tab;

	tab = ft_split(av[1], ' ');
}

void	arg_parser(int	ac, char **av, t_node *lst_a)
{
	int		i;
	char	**tab;
	char	*nbr;

	i = 1;
	while (i < ac)
	{
		tab = ft_split(av[1], ' ');
		while (*tab)
		{
			
		}
		
	}
	
}
