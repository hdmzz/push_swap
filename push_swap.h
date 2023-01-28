/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:12:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/26 23:12:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct node
{
	int			nb;
	struct node	*next;
	struct node	*prev;
}				node;
