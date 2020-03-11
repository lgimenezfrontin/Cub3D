/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:43:41 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:21:50 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;
	int			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = (char*)dst;
	src2 = (const char*)src;
	i = 0;
	while (n)
	{
		dst2[i] = src2[i];
		i++;
		n--;
	}
	return (dst);
}
