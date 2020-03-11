/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:43:59 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:24:46 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_strstr_2(const char *hs, const char *ndl, int i)
{
	unsigned int	j;

	j = 0;
	while (hs[i] == ndl[j])
	{
		i++;
		j++;
		if (ndl[j] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strstr(const char *hs, const char *ndl)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	if (ndl[0] == '\0')
		return ((char*)hs);
	while (hs[i])
	{
		if (hs[i] == ndl[0])
		{
			start = i;
			if (ft_strstr_2(hs, ndl, i) == 1)
				return ((char*)&hs[start]);
		}
		i++;
	}
	return (NULL);
}
