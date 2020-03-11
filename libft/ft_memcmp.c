/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:39:21 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:19:37 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1b;
	unsigned char	*s2b;
	int				i;

	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	if (n == 0)
		return (0);
	n--;
	i = 0;
	while (s1b[i] == s2b[i] && n)
	{
		i++;
		n--;
	}
	return ((int)s1b[i] - (int)s2b[i]);
}
