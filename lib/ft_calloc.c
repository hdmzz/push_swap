/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:51 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/11 14:58:08 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buff;
	size_t	i;

	i = count * size;
	if (i && i / size != count)
		return (NULL);
	buff = malloc(size * count);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size * count);
	return (buff);
}
