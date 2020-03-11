/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:59:57 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:24:32 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_strnstr_2(const char *hs, const char *ndl, size_t i, size_t len)
{
	unsigned int j;

	j = 0;
	while (hs[i] == ndl[j] && i < len)
	{
		i++;
		j++;
		if (ndl[j] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (ndl[0] == '\0')
		return ((char*)hs);
	while (hs[i] && i < len)
	{
		if (hs[i] == ndl[0])
		{
			start = i;
			if (ft_strnstr_2(hs, ndl, i, len) == 1)
				return ((char*)&hs[start]);
		}
		i++;
	}
	return (NULL);
}
