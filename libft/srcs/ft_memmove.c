/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:40:51 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:21:57 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_memmove_2(char *dst2, const char *src2, size_t len)
{
	while (len)
	{
		dst2[len - 1] = src2[len - 1];
		len--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	int			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = (char*)dst;
	src2 = (const char*)src;
	if (dst <= src)
	{
		i = 0;
		while (len)
		{
			dst2[i] = src2[i];
			i++;
			len--;
		}
	}
	else
		ft_memmove_2(dst2, src2, len);
	return (dst);
}
