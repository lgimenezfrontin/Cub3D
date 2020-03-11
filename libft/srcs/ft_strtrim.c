/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:10:02 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 15:24:52 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int		ft_strtrim_isset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int		ft_strtrim_lastc(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_strtrim_isset(s1[i], set) == 1 && i > 0)
		i--;
	return (i);
}

static size_t	ft_strtrim_len(char const *s1, char const *set)
{
	size_t	n;
	size_t	result;

	n = 0;
	result = 0;
	while (ft_strtrim_isset(s1[n], set) == 1 && s1[n])
		n++;
	while (n <= (size_t)ft_strtrim_lastc(s1, set) && s1[n])
	{
		n++;
		result++;
	}
	return (result);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_strtrim_len(s1, set) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (ft_strtrim_isset(s1[i], set) == 1)
		i++;
	while (i <= ft_strtrim_lastc(s1, set))
	{
		dst[j] = s1[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
