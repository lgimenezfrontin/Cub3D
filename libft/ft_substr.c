/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:44:37 by lgimenez          #+#    #+#             */
/*   Updated: 2019/10/24 17:54:54 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	n;

	n = 0;
	while (s[start] && len)
	{
		n++;
		start++;
		len--;
	}
	return (n);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(dst = malloc(sizeof(char))))
			return (NULL);
		*dst = '\0';
		return (dst);
	}
	if (!(dst = malloc(sizeof(char) * (ft_substr_len(s, start, len) + 1))))
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		dst[i] = s[start];
		i++;
		start++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
