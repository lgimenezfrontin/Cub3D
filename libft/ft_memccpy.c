/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:59:20 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:18:56 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	int				i;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	i = 0;
	while (n)
	{
		dst2[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
