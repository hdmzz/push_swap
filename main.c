/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:17:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/26 10:18:25 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_new(int nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = new;
	new->prev = new;
}

void	insert_begin(t_list **start, int nb)
{
	t_list	*last;
	t_list	*new;

	if (!(*start)->next && !(*start)->prev)
	{
		new = init_new(nb);
		(*start) = new;
		return ;
	}
	last = (*start)->prev;
	new = malloc(sizeof(t_list));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = (*start);
	new->prev = last;
	(*start)->prev = new;
	last->next = new;
	*start = new;
}

void	insert_back(t_list **start, int nb)
{
	t_list	*last;
	t_list	*new;

	if (!(*start)->next && !(*start)->prev)
	{
		new = init_new(nb);
		(*start) = new;
		return ;
	}
	last = (*start)->prev;
	new = init_new(nb);

	//maintenant on insere le maillon dans la liste
	//d'abord le next du last devient start
	new->prev = last;

	//maintenant le dernier doit savoir ou est le nouveau dernier
	last->next = new;

	//puis new doit savoir qui est le premier
	new->next = (*start);

	//start->prev pointait sur last il faut qu'il pointe sur new
	(*start)->prev = new;
}

void	print_list(t_list **start)
{
	t_list	*last;
	t_list	*current;

	last = (*start)->prev;
	current = (*start);
	while (current->next != (*start))
	{
		printf("%d\n", current->nb);
		current = current->next;
	}
	printf("%d\n", current->nb);
}
//le dernier devient premier
void	reverse_rotate(t_list	**first, char pile)
{
	(*first) = (*first)->prev;
}

void	reverse(t_list **first, char pile)
{
	(*first) = (*first)->next;
}

void	swap(t_list **first, char pile)
{
	t_list	*temp;
	t_list	*second;
	t_list	*last;

	temp = (*first);//temp est sur le premier maillon
	second = temp->next;//second est le deuxieme
	last = temp->prev;//le dernier de la chaine
	(*first) = second;//first devient second
	(*first)->prev = temp;//temp est first
	temp->next = second->next;
	second->next = temp;
	second->prev = last;
	last->next = second;
}

int main()
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		exit(EXIT_FAILURE);
	lst->next = NULL;
	lst->prev = NULL;

	int		i = 0;
	while (i < 4)
	{
		insert_begin(&lst, i);
		i++;
	}
	print_list(&lst);
	printf("\n");
	reverse(&lst, 'a');
	print_list(&lst);
	printf("\n");
	reverse_rotate(&lst, 'a');
	print_list(&lst);
	printf("\n");
	swap(&lst, 'a');
	print_list(&lst);
	printf("\n");
}
