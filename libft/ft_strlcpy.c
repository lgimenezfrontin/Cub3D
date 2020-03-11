/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:14:15 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:22:40 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	srclen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (dstsize)
	{
		n = 0;
		while (src[n] && n < dstsize - 1)
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (srclen);
}
