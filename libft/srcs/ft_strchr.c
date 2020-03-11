/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:13:47 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:23:09 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	int		i;

	s2 = (char*)s;
	i = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			return (s2 + i);
		i++;
	}
	if (c == '\0')
		return (s2 + i);
	return (NULL);
}
