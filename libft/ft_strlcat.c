/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:14:03 by lgimenez          #+#    #+#             */
/*   Updated: 2019/10/23 18:59:59 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;
	int		dstsize2;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	dstsize2 = (int)dstsize;
	while (dst[i])
		i++;
	dstsize2--;
	while (dstsize2 > (int)dstlen && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
		dstsize2--;
	}
	dst[i] = '\0';
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}
