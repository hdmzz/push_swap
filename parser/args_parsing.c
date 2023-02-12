/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:31 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/02/12 20:23:02 by hdamitzi         ###   ########.fr       */
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
			error_handler();
		i++;
	}
}

void	arg_validator(int ac, char **av)
{
	int			i;
	char		**tab;
	long long	each_nbr;

	i = 1;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		only_digit(tab);
		while (*tab)
		{
			each_nbr = ft_atoll(*tab);
			if (each_nbr > 2147483647 || each_nbr < -2147483648)
				error_handler();
			free(*tab);
			tab++;
		}
		i++;
	}
}

t_node	*arg_parser(int	ac, char **av)
{
	int		i;
	char	**tab;
	t_node	*lst_a;

	lst_a = malloc(sizeof(t_node));
	if (!lst_a)
		return (NULL);
	lst_a->next = NULL;
	lst_a->prev = NULL;
	i = 1;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		while (*tab)
		{
			insert_back(&lst_a, ft_atoi(*tab));
			tab++;
		}
		i++;
	}
	return (lst_a);
}
