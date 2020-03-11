/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:49:45 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:18:36 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	size_t	i;

	if (!(dst = malloc(count * size)))
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
