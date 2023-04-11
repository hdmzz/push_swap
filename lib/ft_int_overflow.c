/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:11:24 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/11 14:19:20 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_int_overflow(char *nbr)
{
	int		first;
	char	*second;
	int		res;

	while (ft_strlen(nbr) > 1 && *nbr == '0')
		nbr++;
	first = ft_atoi(nbr);
	second = ft_itoa(first);
	res = ft_strcmp(nbr, second);
	free(second);
	return (res);
}
