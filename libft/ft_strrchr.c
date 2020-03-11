/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:14:43 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:23:45 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		i;
	int		isfound;
	int		lstocc;

	s2 = (char*)s;
	i = 0;
	isfound = 0;
	lstocc = 0;
	while (s2[i])
	{
		if (s2[i] == c)
		{
			isfound = 1;
			lstocc = i;
		}
		i++;
	}
	if (isfound == 1)
		return (s2 + lstocc);
	if (c == '\0')
		return (s2 + i);
	return (NULL);
}
