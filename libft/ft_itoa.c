/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:53:04 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:16:05 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_itoa_cntchar(long n2, int isneg)
{
	int i;

	if (isneg == 1)
		i = 2;
	else
		i = 1;
	while (n2 > 9)
	{
		n2 = n2 / 10;
		i++;
	}
	return (i);
}

static void	ft_itoa_filldst(char *dst, int isneg, int i, long n2)
{
	if (isneg == 1)
	{
		while (i > 0)
		{
			dst[i] = (n2 % 10) + '0';
			n2 = n2 / 10;
			i--;
		}
		dst[i] = '-';
	}
	else
	{
		while (i >= 0)
		{
			dst[i] = (n2 % 10) + '0';
			n2 = n2 / 10;
			i--;
		}
	}
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		isneg;
	int		i;
	long	n2;

	n2 = n;
	isneg = 0;
	if (n2 < 0)
	{
		n2 = -n2;
		isneg = 1;
	}
	i = ft_itoa_cntchar(n2, isneg);
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dst[i] = '\0';
	i--;
	ft_itoa_filldst(dst, isneg, i, n2);
	return (dst);
}
