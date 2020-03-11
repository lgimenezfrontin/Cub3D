/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:53:06 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:20:20 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	int				i;

	b2 = (unsigned char*)b;
	i = 0;
	while (len)
	{
		b2[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
