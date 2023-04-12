/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:31 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/12 13:40:35 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_double(t_node *lst)
{
	int		to_check;
	t_node	*last;

	to_check = lst->nb;
	last = lst->prev;
	lst = lst->next;
	while (lst != last)
	{
		if (to_check == lst->nb)
			return (1);
		lst = lst->next;
	}
	if (to_check && to_check == lst->nb)
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
		{
			ft_free_node(&lst);
			error_handler();
		}
		lst = lst->next;
	}
}

void	only_digit(char **tab)
{
	int		i;
	char	**temp;

	i = 0;
	temp = tab;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) == 1 && (tab[i][0] == '-' || tab[i][0] == '+'))
		{
			ft_free(tab);
			error_handler();
		}
		if (!ft_isdigitstr(tab[i]))
		{
			while (*tab)
			{
				free(*tab);
				tab++;
			}
			free(temp);
			error_handler();
		}
		i++;
	}
}

void	arg_validator(int ac, char **av)
{
	int			i;
	int			j;
	char		**tab;

	i = 1;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		only_digit(tab);
		j = 0;
		while (tab[j])
		{
			if (ft_int_overflow(tab[j]) != 0)
			{
				ft_free(tab);
				error_handler();
			}
			j++;
		}
		ft_free(tab);
		i++;
	}
}

t_node	*arg_parser(int ac, char **av)
{
	int		i;
	char	**tab;
	char	**temp;
	t_node	*lst_a;

	lst_a = NULL;
	i = 0;
	if (!av[1][0])
		exit(EXIT_SUCCESS);
	while (i++ < ac - 1)
	{
		tab = ft_split(av[i], ' ');
		temp = tab;
		while (*tab)
		{
			insert_back(&lst_a, ft_atoi(*tab));
			free(*tab);
			tab++;
		}
		free(temp);
	}
	if (!lst_a || (!lst_a->next && !lst_a->prev))
		error_handler();
	return (lst_a);
}
