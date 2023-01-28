/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:17:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/28 15:18:19 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node	*init_new(int nb)
{
	node	*new;

	new = malloc(sizeof(node));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = new;
	new->prev = new;
	return (new);
}

void	insert_begin(node **start, int nb)
{
	node	*last;
	node	*new;

	if (!(*start)->next && !(*start)->prev)
	{
		new = init_new(nb);
		(*start) = new;
		return ;
	}
	last = (*start)->prev;
	new = malloc(sizeof(node));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = (*start);
	new->prev = last;
	(*start)->prev = new;
	last->next = new;
	*start = new;
}

void	insert_back(node **start, int nb)
{
	node	*last;
	node	*new;

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

void	printnode(node **start)
{
	node	*last;
	node	*current;

	last = (*start)->prev;
	current = (*start);
	while (current->next != (*start))
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
	ft_printf("%d\n", current->nb);
}
//le dernier devient premier
void	reverse_rotate(node	**first, char pile)
{
	(void)pile;
	(*first) = (*first)->prev;
}

void	reverse(node **first, char pile)
{
	(void)pile;
	(*first) = (*first)->next;
}

void	delete_node(node *from)//cette fonction ne free pas mais enleve juste un noeud de la liste chainée
{
	if (from == from->next)
		from = NULL;
	else
	{
		from->prev->next = from->next;
		from->next->prev = from->prev;
		from = from->next;
	}
}

void	push(node *to, node *from)//premier element de from doit aller a la place de to
{
	node	*save;
//	node	*stock;
	(void)to;
	if (!from)
		return;
	save = from;//on sauvegarde from puis on peux delete
	delete_node(from);
	/* if (to)
	{
		//inserer le nouveaux noeud dans la chaine pointées par to
		stock = to->prev;//stock prend la valeur du dernier noeud de la list
		to->prev = save;//to->prev a une nouvelle valeur au'il faut remettre dans l'ordre save est le premier de l'autre pile
		to->prev->next = to;
		to->prev->prev = stock;
		to->prev->prev->next = save;
		to = to->prev;
	}
	else
	{
		to = save;
		to->next = to;
		to->prev = to;
	} */
}

void	swap(node **first, char pile)
{
	node	*temp;
	node	*second;
	node	*last;

	(void)pile;
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
	node	*lst;
	node	*lstb;

	lst = malloc(sizeof(node));
	lstb = malloc(sizeof(node));
	if (!lst)
		exit(EXIT_FAILURE);
	lst->next = NULL;
	lst->prev = NULL;
	lstb->next = NULL;
	lstb->prev = NULL;

	int		i = 0;
	while (i < 4)
	{
		insert_begin(&lst, i);
		i++;
	}

	while(i < 8)
	{
		insert_begin(&lstb, i);
		i++;
	}

	printnode(&lst);
	printf("\n");
	printnode(&lstb);
	printf("\n push lstb > lst printf lstbdoit to lstb from lst\n");
	push(lstb, lst);
	printnode(&lst);
}
