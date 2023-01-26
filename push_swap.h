/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:12:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/26 10:18:56 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_list
{
	int			nb;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;
