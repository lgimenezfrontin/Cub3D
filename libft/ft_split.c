/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:26:37 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/20 15:21:55 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_split_startstr(char const *s, char c, int *i)
{
	int j;
	int k;

	j = -1;
	k = 0;
	while (j != *i)
	{
		while (s[k] == c)
			k++;
		j++;
		if (j == *i)
			return (k);
		while (s[k] != c)
			k++;
	}
	return (k);
}

static size_t	ft_split_len(char const *s, char c, int *i)
{
	int		j;
	size_t	len;

	j = ft_split_startstr(s, c, i);
	len = 0;
	while (s[j] != c && s[j] != '\0')
	{
		j++;
		len++;
	}
	return (len);
}

static int		ft_split_cntstr(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j] == '\0')
			return (i);
		i++;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (s[j] == '\0')
			return (i);
	}
	return (i);
}

static void		ft_split_cpy(char **dst, char const *s, char c, int *i)
{
	int j;
	int k;

	j = 0;
	k = ft_split_startstr(s, c, i);
	while (s[k] != c && s[k] != '\0')
	{
		dst[*i][j] = s[k];
		j++;
		k++;
	}
	dst[*i][j] = '\0';
	(*i)++;
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;

	if (s == NULL)
		return (NULL);
	if (!(dst = malloc(sizeof(char*) * (ft_split_cntstr(s, c) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_split_cntstr(s, c))
	{
		if (!(dst[i] = malloc(sizeof(char) * (ft_split_len(s, c, &i) + 1))))
		{
			i--;
			while (i >= 0)
			{
				free(dst[i]);
				i--;
			}
			free(dst);
			return (NULL);
		}
		ft_split_cpy(dst, s, c, &i);
	}
	dst[i] = NULL;
	return (dst);
}
